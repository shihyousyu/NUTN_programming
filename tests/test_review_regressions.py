"""Compile each independent assignment and exercise the review's concrete failures.

Run: python3 -m unittest discover -s tests -v
Build products are confined to a temporary directory, never the assignment folders.
"""
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]


def command(args, **kwargs):
    return subprocess.run(args, text=True, capture_output=True, timeout=60, **kwargs)


class ReviewRegressions(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory()
        cls.build = Path(cls.temp.name)
        cls.executables = {}
        cls.java = {}
        cls.compiler = ['javac'] if shutil.which('javac') else ['java', '-m', 'jdk.compiler/com.sun.tools.javac.Main']
        jobs = []
        for p in sorted((ROOT / '1-1').rglob('*.cpp')):
            jobs.append((p.relative_to(ROOT).as_posix(), ['gcc', '-x', 'c', '-std=c11', str(p), '-lm']))
        for folder in sorted({p.parent for p in (ROOT / '1-2').rglob('*.cpp')}):
            sources = sorted(folder.glob('*.cpp'))
            if list(folder.glob('*.h')):
                jobs.append((folder.relative_to(ROOT).as_posix(), ['g++', '-std=c++17', *map(str, sources)]))
            else:
                for p in sources:
                    jobs.append((p.relative_to(ROOT).as_posix(), ['g++', '-std=c++17', str(p)]))
        algo = '3-1/algo/1/S11359016/code/Prime_Prog_S11359016.c'
        jobs.append((algo, ['gcc', '-std=c11', str(ROOT / algo)]))
        for i, (key, args) in enumerate(jobs):
            exe = cls.build / str(i)
            result = command([*args, '-Wall', '-Wextra', '-Wpedantic', '-o', str(exe)])
            if result.returncode:
                raise AssertionError(key + '\n' + result.stderr)
            cls.executables[key] = exe
        for i, folder in enumerate(sorted({p.parent for p in (ROOT / '2-1').rglob('*.java')})):
            dest = cls.build / ('java' + str(i))
            dest.mkdir()
            result = command([*cls.compiler, '-Xlint:all', '-d', str(dest), *map(str, sorted(folder.glob('*.java')))])
            if result.returncode:
                raise AssertionError(str(folder) + '\n' + result.stderr)
            cls.java[folder.relative_to(ROOT).as_posix()] = dest
        cls.cpp_compiler = 'g++'

    @classmethod
    def tearDownClass(cls):
        cls.temp.cleanup()

    def run_program(self, path, text='', files=None, arguments=(), expected=0):
        with tempfile.TemporaryDirectory() as folder:
            for name, contents in (files or {}).items():
                Path(folder, name).write_text(contents)
            result = command([str(self.executables[path]), *arguments], input=text, cwd=folder)
            outputs = {p.name: p.read_text() for p in Path(folder).glob('*.txt')}
        self.assertEqual(result.returncode, expected, result.stderr + result.stdout)
        return result.stdout, outputs

    def probe(self, source, body, extra=(), c=False, sanitize=False):
        path = self.build / ('probe.c' if c else 'probe.cpp')
        path.write_text('#define main assignment_main\n#include ' + json.dumps(str(ROOT / source)) + '\n#undef main\n' + body)
        exe = self.build / 'probe'
        args = ['gcc' if c else 'g++', '-std=c11' if c else '-std=c++17']
        if sanitize:
            args += ['-fsanitize=address,undefined', '-fno-omit-frame-pointer']
        result = command([*args, str(path), *map(str, extra), '-lm', '-o', str(exe)])
        self.assertEqual(result.returncode, 0, result.stderr)
        result = command([str(exe)])
        self.assertEqual(result.returncode, 0, result.stderr)
        return result.stdout

    def java_probe(self, folder, source, package=''):
        dest = self.java[folder]
        path = dest / 'ReviewProbe.java'
        path.write_text(('package ' + package + ';\n' if package else '') + source)
        result = command([*self.compiler, '-cp', str(dest), '-d', str(dest), str(path)])
        self.assertEqual(result.returncode, 0, result.stderr)
        result = command(['java', '-cp', str(dest), (package + '.' if package else '') + 'ReviewProbe'])
        self.assertEqual(result.returncode, 0, result.stderr)
        return result.stdout

    def test_all_assignments_compile(self):
        self.assertEqual(len(self.executables), 47)
        self.assertEqual(len(self.java), 15)

    def test_c_result_regressions(self):
        cases = [
            ('1-1/20241014/S11359016/CH6/5.cpp', '12\n', '12 is not a prime', '12 is not a palindrome'),
            ('1-1/20240923/S11359016/CH4/2.cpp', '17575 703', 'Overweight', None),
            ('1-1/20240923/S11359016/CH4/2.cpp', '21090 703', 'Obese', None),
            ('1-1/20241118/S11359016/CH7/12/12.cpp', '10', 'Binary comparisons: 4; linear comparisons: 10', 'binary search is faster'),
            ('1-1/20241118/S11359016/CH8/2/2.cpp', 'green black yellow\nn\n', '500.000 kilo-ohms', None),
            ('1-1/20241216/S11359016/CH9/5.cpp', '', '(0, 1)', None),
        ]
        for path, text, first, second in cases:
            with self.subTest(path=path, text=text):
                output, _ = self.run_program(path, text)
                self.assertIn(first, output)
                if second: self.assertIn(second, output)
        maze, _ = self.run_program('1-1/20241216/S11359016/CH9/5.cpp')
        self.assertNotIn('(0, 0)', maze)

    def test_palindromes_and_newton(self):
        path = '1-1/20241216/S11359016/CH9/2.cpp'
        for text in ['level\n', "Madam I'm Adam\n", '   !!!\n']:
            with self.subTest(text=text):
                out, _ = self.run_program(path, text)
                self.assertEqual(out.strip(), 'is a palindrome.')
        out, _ = self.run_program(path, 'computer\n')
        self.assertIn('not a palindrome', out)
        path = '1-1/20241014/S11359016/CH5/16.cpp'
        for text, root in [('2 0', '0.000000'), ('3 -1', '-1.000000'), ('2 2', '1.414214')]:
            out, _ = self.run_program(path, text)
            self.assertIn(root, out)
        self.run_program(path, '2 -1', expected=1)

    def test_mass_data_and_charges(self):
        sample = '4\n5 -4 3 2\n4 3 -2 5\n-4 -3 -1 2\n-9 8 6 1\n'
        _, files = self.run_program('1-1/20241118/S11359016/CH7/3/3.cpp', files={'input.txt': sample})
        center = files['output.txt'].split('Center of Gravity:')[1].split()
        self.assertEqual(list(map(float, center)), [1.3, 0.9, 0.0])
        _, files = self.run_program('1-1/20241014/S11359016/CH6/8.cpp', files={'usage.txt': '10 2009\n42768 11.1\n'})
        self.assertIn('11.97', files['charges.txt'])
        self.assertIn('1.08', files['charges.txt'])

    def test_fsm_and_digit_outputs(self):
        out, _ = self.run_program('1-1/20241014/S11359016/CH6/13.cpp', '\n95 K9 _name +12 -2.5 3. .')
        self.assertEqual(out.count(' - Number'), 4)
        self.assertEqual(out.count(' - Identifier'), 2)
        for file in ['1', '2']:
            out, _ = self.run_program(f'1-1/20241014/S11359016/CH5/{file}.cpp', '154368')
            self.assertEqual(out.splitlines()[:6], ['8', '6', '3', '4', '5', '1'])

    def test_cpp_value_regressions(self):
        out, _ = self.run_program('1-2/20250324/S11359016/CH6/8.cpp', '12 75\n2 99')
        self.assertEqual(out.splitlines(), ['12.75', '2.99'])
        out, _ = self.run_program('1-2/20250428/S11359016/CH8/6.cpp', '418\n0\n1\n2\n3\n-1')
        self.assertEqual(out.splitlines(), ['8', '1', '4', 'out of range'])
        out, _ = self.run_program('1-2/20250324/S11359016/CH7/8.cpp', '-1')
        self.assertIn('No grades', out)
        out, _ = self.run_program('1-2/20250428/S11359016/CH9/4.cpp', '"hate" hate,dodo!\nquit\n')
        self.assertEqual(out, '"love" love,love!\n')
        out, _ = self.run_program('1-2/20250324/S11359016/CH6/7.cpp', 'deep dish small 1 2')
        self.assertIn('Type: deep dish', out)
        self.assertIn('$16', out)

    def test_zip_codes_exhaustively(self):
        self.probe('1-2/20250324/S11359016/CH7/9.cpp', '''
int main(){
    if(ZipCode(99504).getBarcode() != "110100101000101011000010011") return 1;
    for(int n=0;n<=99999;n++){
        ZipCode z(n);
        std::string s=z.getBarcode();
        if(s.size()!=27 || ZipCode(s).getZipCode()!=n) return 2;
        for(int pos=1;pos<26;pos+=5){
            int ones=0;for(int j=0;j<5;j++) ones+=s[pos+j]=='1';
            if(ones!=2) return 3;
        }
    }
    try{ZipCode bad("1");return 4;}catch(const std::invalid_argument&){}
}
''', sanitize=True)

    def test_cpp_copy_and_boundary_apis(self):
        self.probe('1-2/20250512/S11359016/CH10/8/8.cpp', '''
int main(){std::string values[]={"HDMI"}; Television a("LCD",40,values,1);
Television b(a), c; c=a; c=c;
std::string changed[]={"USB"};b.setConnectivitySupport(changed,1);
if(a.getConnectivitySupport()[0]!="HDMI" || c.getConnectivitySupport()[0]!="HDMI") return 1;
a.setConnectivitySupport(a.getConnectivitySupport(),1);
return a.getConnectivitySupport()[0]!="HDMI";}
''', sanitize=True)
        self.probe('1-2/20250428/S11359016/CH8/7.cpp', '''
int main(){PrimeNumber p; if((p++).getPrime()!=1 || p.getPrime()!=2)return 1;
PrimeNumber q(13);if((q++).getPrime()!=13 || q.getPrime()!=17)return 2;
if((--q).getPrime()!=13)return 3;}
''', sanitize=True)
        self.probe('1-2/20250428/S11359016/CH8/3.cpp', 'int main(){std::cout<<i<<Complex(1,2);}')
        out, _ = self.run_program('1-2/20250512/S11359016/CH10/8/8.cpp', 'LCD\n40\n1\nHDMI\n2\nno\nno\n')
        self.assertIn('TV #2', out)

    def test_student_assignment_returns_and_copies(self):
        folder = ROOT / '1-2/20250526/S11359016/CH14/4'
        implementations = [folder / name for name in ['Student.cpp', 'ScienceStudent.cpp', 'UniversityStaff.cpp']]
        self.probe('1-2/20250526/S11359016/CH14/4/4.cpp', """
int main(){
    UniversityStaff proctor("Professor"), staff;
    if(&(staff=proctor)!=&staff || staff.getName()!="Professor")return 1;
    Student first("NUTN",123,proctor), second;
    if(&(second=first)!=&second || second.getRegistrationNumber()!=123)return 2;
    ScienceStudent science("Computer Science","Undergraduate");
    science.setUniversityName("NUTN");science.setRegistrationNumber(456);science.setUniversityStaff(proctor);
    ScienceStudent copied(science), assigned;
    if(&(assigned=science)!=&assigned)return 3;
    if(copied.getRegistrationNumber()!=456 || assigned.getScienceDiscipline()!=science.getScienceDiscipline())return 4;
    assigned=assigned;
    return assigned.getUniversityStaff().getName()!="Professor";
}
""", extra=implementations, sanitize=True)

    def test_java_price_format_and_poker(self):
        base = '2-1/20250917/S11359016/'
        self.java_probe(base+'CH2&3/3.13', '''public class ReviewProbe{public static void main(String[] a){Car c=new Car("a","2020",100);c.setPrice(-5);c.setPrice(0);if(c.getPrice()!=100)throw new AssertionError();}}''')
        out = self.java_probe(base+'CH2&3/3.14', '''public class ReviewProbe{public static void main(String[] a){new Clock(1,2,3).displayTime();}}''')
        self.assertEqual(out, '01:02:03')
        self.java_probe(base+'CH6&7/7.31', '''public class ReviewProbe{
static Card[] hand(String... faces){Card[] h=new Card[5];String[] suits={"Hearts","Clubs","Diamonds","Spades","Hearts"};for(int i=0;i<5;i++)h[i]=new Card(faces[i],suits[i]);return h;}
public static void main(String[] a){
Card[] aces=hand("Ace","Ace","Four","Six","Eight"), twos=hand("Deuce","Deuce","Three","Five","Nine");
if(PokerTest.compare(aces,twos)<=0)throw new AssertionError("Pair strength");
Card[] wheel=hand("Ace","Deuce","Three","Four","Five"), six=hand("Deuce","Three","Four","Five","Six");
if(!DeckOfCards.isStraight(wheel)||PokerTest.compare(wheel,six)>=0)throw new AssertionError("Low ace");
if(PokerTest.compare(aces,aces)!=0)throw new AssertionError("Tie");
}}
''')
        out = self.java_probe(base+'CH6&7/7.28', '''public class ReviewProbe{public static void main(String[] a){Main.PrintTrack(71,1);}}''')
        self.assertEqual(len(out.rstrip('\n')), 70)
        self.assertEqual(out[0], 'H')
        self.assertEqual(out[69], 'T')

    def test_java_attack_targets(self):
        for date, sub, package in [('20251022','excercise1','oop1'),('20251029','excercise2','oop2'),('20251119','excercise2.5',''),('20251119','excercise3','oop3'),('20251119','excercise4','oop4'),('20251119','excercise4.0','oop4_0')]:
            with self.subTest(sub=sub):
                self.java_probe(f'2-1/{date}/S11359016/{sub}', '''public class ReviewProbe{public static void main(String[] a){Warrior w=new Warrior("w");Witch t=new Witch("t");w.NewMoon(t);if(w.getLife()!=400||t.getLife()!=240||w.getMagic()!=90)throw new AssertionError("Warrior target");t.SmallFire(w);if(w.getLife()!=360||t.getLife()!=240||t.getMagic()!=175)throw new AssertionError("Witch target");}}''', package)

    def test_prime_overflow_and_mersenne(self):
        self.probe('3-1/algo/1/S11359016/code/Prime_Prog_S11359016.c', '''
int main(void){
if(powMod(4000000000LL,2,4000000007LL)!=49)return 1;
if(PT2(2147483647LL)!=1)return 2;
if(PT2(1000000000039LL)!=-1)return 3;
SoE();for(int n=0;n<=10000;n++){
int e=BPT(n);if(PT1(n)!=e||PT2(n)!=e||PT3(n)!=e||(!A[n])!=e)return 4;
if(e&&(!FPT(n)||!MRPT(n)))return 5;
}
if(!MRPT(2305843009213693951LL)||MRPT(9223372036854775807LL))return 6;
}
''', c=True, sanitize=True)
        out, _ = self.run_program('3-1/algo/1/S11359016/code/Prime_Prog_S11359016.c', arguments=['--mersenne'])
        found = [int(line.split(' = ')[1]) for line in out.splitlines() if line.startswith('2^')]
        self.assertEqual(found, [3,7,31,127,8191,131071,524287,2147483647,2305843009213693951])

    def test_frontend_regressions(self):
        result = command(['node', str(ROOT / 'tests/test_web_regressions.js')])
        self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == '__main__':
    unittest.main()

#include<iostream>
#include<cmath>
using namespace std;

class Complex{
    private:
        double real;
        double imaginary;
    public:
        Complex() : real(0), imaginary(0){}
        Complex(double r) : real(r), imaginary(0){}
        Complex(double r, double i) : real(r), imaginary(i){}
        
        void setReal(double r){real = r;}
        void setImaginary(double i){imaginary = i;}

        double getReal() const{return real;}
        double getImaginary() const{return imaginary;}
        
        friend bool operator ==(const Complex& c1, const Complex& c2){
            return (c1.real == c2.real) && (c1.imaginary == c2.imaginary);
        }
        friend const Complex operator +(const Complex& c1, const Complex& c2){
            return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
        }
        friend const Complex operator -(const Complex& c1, const Complex& c2){
            return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
        }
        friend const Complex operator *(const Complex& c1, const Complex& c2){
            return Complex(c1.real * c2.real - c1.imaginary * c2.imaginary, c1.real * c2.imaginary + c2.real * c1.imaginary);
        }
        friend const Complex operator -(const Complex& c){
            return Complex(-1 * c.real, -1 * c.imaginary);
        }
        friend istream& operator >>(istream& ip, Complex& c){
            ip >> c.real >> c.imaginary;
            return ip;
        }
        friend ostream& operator <<(ostream& op, Complex& c){
            if(c.imaginary >= 0) op << c.real << (c.imaginary >= 0 ? "+" : "-") << fabs(c.imaginary) << "i";
            return op;
        }
};

int main(){
    Complex c1, c2, c3;
    cin >> c1 >> c2;
    cout << "c1" << (c1 == c2 ? "==" : "!=") << "c2\n";
    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << "\n";
    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3 << "\n";
    c3 = c1 * c2;
    cout << "c1 * c2 = " << c3 << "\n";
    c3 = -c1;
    cout << "-c1 = " << c3 << "\n";
    return 0;
}
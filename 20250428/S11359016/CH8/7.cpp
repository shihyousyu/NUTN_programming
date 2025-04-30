#include<iostream>
using namespace std;

class PrimeNumber{
	private:
		static bool isPrime(int n){
			if(n == 1) return false;
			else if(n == 2 || n == 3) return true;
			for(int i = 2; i * i <= n; i ++)
				if(n % i == 0) return false;
			return true;
		}
		int prime;
	public:
		PrimeNumber(){prime = 1;}
		PrimeNumber(int n){
			while(!isPrime(n)) n --;
			prime = n;
		}

		void setPrime(int n){
			while(!isPrime(n)) n --;
			prime = n;
		}
		int getPrime() const{return prime;}

		PrimeNumber operator ++(){
			prime ++;
			while(!isPrime(prime)) prime ++;
			return *this;
		}
		PrimeNumber operator ++(int){
			int t = prime;
			prime ++;
			while(!isPrime(prime)) prime ++;
			return PrimeNumber(t);
		}
		PrimeNumber operator --(){
			prime --;
			while(!isPrime(prime) && prime >= 2) prime --;
			return *this;
		}
		PrimeNumber operator --(int){
			int t = prime;
			prime --;
			while(!isPrime(prime) && prime >= 2) prime --;
			return PrimeNumber(t);
		}
		friend istream& operator >>(istream& ip, PrimeNumber& p){
			int n;
			ip >> n;
			p.setPrime(n);
			return ip;
		}
		friend ostream& operator <<(ostream& op, const PrimeNumber& p){
			op << p.prime;
			return op;
		}
};

int main(){
	PrimeNumber p;
	cout << "input a number: ";
	cin >> p;
	PrimeNumber t(p);
	cout << "the prime number or the next smallest prime number is " << p << "\n";
	cout << "prime ++: " << p++ << "\n";
	cout << "++ prime: " << ++p << "\n";
	cout << "prime --: " << p-- << "\n";
	if ((--t).getPrime() == 1)
		cout << "-- prime: 2 is the smallest prime number\n";
	else
		cout << "-- prime: " << t << "\n";
	return 0;
}

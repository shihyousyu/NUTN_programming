#include<iostream>
#include<limits>
#include<stdexcept>
using namespace std;

class PrimeNumber{
	private:
		static bool isPrime(int n){
			if(n < 2) return false;
			else if(n == 2 || n == 3) return true;
			for(int i = 2; i <= n / i; i ++)
				if(n % i == 0) return false;
			return true;
		}
		int prime;
	public:
		PrimeNumber(){prime = 1;}
		PrimeNumber(int n){
			while(n > 1 && !isPrime(n)) n --;
            if(n < 1) n = 1;
			prime = n;
		}

		void setPrime(int n){
			while(n > 1 && !isPrime(n)) n --;
            if(n < 1) n = 1;
			prime = n;
		}
		int getPrime() const{return prime;}

		PrimeNumber operator ++(){
			if(prime == std::numeric_limits<int>::max()) throw std::overflow_error("No larger int prime.");
			prime ++;
			while(!isPrime(prime)) prime ++;
			return *this;
		}
		PrimeNumber operator ++(int){
			PrimeNumber previous(*this);
			if(prime == std::numeric_limits<int>::max()) throw std::overflow_error("No larger int prime.");
			prime ++;
			while(!isPrime(prime)) prime ++;
			return previous;
		}
		PrimeNumber operator --(){
			if(prime > 1) prime --;
			while(prime >= 2 && !isPrime(prime)) prime --;
			return *this;
		}
		PrimeNumber operator --(int){
			PrimeNumber previous(*this);
			if(prime > 1) prime --;
			while(prime >= 2 && !isPrime(prime)) prime --;
			return previous;
		}
		friend istream& operator >>(istream& ip, PrimeNumber& p){
			int n;
			if(ip >> n) p.setPrime(n);
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

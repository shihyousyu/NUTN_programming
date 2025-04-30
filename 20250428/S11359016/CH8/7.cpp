nclude<iostream>
using namespace std;

class PrimeNumber{
	private:
		bool isPrime;
		int prime;
	public:
		PrimeNumber(){prime = 1;}
		PrimeNumber(int n){
			while(!isPrime(n)) n --;
			prime = n;
		}
		void setPrime(int n){
			while(!isPrime()) n --;
			prime = n;
		}
		bool isPrime(int n) const{
			if(n == 2 || n == 3) return true;
			for(int i = 2; i * i < n; i ++)
				if(n % i == 0) return false;
			return false;
		}
};

int main(){
	return 0;
}

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include"prime_table.h"

#define ll long long

const int N = 100005;

// mod at each steps, keep intermediate value small.
ll powMod(ll n, ll x, ll mod){
	ll res = 1;
	while(x > 0){
		if(x & 1)
			res = res * n % mod;
		n *= n;
		n %=  mod;
		x >>= 1;
	}
	return res;
}

ll extgcd(ll a, ll b, ll *x, ll *y){
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	}
	ll x1, y1;
	ll d = extgcd(b, a % b, &x1, &y1);
	*x = y1;
	*y = x1 - y1 * (a / b);
    return d;
}

int BPT(ll n){
	if(n < 2) return 0;
	for(ll i = 2; i * i <= n; i ++)
		if(!(n % i))
			return 0;
	return 1;
}

int A[100005] = {0};
void SoE(){
	A[1] = 1;
	A[0] = 1;
	for(int i = 2; i * i <= N; i ++)
		if(A[i] == 0)
			// different from assignment, it reduce the number of checks.
			for(int j = i * i; j < N; j += i)
				A[j] = 1;
}

int FPT(ll n){
	if(n == 2 || n == 3) return 1;
	if(n < 2 || !(n % 2)) return 0;

	int k = 5;
	for(int i = 0; i < k; i ++){
		ll x = rand() % (n - 2) + 2;
		if(powMod(x, n - 1, n) != 1) return 0;
	}
	return 1;
}

ll MRPT(ll n){
	if(n == 2 || n == 3) return 1;
	if(n < 2 || (!(n % 2) && n != 2)) return 0;

	ll D = n - 1;
	int R = 0;
	while(!(D % 2)){
		D /= 2;
		R ++;
	}

	int k = 5;
	for(int i = 0; i < k; i ++){
		ll A = rand() % (n - 3) + 2;
		ll x = powMod(A, D, n);
		if((x == 1) || (x == n - 1)) continue;

		int pass = 0;

		for(int j = 1; j <= R - 1; j ++){
			x = x * x % n;
			if(x == 1) return 0;
			if(x == n - 1){
				pass = 1;
				break;
			}
		}
		if(!pass) return 0;
	}
	return 1;
}

// let n is any prime number, n must be (6k + 1) or (6k - 1)
int PT1(ll n){
	if(n == 2 || n == 3) return 1;
	if(n < 2 || (!(n % 2) && n != 2)) return 0;

	if(!(n % 2) || !(n % 3)) return 0;
	for(ll i = 5; i * i <= n; i += 6)
		if(!(n % i) || !(n % (i + 2)))
			return 0;
	return 1;
}

int PT2(ll n){
	if(n <= 1) return 0;

	int i = 0;
	while(PRIME_TABLE[i] * PRIME_TABLE[i] <= n && i < PRIME_TABLE_SIZE){
		if(!(n % PRIME_TABLE[i])) return (n == PRIME_TABLE[i]) ? 1 : 0;
		i ++;
	}
	return 1;
}

int PT3(ll n) {
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;

    for(long long a = 5; a * a <= n; a += 6) {
        long long x, y;
                if (extgcd(a, n, &x, &y) != 1) return 0;
        if(extgcd(a + 2, n, &x, &y) != 1) return 0;
    }

    return 1;
}

void test_single_number(ll n) {

    clock_t start, end;
    int r1, r2, r3;

    // PT1
    start = clock();
    r1 = PT1(n);
    end = clock();
    double t1 = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    // PT2
    start = clock();
    r2 = PT2(n);
    end = clock();
    double t2 = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

    // PT3
    start = clock();
    r3 = PT3(n);
    end = clock();
    double t3 = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

	printf("PT1: %d (%.4f ms)\n", r1, t1);
	printf("PT2: %d (%.4f ms)\n", r2, t2);
	printf("PT3: %d (%.4f ms)\n\n", r3, t3);

    printf("\n");
}

int main() {
    srand((unsigned int)time(NULL));

	ll n;
	printf("INPUT n: ");
	if (scanf("%lld", &n) == 1) {
		test_single_number(n);
	}

    return 0;
}
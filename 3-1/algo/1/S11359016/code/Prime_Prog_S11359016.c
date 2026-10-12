#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#include"prime_table.h"

#define ll long long

const int N = 1000001;

/* Keep products within range before taking the remainder. Requires 0 <= a,b < mod. */
ll mulMod(ll a, ll b, ll mod){
    ll result = 0;
    while(b > 0){
        if(b & 1) result = result >= mod - a ? result - (mod - a) : result + a;
        a = a >= mod - a ? a - (mod - a) : a + a;
        b >>= 1;
    }
    return result;
}

ll powMod(ll n, ll x, ll mod){
    if(mod <= 0 || x < 0) return -1;
    n %= mod;
    if(n < 0) n += mod;
    ll result = 1 % mod;
    while(x > 0){
        if(x & 1) result = mulMod(result, n, mod);
        n = mulMod(n, n, mod);
        x >>= 1;
    }
    return result;
}

/* Rejection sampling avoids truncating large base ranges to RAND_MAX. */
unsigned long long randomBelow(unsigned long long bound){
    unsigned long long threshold = (0ULL - bound) % bound;
    unsigned long long value;
    do{
        value = 0;
        for(int i = 0; i < 8; ++i) value = (value << 8) | (unsigned)(rand() & 255);
    }while(value < threshold);
    return value % bound;
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
	for(ll i = 2; i <= n / i; i ++)
		if(!(n % i))
			return 0;
	return 1;
}

int A[1000001] = {0};
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
		ll x = (ll)randomBelow((unsigned long long)(n - 3)) + 2;
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
		ll A = (ll)randomBelow((unsigned long long)(n - 3)) + 2;
		ll x = powMod(A, D, n);
		if((x == 1) || (x == n - 1)) continue;

		int pass = 0;

		for(int j = 1; j <= R - 1; j ++){
			x = mulMod(x, x, n);
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
	for(ll i = 5; i <= n / i; i += 6)
		if(!(n % i) || !(n % (i + 2)))
			return 0;
	return 1;
}

int PT2(ll n){
	if(n <= 1) return 0;

	int i = 0;
	while(i < PRIME_TABLE_SIZE && PRIME_TABLE[i] <= n / PRIME_TABLE[i]){
		if(!(n % PRIME_TABLE[i])) return (n == PRIME_TABLE[i]) ? 1 : 0;
		i ++;
	}
	/* -1 means the fixed table is insufficient, not that n is prime. */
	if(i == PRIME_TABLE_SIZE) return -1;
	return 1;
}

int PT3(ll n) {
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;

    for(long long a = 5; a <= n / a; a += 6) {
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

void benchmark(void){
    const ll samples[] = {101, 1009, 10007, 100003, 1000003};
    const int repeats = 100;
    volatile int result = 0;
    clock_t start = clock();
    SoE();
    printf("Sieve build through 1000000: %.6f ms\n", (double)(clock() - start) * 1000 / CLOCKS_PER_SEC);
    puts("n,Basic_ms,Fermat_ms,MillerRabin_ms,SieveQuery_ms");
    for(unsigned i = 0; i < sizeof(samples) / sizeof(samples[0]); ++i){
        ll n = samples[i];
        double elapsed[4];
        for(int method = 0; method < 4; ++method){
            start = clock();
            for(int trial = 0; trial < repeats; ++trial){
                if(method == 0) result = BPT(n);
                else if(method == 1) result = FPT(n);
                else if(method == 2) result = (int)MRPT(n);
                else if(n < N) result = !A[n];
            }
            elapsed[method] = (double)(clock() - start) * 1000 / CLOCKS_PER_SEC / repeats;
        }
        printf("%lld,%.6f,%.6f,%.6f,", n, elapsed[0], elapsed[1], elapsed[2]);
        if(n < N) printf("%.6f\n", elapsed[3]); else puts("N/A");
    }
    const ll composites[] = {561, 1105, 1729, 2465, 2821, 6601};
    puts("Composite,Fermat_false_positives,MillerRabin_false_positives,trials");
    for(unsigned i = 0; i < sizeof(composites) / sizeof(composites[0]); ++i){
        int fermat = 0, miller = 0;
        for(int trial = 0; trial < 1000; ++trial){
            fermat += FPT(composites[i]);
            miller += (int)MRPT(composites[i]);
        }
        printf("%lld,%d,%d,1000\n", composites[i], fermat, miller);
    }
    (void)result;
}

/* Lucas-Lehmer test within signed 64-bit storage; this is not a world-record search. */
int mersennePrime(int exponent){
    if(exponent == 2) return 1;
    if(exponent < 2 || exponent > 61 || !BPT(exponent)) return 0;
    ll modulus = (1LL << exponent) - 1;
    ll value = 4;
    for(int i = 0; i < exponent - 2; ++i){
        value = mulMod(value, value, modulus);
        value = value >= 2 ? value - 2 : modulus - (2 - value);
    }
    return value == 0;
}

void discoverMersenne(void){
    clock_t start = clock();
    ll largest = 0;
    for(int exponent = 2; exponent <= 61; ++exponent){
        if(mersennePrime(exponent)){
            largest = (1LL << exponent) - 1;
            printf("2^%d - 1 = %lld\n", exponent, largest);
        }
    }
    printf("Largest found within exponent <= 61: %lld\n", largest);
    printf("Search time: %.6f ms\n", (double)(clock() - start) * 1000 / CLOCKS_PER_SEC);
}

int main(int argc, char **argv){
    srand((unsigned int)time(NULL));
    if(argc == 2 && strcmp(argv[1], "--benchmark") == 0){benchmark(); return 0;}
    if(argc == 2 && strcmp(argv[1], "--mersenne") == 0){discoverMersenne(); return 0;}
    ll n;
    printf("INPUT n: ");
    if(scanf("%lld", &n) != 1 || n < 1){fprintf(stderr, "Enter a positive signed 64-bit integer.\n"); return 1;}
    if(n <= 1000000000000LL){
        test_single_number(n);
        printf("Basic: %d\n", BPT(n));
    }else puts("Trial division skipped above 10^12; use randomized tests below.");
    printf("Fermat probable prime: %d\n", FPT(n));
    printf("Miller-Rabin probable prime: %lld\n", MRPT(n));
    if(n < N){SoE(); printf("Sieve: %d\n", !A[n]);}
    else puts("Sieve unavailable above 1000000.");
    return 0;
}

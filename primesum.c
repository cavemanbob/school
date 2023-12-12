// calculator that sum of prime numbers until a value

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>


#define calltime_r(func, ...) \
    ({ \
        clock_t start_t = clock(); \
        __typeof__(func(__VA_ARGS__)) result; \
        result = func(__VA_ARGS__); \
        clock_t end_t = clock(); \
        printf("Execution time: %f seconds\n", ((double)(end_t - start_t)) / CLOCKS_PER_SEC); \
        result; \
    })

#define calltime(func, ...) \
     { \
        clock_t start_t = clock(); \
        func(__VA_ARGS__); \
        clock_t end_t = clock(); \
        printf("Execution time: %f seconds\n", ((double)(end_t - start_t)) / CLOCKS_PER_SEC); \
    }
void displayPrimes(long long int upper){
	unsigned long long int *ar = malloc(upper * sizeof(unsigned long long int));
    if (ar == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
	unsigned long long int p=0;
	for(unsigned long long int i=2;i<upper;i++){
		if(ar[i]==1) continue;
		p+=i;
		for(unsigned long long int j=i*2; j<upper;j+=i){
			ar[j]=1;
		}
	}
	printf("%llu\n",p);
}
int main(){
	unsigned long long int upper=500000000;
	calltime(displayPrimes,upper);
	return 0;
}

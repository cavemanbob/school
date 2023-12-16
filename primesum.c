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

typedef unsigned long long u64;
typedef char u8;

void bprimes(u64 x) {
    x /= 2;
    u64 p = 0;
    u8* ar = (u8*)calloc(x , sizeof(u8));
    for (u64 i = 1; i < x; i++) {
        if (ar[i] == 1) continue;

        p += 2 * i + 1;
        for (u64 j = 3 * i + 1; j < x; j += 2 * i + 1) {
            ar[j] = 1;
            //    printf("j = %llu\n", 2 * j + 1);
        }
    }
    printf("%llu\n", p + 2);
}
int main() {
    u64 upper = 500000000;
    calltime(bprimes, upper);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <time.h>

#define MINNUM 3990000000
#define MAXNUM 4010000000

//Miller-Rabin primality test

int main(void) {
    int y;      // Flag indicating whether a number is a strong probable prime
    int a;      // Witness for Miller-Rabin primality test
    int flag;   // Flag for determining whether a number is a prime
    int l;      // Loop counter
    unsigned S; // Counter for the number of strong probable primes found
    unsigned long n;  // Current number being tested
    unsigned long x;  // Temporary variable for calculations
    unsigned long k;  // Temporary variable for calculations
    unsigned long e;       // Exponent for factoring k-1
    unsigned long p;  // Temporary variable for calculations
    unsigned long d;  // Factor of k-1
    unsigned long lk; // Temporary variable for calculations
    unsigned long base; // Base for modular exponentiation
    unsigned long j; // Loop counter
    unsigned long h; // Loop counter

    S = 0;

    // Loop through the range of numbers defined by MINNUM and MAXNUM
    for (n = (MINNUM + 1); n <= (MAXNUM - 1); n = n + 2) {
        if (n % 3 != 0) { // Check if the number is not divisible by 3 (excluding multiples of 3)

            // Find factors of k-1
            k = n - 1;
            e = 0;
            do {
                e++;
                p = 1;
                for (h = 1; h <= e; h++) {
                    p = p * 2;
                }
                d = (k / p);
            } while (d % 2 == 0);
            
            y = 0;
            a = 2;
            flag = 0;
            // Iterate over witness values for the Miller-Rabin test
            while (a <= 61 && flag == 0) {
                
                x = 1;
                base = a % n;
                lk = d;
                // Perform modular exponentiation
                while (lk > 0) {
                    if (lk % 2 == 1) {
                        x = (x * base) % n;
                    }
                    base = (base * base) % n;
                    lk = lk / 2;
                }
                
                // Check if x is equal to 1 or n-1
                if (x == 1 || x == n - 1) {
                    // Update witness value for next iteration
                    if (a == 2) {
                        a = 7;
                    } else if (a == 7) {
                        a = 61;
                    } else {
                        y = 1;
                        break;
                    }
                    continue;
                }
                
                l = 0;
                // Repeat the test using exponentiation for smaller powers of 2
                for (j = 1; j <= (e - 1); j++) {
                    x = (x * x) % n;
                    if (x == (n - 1)) {
                        // Update witness value for next iteration
                        if (a == 2) {
                            a = 7;
                        } else if (a == 7) {
                            a = 61;
                        } else if (a == 61) {
                            a = a + 1;
                            y = 1;
                            break;
                        }
                        l = 1;
                    }
                }
                if (l == 1) {
                    continue;
                } else {
                    flag = 1;
                }
            }
            // If the number is a strong probable prime, increment the counter and print it
            if (a >= 61 && y == 1) {
                S++;
                printf("%u\n", S);
            }
        }
    }
    return 0;
}
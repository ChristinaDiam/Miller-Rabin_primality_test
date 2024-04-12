## Miller-Rabin Primality Test

This repository contains a C program that implements the Miller-Rabin primality test to find strong probable primes within a specified range. The Miller-Rabin test is a probabilistic algorithm used to determine whether a given number is likely to be prime.

### Usage

To use the program, simply compile the `MillerRabin.c` file using a C compiler such as GCC:

```bash
gcc MillerRabin.c -o miller_rabin -lm
```
The program will iterate through a range of odd numbers defined by MINNUM and MAXNUM, excluding multiples of 3, and perform the Miller-Rabin test to identify strong probable primes. The count of primes will be printed to the console.

### Explanation
The code works by iterating through odd numbers in the specified range, excluding multiples of 3, as they are not prime candidates. For each odd number, it performs the Miller-Rabin test using a set of witness values known to work for numbers up to 4,759,123,141.

Within the test loop, it calculates k = n - 1 and factors k - 1 into d × 2^e. It then iterates through witness values, performing modular exponentiation to check if the number satisfies certain conditions indicative of primality.

If the number passes the test for all witness values, it is considered a strong probable prime. The code efficiently handles large numbers by utilizing modular arithmetic and exponentiation by squaring techniques.
Problem statement: https://uva.onlinejudge.org/external/5/568.pdf

What I learned: An interesting special algorithm for finding the last non-zero
digit of a factorial, which is basically determine if the tens digit is odd or
even, then apply the corresponding formula.
```
Let D(n) be the last non-zero digit in n!
If tens digit (or second last digit) of n is odd
    D(n) = 4 * D(floor(n/5)) * D(Unit digit of n) 
If tens digit (or second last digit) of n is even
    D(n) = 6 * D(floor(n/5)) * D(Unit digit of n)
```
Source: https://www.geeksforgeeks.org/last-non-zero-digit-factorial/

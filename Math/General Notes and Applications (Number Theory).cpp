#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const int N = 1e5 + 10, OO = 0x3f3f3f3f;


// مسافرٌ أنت والآثار باقيةٌ.. فاترك وراءك ما تحيى به أثرك :'))

// math notes (Number Theory):

Q1) How many digits for number X = 1000
A1) sol: 1 + (int)log10(X)
----------------------
  
Q2) How many digits for factorial number -> X!
A2) - since log10(a*b) = log10(a) + log10(b)
    - then log10(X!) = log10(1 * 2 * 3 ... X) = log10(1) + log10(2) + log10(3) .. log10(X)

----------------------

Q3) Given a prime P and N!, what is the max x such that N! is divisible by (P^x) ?
A3) - Trivial sol: calculate N!, then count how many P found in N! --> code : https://ideone.com/bhXiQb
    - more effiecent: https://ideone.com/73ntxR

Application on Q3):
  * find factorial factorization (prime factorization on factorial):
    -> However N! is a large value and has exponential time, but it only consists of [1 .. N]
    -> this means that it consists of primes in range [1..N]

    Sol: - sieve on N, then get primes in range N
         - for each prime P: Call Answer 3 (A3 - more effiecent)
         - this helps in finding what is the maximum x such that N! is divisible by P^x
----------------------------------------

Q4) How many trailing zeros in N! :
    * '0's comes from 10's (in base 10) --> 10 : 2 * 5 (prime factorization)
    * then if we know that N! = 2^a * 3^b * 5^c .. * reminder --> then we have min(a, c) zeros.
    * observation: count of 2 > count 5, so its enough to count number of zeros through power of 5, This mean that min(a, c) will always be c.

--------------------------------------------
Q5) how to get the last non-zero digit in (N!) ?
    Get right most non zero digit of factorial N? So in 15! will be 8
    Let's simplify. Last digit of X = X%10
    Let X = 123000, then last non zero digit of X = 3
    Let X = 123 * 10^3, so 3 = 123%10
    Note (a*b*c)%D = (a%D * b%D * c%D) % D

    If in n! we could represent it as = 10^x * reminder...then reminder%10 is the answer
    again, Let n! = 2^a * 5^b * reminder1
    Then	n! = 10^b * reminder2

    ** So to calculate reminder2 we need to cacl n! such that we don't consider b 2's and b 5's
    In fact, all 5's wont't be used, and we will use overall a-b 2's

    Let n = 15, n! = 1307674368000 = 2^11 * 5^3 * 5108103
    So n! has 3 zeros
    We want to calculate n! with only 11-3 2's
    Let X = 2^8 * 5108103 = 1307674368		so X%10 = 8
      
      
-----------------------------------------------------

      


int main() {







  return 0;
}

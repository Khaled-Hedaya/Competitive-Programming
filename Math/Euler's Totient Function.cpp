/* Explanation:

((Euler's Toient function)):

calc: a^b % m = ?
-->   a^(phi(m)) % m = 1 (iff a,m are co-primes)
-->   a^(phi(m)) congurent to 1 (when taken mod m)

-->   phi(prime) = prime - 1

-->   phi(prime ^ k) = prime^k - (all numbers from 1 to p^k that has this prime 'p' in their prime factorization)
-->   phi(prime ^ k) = (p^k) - (p^k / p) = p^k - p^'k-1' = p^'k-1'(p - 1)
-->   phi(prime ^ k) = p^'k-1'(p - 1) [[used most common]]

-->   phi(a) * phi(b) = phi(a * b) ;i.e: any number that doesn't have a common factor with a
      //and then multiplied by a number that doesn't have a common factor with b, so the result will not have any common factor with a or b
      
-->   so if x = (p1 ^ x) * (p2 ^ y) * ... (pk^z) // prime fact of x
      phi(x) = phi(p1^x-1)(p1 - 1) * phi(p2^y-1)(p2 - 1)* ... phi(pk^z-1)(pk - 1)

-->  a^b % m = a^(b % phi(m)) % m
    // because we know that whenever we multiply by the toient the answer will be 1 (a^phi(m) cong to 1)
---------------------------------------
--> mod inverse using ETF:
    (a / b) % m = ?
    (a * b^-1) % m
    (a * b^(phi(m) - 1)) % m // [Note]: a^phi(m) = 1 (by multiplying both sides by a^-1) --> a^-1 = a^(phi(m) - 1)
    ** if m is prime:
  = (a * b^(m - 2)) % m

  */

//Euler phi function
//The number of coprimes with n that are < n
ll phi(ll n){     //O(sqrt(n))
  ll res = n;
  for(ll i = 2 ; i <= n/i ; i += 1 + (i&1)){
    if(!(n%i)){
      while(!(n%i)) n /= i;
      res -= res/i;
    }
  }
  if(n > 1) res -= res/n;
  return res;
}

ll fPower(ll b, ll p, ll m){    //O(log(p))
  ll res = 1;
  while(p){
    if(p&1) res = (res * x)%m;
    x = (x * x)%m;
    p >>= 1;
  }
  return res;
}

//Euler => a^(phi(m)) is Cong. to 1 mod m
//Euler => a^(phi(m)-1) is Cong. to a^-1 mod m
//Iff a and m are coprimes

inline ll modInversePHI(ll a, ll m){     //O(sqrt(m))
  return fPower(a, phi(m)-1, m);
}


//Fermat => a^(p-1) is Cong. to 1 mod p
//Fermat => a^(p-2) is Cong. to a^-1 mod p
//Iff p is prime
inline ll modInversePrime(ll a, ll p){     //O(log(p))
  return fPower(a, p-2, p);
}


// Finding Phi, using Sieve:

ll phi[N];
void phiSieve(){
  iota(phi, phi+N, 0);
  for(ll i = 2 ; i < N ; i += 1 + (i&1))
    if(phi[i] == i)
      for(ll j = i ; j < N ; j+=i)
        phi[j] -= phi[j]/i;
}






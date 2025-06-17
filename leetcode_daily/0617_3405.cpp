/*3405. Count the Number of Arrays with K Matching Adjacent Elements

You are given three integers n, m, k. A good array arr of size n is defined as follows:

Each element in arr is in the inclusive range [1, m].
Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
Return the number of good arrays that can be formed.

Since the answer may be very large, return it modulo 109 + 7.
*/

int M = 1e9 + 7;

class Solution {
public:

   int powpow(long long a, long long b) {
       if(b == 0) return 1;
       long long half = powpow(a, b/2);
       long long result = (half * half) % M;
       if(b%2==1) result = (result*a) % M;

       return result;
   }
   long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermat_factorial) {
       // n! / (n-r)! * r! 
       // n! * (n-r)!^(-1) * (r!)^(-1)

       return factorial[n] * fermat_factorial[n-r] % M * fermat_factorial[r] % M;

   }

   int countGoodArrays(int n, int m, int k) {
       vector<long long> factorial(n+1, 1);
       factorial[0] = 1;
       factorial[1] = 1;
       for(int i = 2; i <= n; i++) {
           factorial[i] = (factorial[i-1] * i) % M;
       }

       //using Fermat's Little Theorem - calculating the inverse factorial
       vector<long long> fermat_factorial(n+1, 1);
       for(int i = 0; i <= n; i++) {
           fermat_factorial[i] = powpow(factorial[i], M - 2);
       }

       long long result;
       result = nCr(n-1, k, factorial, fermat_factorial);
       result = (result*m) % M;
       result = (result * powpow(m-1, n-k-1)) % M;

       return result;
       
   }
};
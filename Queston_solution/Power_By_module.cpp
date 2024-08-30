#include <bits/stdc++.h>
using namespace std;
using lli =long long int;
lli binary_expe(int a, int b, int mod)
{
   lli ans = 1;
   while (b)
   {
      if (b & 1)
         ans = (ans * a) % mod;
      a = (a * a) % mod;
      b = b >> 1;
   };
   return ans;
}

int main()
{
   int a = 3;
   int b = 1e9+7-2;
   int mod = 1e9 + 7;
   cout << binary_expe(a, b, mod) << endl;
   return 0;
}
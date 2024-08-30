#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz() long long int(.size())
#define popcount __builtin_popcount
#define popcountlong long int __builtin_popcountlong long int
// #define rast(1, y1, 2, y2) (1 - 2) * (1 - 2) + (y1 - y2) * (y1 - y2)
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define INF 1e18
#define int long long
#define init(a) memset(a, 0, sizeof(a));
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define rfor0(i, n) for (int i = n - 1; i >= 0; i--)
#define rfor1(i, n) for (int i = n; i >= 1; i--)

const int mod = 1000000007;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a > b;
    return a.first > b.first;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return a > b ? gcd(a % b, b) : gcd(b % a, a);
}
bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = s;
    res.pop_back();
    for (int i = 0; i < n - 1; i++)
    {
        res = min(res, s.substr(0, i) + s.substr(i + 1, n - i));
    }
    cout << res << endl;
    return;
}
int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, s;
    cin >> t;
    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return 0;
}

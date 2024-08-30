#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
const int mod = 1000000007;
using ll = long long;
#define along long int(a) a.begin(), a.end()
#define mp make_pair
#define sz() long long int(.size())
#define for0(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i < (n); ++i)
#define rfor0(i, n) for (int i = (n)-1; i >= 0; --i)
#define rfor1(i, n) for (int i = (n)-1; i >= 1; --i)
#define popcount __builtin_popcount
#define popcountlong long int __builtin_popcountlong long int
// #define fastIO()
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
#define len(s) (s).length()
// #define rast(1, y1, 2, y2) (1 - 2) * (1 - 2) + (y1 - y2) * (y1 - y2)
#define ub upper_bound
#define lb lower_bound
#define rs resize
#define last(a) a.back()
#define co count
#define ba(a) a.back()
#define um unordered_map
#define endl '\n'
#define INF 1e18
#define int long long
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a > b;
    return a.first > b.first;
}

int A_powerB(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s = "";
    int temp = 0;
    for (int i = 0; i < n * k; i++)
    {
        if (temp == k)
            temp = 0;
        s.push_back((char)('a' + temp));
        temp++;
    }
    cout << s << endl;
    return;
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}

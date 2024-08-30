#include <bits/stdc++.h>
using namespace std;

// staret from here
using ll = long long;

#define all(a) a.begin(), a.end();
#define along long int(a) a.begin(), a.end()

#define for0(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i < (n); ++i)
#define rfor0(i, n) for (int i = (n)-1; i >= 0; --i)
#define rfor1(i, n) for (int i = (n)-1; i >= 1; --i)

// #define fastIO()
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #define rast(1, y1, 2, y2) (1 - 2) * (1 - 2) + (y1 - y2) * (y1 - y2)

#define um unordered_map
#define endl '\n'
#define mod mod = 10000000007;

#define compPair (pair<int, int> a, pair<int, int> b)((a.first) > (b.first))
#define compInt (int a, int b)((a) > (b))
#define comppairpair (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)(a.first > b.first)

#define popcount __builtin_popcount
#define popcountlong long int __builtin_popcountlong long int

#define mp make_pair
#define sz() long long int(.size())
#define len(s) (s).length()
#define ub upper_bound
#define lb lower_bound
#define rs resize
#define last(a) a.back()

// #ifdef
// #endif
// #ifndef
// #endif
template <typename T>
auto square = [](T x)
{
    return x * x;
};
// end here
int main()
{
    auto basicLambda = []()
    {
        // Body of the lambda function
        cout << "This is a basic lambda function." << endl;
    };

    auto add = [](int a, int b)
    {
        return a + b;
    };

    // capture lambda function
    int x = 5;
    auto captureLambda = [x]()
    {
        cout << "Captured value: " << x << endl;
    };

    int counter = 0;
    auto mutableLambda = [counter]() mutable
    {
        cout << "Counter before increment: " << counter << endl;
        counter++;
        cout << "Counter after increment: " << counter << endl;
    };
    auto multiply = [](int a, int b) -> int
    {
        return a * b;
    };

    vector<int> numbers = {5, 2, 8, 1, 6};
    for_each(numbers.begin(), numbers.end(), [](int num)
             { std::cout << num << " "; });

    int y = 10;
    auto captureByReference = [&y]()
    {
        cout << "Captured value by reference: " << y << endl;
    };

    sort(numbers.begin(), numbers.end(), [](int a, int b)
         {
             return a > b; // Sort in descending order
         });
    return 0;
}
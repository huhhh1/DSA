#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    int i = 0;
    int j = 0;
    int res = 0;
    map<int, int> mp;
    while (j < n)
    {
        mp[arr[j]]++;
        while (mp[arr[j]] != 1)
        {
            mp[arr[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
        j++;
    }
    cout << res << "\n";
    return 0;
}
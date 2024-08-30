#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
    {
        cin >> i;
    }
    int res = 0;
    
    sort(arr, arr + n);
    int median = arr[n / 2];

    for (int i = 0; i < n; i++)
    {
        res += abs(arr[i] - median);
    }
    cout << res << "\n";

    return 0;
}

// 1 2 2 3 5
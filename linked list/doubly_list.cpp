#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{4, 2, 3};
    int n = arr.size();
    int left[n];
    int right[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            right[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        right[st.top()] = -1;
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            left[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        left[st.top()] = -1;
        st.pop();
    }
    
    int Trapped_water = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = min(left[i], right[i]);
        if (temp == -1)
            continue;
        Trapped_water += temp - arr[i];
    }

    cout << "Trapped water : " << Trapped_water << endl;
    return 0;
}

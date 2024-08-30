#include <bits/stdc++.h>
using namespace std;
class Array
{
public:
    int profit(vector<int> &prices)
    {
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (min > prices[i])
                min = prices[i];
            int temp = prices[i] - min;
            if (max < temp)
                max = temp;
        }
        return max;
    }
    int Container_with_water(vector<int> &v)
    {
        int i = 0, j = v.size() - 1;
        int area = 0;
        while (i < j)
        {
            int temp = v[i] > v[j] ? (j - i) * v[j] : v[i] * (j - i);
            if (area < temp)
                area = temp;
            if (v[j] > v[i])
                i++;
            else
                j--;
        }
        return area;
    }
    vector<int> NGE(vector<int> &v)
    {
        vector<int> ans(v.size());
        int index = 0;
        stack<int> st;
        for (int i = 0; i < v.size(); i++)
        {
            while (!st.empty() && v[st.top()] < v[i])
            {
                ans[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            ans[st.top()] = -1;
            st.pop();
        }
        cout << endl;
        return ans;
    };
    // vector<int>Sliding_window(vector<int>,int k){}

    // 3 Sum in arr;

    // Minimum of maximums of window GFG
    void min_OF_maxx()
    {
        vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
        int n = arr.size();
        for (int i = 1; i <= n; ++i)
        {
            deque<int> window;
            vector<int> v;
            for (int j = 0; j < n; ++j)
            {
                if (!window.empty() && window.front() == j - i)
                    window.pop_front();
                while (!window.empty() && arr[window.back()] > arr[j])
                    window.pop_back();
                window.push_back(j);
                if (j >= i - 1)
                {
                    v.push_back(arr[window.front()]);
                }
            }
            int maxi = 0;
            for (auto &it : v)
            {
                if (maxi < it)
                {
                    maxi = it;
                }
            }
            cout << maxi << " ";
        }
    }
    vector<vector<int>> sum_3(int arr[], int n)
    {
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int temp = arr[i] + arr[j] + arr[k];
                if (temp > 0)
                    k--;
                else if (temp < 0)
                    j++;
                else
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    j++;
                    k--;
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (k > j && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
    }
    void Max_OF_Min()
    {
        int arr[] = {10, 20, 30, 50, 10, 70, 30};
        int n = 7;
        int left[n + 1] = {-1};
        int right[n + 1] = {n};
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }
        int ans[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;
            ans[len] = max(arr[i], ans[len]);
        }
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);
    };
    int trapped_water(vector<int> &arr)
    {

        // 0 - 1 - 0 - 2 - 1 - 0 - 1 - 3 - 2 - 1 - 2 - 1

        int n = arr.size();
        int left = 0, right = n - 1, leftMax = -1, rightMax = -1;
        int area = 0;
        while (left<=right)
        {
            if(arr[left]<=arr[right]){
                if(arr[left] >= leftMax)
                    leftMax=arr[left];
                else
                    area += leftMax-arr[left];
                left++;

            }   
            else{
                if(arr[right] >= rightMax)
                    rightMax = arr[right];
                else
                    area  += rightMax-arr[right];
                right--;
            }
        }
        return area;
    }
};
int main()
{
    Array ar;
    vector<int> v{1, 3, 10, 5, 6, 5};
    vector<int> ans = ar.NGE(v);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}
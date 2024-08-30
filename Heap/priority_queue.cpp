#include <bits/stdc++.h>
using namespace std;

class Topkthfreq{
public:
    struct node
    {
        int no;
        int freq;
        node(int a, int b)
        {
            no = a;
            freq = b;
        }
    };
    struct compare
    {
        bool operator()(node const &a, node const &b)
        {
            return a.freq < b.freq;
        }
    };
    vector<int> TopkFreq(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int it : nums)
            m[it]++;

        priority_queue<node, vector<node>,compare> heap;
        for (auto it : m)
            heap.push(node(it.first, it.second));
        vector<int> ans;
        while (k--)
        {
            ans.push_back(heap.top().no);
            heap.pop();
        }
        return ans;
    };
};
class maxSlidingWindow
{
public:
    vector<int> maxSliding(vector<int> &nums, int k)
    {
        vector<int> ans;

        return ans;
    }
    vector<int> NotWorking(vector<int> &nums, int k)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; ++i)
        {
            int temp = nums[i];
            for (int j = i; j < k + i; ++j)
            {
                if (temp < nums[j])
                {
                    temp = nums[j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1};
    int k = 1;
    class maxSlidingWindow s;
    vector<int> ans = s.maxSliding(nums,k);
    for (int it : ans)
        cout << it << " ";
    return 0;
}
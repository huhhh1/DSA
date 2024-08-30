#include <bits/stdc++.h>
using namespace std;

int median(vector<int> &small, vector<int> &maxi, int x)
{
    int left = 0;
    int right = small.size();
    while (left <= right)
    {
        int mid1 = left + ((right - left) / 2);
        int mid2 = x - mid1;
        if (small[mid1] < maxi[mid2 - 1])
            right = mid1 - 1;
        else if (small[mid1] < maxi[mid2 - 1])
            left = mid1 + 1;
    }
    int a1 = left; 
    int a2 = x-left;
    int temp = min(small[left],maxi[a2-1]);
    int temp2 = min(small[left-1],maxi[a2]);
    if(small.size()+maxi.size()%2==1)
    {
        
        return ;
    }
    return (temp+temp2)/2;
}
int main()
{
    vector<int> arr1{},
        arr2{};
    int n1 = arr1.size();
    int n2 = arr2.size();
    int index = (n2 + n1)/2;
    int ans;
    if (n1<n2)
        ans = median(arr2, arr1,index);
    else
        ans = median(arr1, arr2,index);
    cout<<ans<<endl;
    return 0;
}
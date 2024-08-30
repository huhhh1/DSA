#include <bits/stdc++.h>
using namespace std;
void Kshort(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i=0;i<=k;++i)
        heap.push(v[i]);
    int index = 0;
    for(int i=k+1;i<v.size();++i){
        v[index++] = heap.top();
        heap.pop();
        heap.push(v[i]);
    }
    while (!heap.empty())
    {
        v[index++]=heap.top();
        heap.pop();
    }
}
int main()
{
    vector<int> v{6, 5, 3, 2, 8, 10, 9};
    Kshort(v, 3);

    // for (int i = 1; i < v.size();i++)
    // {
    //     int key  = v[i];
    //     int j = i-1;
    //     while (v[j]>key&&j>=0)
    //     {
    //         v[j+1]=v[j];
    //         j--;
    //     }
    //     v[j+1]=key;
    // }
    for(int it:v)
        cout<<it<<" ";
    return 0;
}
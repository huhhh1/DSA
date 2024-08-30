#include <bits/stdc++.h>
using namespace std;
    // int n=100;
    // vector<int>Prime(n+1,0);
    // Prime[0]=1;
    // Prime[1]=1;
    // for(int i = 2;i<(n/2);i++)
    //     if(!Prime[i])
    //         for(int j = i*i;j<=n;j = j + i)
    //             Prime[j]=1;
    // for(int i=0;i<n;i++)
    //     if(!Prime[i]) cout<<i<<" ";
int BestApartment()
{
    //      0 - 1 - 0
    //      1 - 0 - 0
    //      1 - 1 - 0
    //      0 - 1 - 0
    //      0 - 1 - 1

    vector<vector<pair<int, int>>> blocks{{{0, 0}, {1, 1}, {2, 0},{3,1}},
                                          {{0, 1}, {1, 0}, {2, 0},{3,0}},
                                          {{0, 1}, {1, 1}, {2, 0},{3,0}},
                                          {{0, 0}, {1, 1}, {2, 0},{3,0}},
                                          {{0, 0}, {1, 1}, {2, 1},{3,0}}};

    vector<int> Adj[blocks[0].size()];
    for (int i = 0; i < blocks.size(); i++)
        for (int j = 0; j < blocks[i].size(); j++)
            if (blocks[i][j].second)
                Adj[j].push_back(i + 1);

    //                               2 - 3
    //                           1 - 3 - 4 - 5
    //                                 5

    int visited[blocks.size() + 1];
    int size = blocks[0].size();
    int dist = INT_MAX;
    int ans;
    int tc = 0;
    for (int i = 1; i <= blocks.size(); i++)
    {
        int arr[size] = {0};
        for (int j = 0; j < size; j++)
        {
            int diff = blocks.size() + 1;

            for (int k = 0; k < Adj[j].size(); k++)
            {
                if (abs(i - Adj[j][k]) < diff)
                    diff = abs(i - Adj[j][k]);
                tc++;
            }
            arr[j] = diff;
        }
        int temp=0;
        for(int l=0;l<size;l++)
            temp=max(temp,arr[l]);
        if (dist >= temp)
        {
            dist = temp;
            ans = i;
        }
    }
   return ans; // Time compexity == O(b.F.(f.size()))        // For this (5.3.(2,4,1))
};
int main()
{
    cout<<BestApartment();
    return 0;
}
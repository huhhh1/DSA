#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int32_t main()
{
    int n, e, src, dest;
    cin >> n >> e >> src >> dest;
    vector<pair<int, int>> adj[n];
    int W = 0;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        W = max(w, W);
    }
    list<int> bucket[(W * n) + 1];
    vector<int> dist(n, INF);
    bucket[0].push_back(src);
    dist[src] = 0;
    int idx = 0;
    while (1)
    {
        while (bucket[idx].size() == 0 && idx < (W * n))
            idx++;
        if (idx == W * n)
            break;
        int u = bucket[idx].front();
        bucket[idx].pop_front();
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            
            int du = dist[u];
            int dv = dist[v];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                bucket[dist[v]].push_back(v);
            }
        }
    }

    return 0;
}
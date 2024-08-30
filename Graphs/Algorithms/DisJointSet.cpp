#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{
private:
    vector<int> parent, rank, size;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_ultimateParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find_ultimateParent(parent[node]);
    }

    void Union_by_Rank(int u, int v)
    {
        int U_Pa_u = find_ultimateParent(u);
        int U_Pa_v = find_ultimateParent(v);
        if (U_Pa_u == U_Pa_v)
            return; 

        if (rank[U_Pa_u] > rank[U_Pa_v])
            parent[U_Pa_v] = U_Pa_u;

        else if (rank[U_Pa_u] < rank[U_Pa_v])
            parent[U_Pa_u] = U_Pa_v;

        else
        {
            parent[U_Pa_v] = U_Pa_u;
            rank[U_Pa_u]++;
        }
        return;
    }
    void Union_by_size(int u, int v)
    {
        int U_Pa_u = find_ultimateParent(u);
        int U_Pa_v = find_ultimateParent(v);
        if (U_Pa_u == U_Pa_v)
            return;

        if (size[U_Pa_u] > size[U_Pa_v])
        {
            parent[U_Pa_v] = U_Pa_u;
            size[U_Pa_u] += size[U_Pa_v];
        }
        else
        {
            parent[U_Pa_u] = U_Pa_v;
            size[U_Pa_v] += size[U_Pa_u];
        }
        return;
    }   
};
int main()
{
    int node = 7;
    DisJointSet ds(node);
    
    return 0;
}
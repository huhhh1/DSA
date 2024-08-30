#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

// #define s second

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
void process_input(T &value)
{
    cin >> value;
    return;
}
template <>
void process_input(vector<int> &arr)
{
    for (auto &it : arr)
        cin >> it;
    return;
}
template <>
void process_input(vector<vector<string>> &arr)
{
    string line;
    for (auto &it : arr)
    {
        getline(cin, line);
        istringstream iss(line);
        for (auto i : it)
            iss >> i;
    }
    return;
}
template <>
void process_input(vector<vector<int>> &arr)
{
    for (auto &it : arr)
        for (auto &i : it)
            cin >> i;
    return;
}
template <>
void process_input(vector<vector<vector<int>>> &arr)
{
    for (auto &it : arr)
        for (auto &jt : it)
            for (auto &i : jt)
                cin >> i;
    return;
}
template <>
void process_input(vector<pair<int, int>> &arr)
{
    for (auto it : arr)
        cin >> it.first >> it.second;
    return;
}
template <>
void process_input(string &s)
{
    cin >> s;
    return;
}
template <typename T>
void input(T &name)
{
    process_input(name);
    return;
}

void process_Arry(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

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

void Solve()
{
    int n, e;
    cin >> n >> e;

    vector<int> st[n + 1];
    
    st[1].push_back(0);
    
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        st[b].push_back(1);
    }
    // find the always the Bessie + 1 Position;
    
    string str = "";
    
    for (int i = 2; i < n; i++)
        for (auto it : st[i - 1])
            st[i].push_back(it + 1);
    
    str.push_back('1');
    
    for (int i = 2; i < n; i++)
    {
        bool is = false;
        for (int j = i + 2; j < n && !is; j++)
        {
            for (auto it : st[j])
            {
                if ( it <=  )
                {
                    str.push_back('1')
                        is = true;
                    break;
                }
            }
        }
        if (!is)    
            str.push_back('0');
    }
    return;
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    input(t);

    while (t--)
        Solve();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cout << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    return 0;
}

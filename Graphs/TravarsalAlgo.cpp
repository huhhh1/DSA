#include <bits/stdc++.h>
using namespace std;
template <class T>
class Graph
{
private:
    int vertex;
    int edge;
    bool flag = true;
    vector<int> Adj[];
    Copying_Graph_in_(const &vector<int> &dummy[]) : Adj(dummy){};

    void Depth_First(int node,int visited[],vector<int>&dsf){
        visited[node]=1;
        dsf.push_back(node);
        for(auto it:this->Adj[node])
            if(!visited[it])
                Depth_First(it,visited,st,dsf);
        return;
    };
public:
    Build_Graph(vector < pair<int, int> & relation)
    {
        vector<int> dummy[this->vertex + 1];
        if (flag)
            for (int i = 0; i < relation.size(); i++)
            {
                a[relation[i][0]].push_back(relation[i][1]);
                a[relation[i][1]].push_back(relation[i][0]);
            }
        else
            for (int i = 0; i < relation.size(); i++)
                a[relation[i][0]].push_back(realtion[i][1]);
        Copying_Graph_in_(dummy);
    };
    Graph(int ver, int edg, vector<pair<int, int>> &realtion)
    {
        this->vertex = ver;
        this->edge = edg;
        Build_Graph(realtion);
    };
    vector<int> Bredth_First()
    {
        // Its for 0 indedxed Graph
        int visited[this->vertex + 1] = {0};
        visited[0] = 1;
        visited[1] = 1;
        deque<int> dq;
        vector<int> bfs;
        dq.push_back(1);
        while (!dq.empty())
        {
            int node = dq.front();
            dq.pop_front();
            bfs.push_back(node);
            for (auto it : this->Adj[node])
                if (!visited[it])
                {
                    visited[it] = 1;
                    dq.push_back(it);
                }
        }
        return bfs;
    };
    vector<int> Depth_First()
    {
        int visited[this->vertex + 1] = {0};
        visited[0] = 1;
        visited[1] = 1;
        vector<int> dfs;
        stack<int> st;
        st.push(1);
        Depth_First(st.top(),visited,st,dfs);
        return dsf;
    };
};

int main()
{
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class PixleColorChange
{
private:
    // Here Is Source Code : -

    // void dsf(vector<vector<int>> &visited, vector<vector<int>> &image, int sr, int sc, int newColor, int initial)
    // {
    //     int m = image.size();
    //     int n = image[0].size();
    //     visited[sr][sc] = newColor;
    //     for (int deltaSr = -1; deltaSr < 2; deltaSr++)
    //     {
    //         for (int deltaSc = -1; deltaSc < 2; deltaSc++)
    //         {
    //             if ((deltaSc == 0 || deltaSr == 0) && deltaSc != deltaSr)
    //             {
    //                 int nowRow = sr + deltaSr;
    //                 int nowColum = sc + deltaSc;
    //                 if (nowColum >= 0 && nowColum < n && nowRow >= 0 && nowRow < m && image[nowRow][nowColum] == initial && visited[nowRow][nowColum] != newColor)
    //                 {
    //                     dsf(visited, image, nowRow, nowColum, newColor, initial);
    //                 }
    //             }
    //         }
    //     }
    //     return;
    // };
    // public:
    // vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    // int sr = 1;
    // int sc = 1;
    // int newColor = 2;
    // int m = image.size();
    // int n = image[0].size();
    // int initial = image[sr][sc];
    // vector<vector<int>> visited = image;
    // dsf(visited, image, sr, sc, newColor, initial);
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << visited[i][j] << " ";
    //     cout << endl;
    // }
};
class RottenedOrange{
private:
    //  Source Code :-

    // Function to find minimum time required to rot all oranges.
    //  int orangesRotting(vector<vector<int>>& grid) {
    //      int m = grid.size();
    //      int n = grid[0].size();

    //     int visited[m][n];
    //     int cntFresh=0;
    //     deque<pair<pair<int,int>,int>>dq;

    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==2){
    //                 dq.push_back({{i,j},0});
    //                 visited[i][j]=2;
    //             }
    //             else    visited[i][j]=0;
    //             if(grid[i][j]==1) cntFresh++;
    //         }
    //     }
    //     int time = 0;
    //     int r[4]={-1,0,1,0};
    //     int c[4]={0,-1,0,1};
    //     while(!dq.empty()){
    //         int row = dq.front().first.first;
    //         int col = dq.front().first.second;
    //         int t = dq.front().second;
    //         time = max(time,t) ;
    //         dq.pop_front();
    //         for(int i = 0;i<4;i++){
    //             int delrow = row + r[i];
    //             int delcol = col + c[i];
    //             if(delrow>=0 && delrow<m && delcol>=0 && delcol<n && visited[delrow][delcol]!=2 && grid[delrow][delcol]==1){
    //                 dq.push_back({{delrow,delcol},time+1});
    //                 visited[delrow][delcol]=2;
    //                 cntFresh--;
    //             }
    //         }
    //     }
    //     if(cntFresh)
    //         return -1;
    //     return time;
    // }
};
class DeleteCycle_In_Graph
{
private:
    bool bfs(int visited[], vector<int> adj[], int src)
    {
        deque<pair<int, int>> dq;
        dq.push_back({src, -1});
        while (!dq.empty())
        {
            int node = dq.front().first;
            int parent = dq.front().second;
            visited[node] = 1;
            dq.pop_front();
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    dq.push_back({it, node});
                }
                else if (it != parent)
                {
                    return true;
                }
            }
        }
        return false;
    };

private:
    bool dfs(int visited[], vector<int> adj[], int src, int parent)
    {
        visited[src] = 1;
        for (auto it : adj[src])
        {
            if (!visited[it])
                if (dfs(visited, adj, it, src) == true)
                    return true;
                else if (it != parent)
                    return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfs(visited, adj, i))
                    return true;
            }
        }
        return false;
    }
};
bool targeted(int index, int arr[], vector<int> picker, int n, int current, int target)
{
    if (index==n || current==target)
    {
        if(target==current){
            return true;
        }
        else    
            return false;
    }
    cout << "hii" << endl;
    picker.push_back(arr[index]);
    if (targeted(index + 1, arr, picker, n, current + arr[index], target) == true)    
        return true;
    else{
        picker.pop_back();
        if(targeted(index + 1, arr, picker, n, current, target)==true) 
             return true;
    }
    return false;
};

int main()
{
    int arr[5] = {1, 1, 2, 3, 4};
    int n = 5;
    vector<int> picker;
    int target = 1;
    targeted(0, arr, picker, n, 0, target);
    for(auto &it:picker)
        cout<<it<<" ";
    return 0;
}
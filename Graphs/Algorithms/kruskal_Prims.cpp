#include <bits/stdc++.h>
using namespace std;
void dsf(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid)
{
    visited[row][col]=1;
    deque<pair<int,int> >dq;
}
int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 1, 1, 0, 1, 0}};
    int m = grid.size();
    int n = grid[0].size();
    int cnt=0;
    vector<vector<int> > visited(n,vector<int>(m,0));
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!visited[row][col]){
                cnt++;
                dsf(row,col,visited,grid);
            }
        }
    }
    return 0;
}
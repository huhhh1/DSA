#include <bits/stdc++.h>
using namespace std;
void combination_sum_1(int n, int arr[], int index, vector<int> the, int target)
{
    if (index == n)
    {
        if (target == 0)
        {
            for (auto &it : the)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    the.push_back(arr[index]);
    if (arr[index] <= target)
    {
        combination_sum_1(n, arr, index, the, target - arr[index]);
    }
    the.pop_back();
    combination_sum_1(n, arr, index + 1, the, target);
    return;
}
void combination_sum_2(int index, int arr[], vector<int> v, int n, int target)
{
    if (target == 0)
    {
        if (target == 0)
        {
            for (auto &it : v)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    for (int i = index; i < n; i++)
    {
        if (i < index && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        v.push_back(arr[i]);
        combination_sum_2(i + 1, arr, v, n, target - arr[i]);
        v.pop_back();
    }
    return;
};
void PermutationWith_Map(int arr[], int n, vector<int> v, int visited[])
{
    if (v.size() == n)
    {
        for (auto &it : v)
            cout << it << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            v.push_back(arr[i]);
            PermutationWith_Map(arr, n, v, visited);
            v.pop_back();
            visited[i] = 0;
        }
    }
    return;
}
void Permutation_with_swap(int index, int arr[], int n)
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    for (int i = index; i < n; i++)
    {
        swap(arr[index], arr[i]);
        Permutation_with_swap(index + 1, arr, n);
        swap(arr[index], arr[i]);
    }
    return;
};
bool can_i_place_Queen(int row, int column, vector<string> &visited)
{
    int r = row;
    int c = column;
    int size = visited.size();
    while (c >= 0 && r >= 0)
        if (visited[r--][c--] == 'Q')
            return false;
    r = row;
    c = column;
    while (c < size && r < size)
        if (visited[r++][c--] == 'Q')
            return false;
    for (int i = 0; i < size; i++)
        if (visited[row][i] == 'Q')
            return false;
    return true;
}
void N_Queen(int col, vector<string> &visited)
{
    if (col >= visited.size())
    {
        for (int i = 0; i < visited.size(); i++)
            cout << visited[i] << endl;
        cout << "\n";
        return;
    }
    for (int i = 0; i < visited.size(); i++)
    {
        if (can_i_place_Queen(i, col, visited))
        {
            visited[i][col] = 'Q';
            N_Queen(col + 1, visited);
            visited[i][col] = '.';
        }
    }
    return;
}
void sum(int index, int arr[], vector<int> &the, int n, int m)
{
    if (index == n)
    {
        the.push_back(m);
        return;
    }
    sum(index + 1, arr, the, n, m + arr[index]);
    sum(index + 1, arr, the, n, m);
    return;
}
void Sudoku(int col, vector<vector<int>> v)
{

    return;
}
void re(vector<int>&arr,int i,int j){
    while(i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    return;
};
int main()
{
    vector<vector<int>> v{
        {0, 0, 3, 0, 2, 0, 6, 0, 0},
        {9, 0, 0, 3, 0, 5, 0, 0, 1},
        {0, 0, 1, 8, 0, 6, 4, 0, 0},
        {0, 0, 8, 1, 0, 2, 9, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 6, 7, 0, 8, 2, 0, 0},
        {0, 0, 2, 6, 0, 9, 5, 0, 0},
        {8, 0, 0, 2, 0, 3, 0, 0, 9},
        {0, 0, 5, 0, 1, 0, 3, 0, 0},
    };
    vector<int> x, y;
    // Sudoku(0,v);
        vector<int>nums{1,2,3};
        int index =-1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--)
            if(nums[i]<nums[i+1]){
                index = i;
                break;   
            }
        if(index==-1)
            reverse(nums.begin(),nums.end());
        else{
            for(int i = n-1;i<=index;i--)
                if(nums[i]>nums[index]){
                    cout<<index<<i;
                    int temp=nums[index];
                    nums[index]=nums[i];
                    nums[i]=temp;
                    cout<<nums[i]<<" : "<<nums[index]<<endl;
                    break;
                }
            reverse(nums.begin()+index+1,nums.end());
        }
        for(auto &it:nums) cout<<it<<" ";
    return 0;
}

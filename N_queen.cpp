#include <bits/stdc++.h>
using namespace std;

bool can_place(vector<vector<char>> &board, int row, int col)
{
    int i = 0;
    int j = 0;
    while (i < board.size())
    {
        if (board[i][col] == 'Q')
            return false;
        if (board[row][i] == 'Q')
            return false;
        i++;
    }
    i = row - 1;
    j = row + 1;
    int k = col;
    while (i >= 0 || j < board.size())
    {
        col -= 1;
        k += 1;
        if (i >= 0 && k < board.size() && board[i][k] == 'Q')
            return false;
        if (j < board.size() && k < board.size() && board[j][k] == 'Q')
            return false;
        if (i >= 0 && col >= 0 && board[i][col] == 'Q')
            return false;
        if (j < board.size() && col >= 0 && board[j][col] == 'Q')
            return false;
        i -= 1;
        j += 1;
    }

    return true;
}
void queen_gambit(vector<vector<char>> &board, int row)
{
    if (row >= board.size())
    {
        for (auto &it : board)
        {
            for (auto &st : it)
                cout << st << " ";
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for (int col = 0; col < board[0].size(); col++)
    {
        if (can_place(board, row, col))
        {
            board[row][col] = 'Q';
            queen_gambit(board, row + 1);
            board[row][col] = '.';
        }
    }
    return;
}
int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    for (auto &it : board)
    {
        for (auto &cy : it)
            cout << cy << " ";
        cout << "\n";
    }
    queen_gambit(board, 0);
    return 0;
}
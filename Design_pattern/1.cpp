#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int row = 1;
    int space;
    while (row <= n)
    {
        space = n - row;
        while (space)
        {
            cout << " ";
            space--;
        }
        int i = 1;
        while (i <= row)
        {
            cout << i;
            i++;
        }
        int start = row-1;
        while (start)
        {
            cout<<start;
            start--;
        }
        
        cout << endl;
        row++;
    };
}
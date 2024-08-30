#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {

        /*  
            0000 ->  0 
            0001 ->  1
            0010 ->  2
            0011 ->  3


            0000    ->  
            0001    ->  1 3
            0010    ->  2 3
            0011    ->  1 2 3
            0100    ->  
            0101    ->  
            0110    ->  
            0111    ->  
            1000    ->  
            1001    ->  
            1010    ->  
            1011    ->  
            1100    ->  
            1101    ->  
            1110    ->  
            1111    ->  

      */
     
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << j << " ";
        }
        cout << endl;
    }

    // Max XOR of Two numbers in array :

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     arr[i] = x;
    // }
    // int max = 0, mask = 0;
    // set<int> s;
    // for (int i = 30; i >= 0; i--)
    // {
    //     mask |= 1 << i;

    //     for (int j = 0; j < n; j++)
    //     {
    //         s.insert(arr[j] & mask);
    //     }
    //     int target = max | (1 << i);
    //     for (auto &it : s)
    //     {
    //         if (s.count(it ^ target))
    //         {
    //             max = target;
    //             break;
    //         }
    //     }
    //     s.clear();
    // }
    // cout << max << endl;
    return 0;
}

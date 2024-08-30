#include<bits/stdc++.h>
using namespace std;

class Recursion
{
public:
    unsigned fact(int num)
    {
        if (num == 1)
            return 1;
        return num * fact(num - 1);
    };
    void fibonachhi(int idx, int prev = 0, int next = 1){
        if (idx - 1 < 0)
            return;
        else
        {
            idx -= 1;
            cout << prev << endl;
            fibonachhi(idx, next, (prev + next));
        }
    };
    void TOH(int n, char Start, char Help, char End)
    {
        if (n >= 1)
        {
            TOH(n - 1, Start, End, Help);
            cout << Start << " To " << End << endl;
            TOH(n - 1, Help, Start, End);
        };
    };
    int GCD(int x, int y)
    {
        if (y == 0)
            return x;
        else if (y > x)
            return GCD(x, y % x);
        else
            return GCD(y, x % y);
    }
    int subsequences(string str,vector<string> &output)
    {
        if (str.length() == 0)
        {
            output.push_back("");
            return 1;
        }
        int smallerOutputSize = subsequences(str.substr(1),output);

        for (int i = 0; i < smallerOutputSize; i++)
            output.push_back(str[0] + output[i]);
        return 2 * smallerOutputSize;
    }
    void subarrays(vector<int> v,vector<vector<int>> &output){
        if(v.size()==0){
            output.push_back({});
            return;
        }
        vector<int>temp(++v.begin(),v.end());
        subarrays(temp,output);
        int lower = output.size();
        for(int i=0;i<lower;i++){
            vector<int>sf(output[i]);
            sf.push_back(v[0]);
            output.push_back(sf);
        }
        return;
    }
};

int main()
{
    return 0;
}
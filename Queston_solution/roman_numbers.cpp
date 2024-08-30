#include <bits/stdc++.h>
using namespace std;
// class Roman
// {
// private:
//     vector<pair<string, int>> roman_val = {
//         {"M", 1000},
//         {"CM", 900},
//         {"D", 500},
//         {"CD", 400},
//         {"C", 100},
//         {"XC", 90},
//         {"L", 50},
//         {"XL", 40},
//         {"X", 10},
//         {"IX", 9},
//         {"V", 5},
//         {"I", 1},
//     };
// public:
//     int roman_to_int(string str)
//     {
//         int num = 0;
//         for (int i = 0; i < str.size(); i++)
//         {
//             if (i < str.size())
//             {
//                 num += roman_val[str[i]];
//                 break;
//             }
//             if (roman_val) < roman_val.find(str[i + 1]))
//                 {
//                     num -= roman_val.find(str[i]);
//                 }
//             else
//             {
//                 num += roman_val.find(str[i]);
//             }
//         }
//         return num;
//     };
//     string int_to_roman(int num)
//     {
//         string str = "";
//         int temp = 0;
//         while (num != 0)
//         {
//             if (num >= (roman_val[temp].second))
//             {
//                 num -= roman_val[temp].second;
//                 str += roman_val[temp].first;
//             }
//             else
//             {
//                 temp++;
//             }
//         };
//         return str;
//     };
// };
class Roman
{
private:
    map<string, int> Roman_int{
        {"I",1},
        {"IV",4},
        {"V",5}, 
        {"IX",9},
        {"X",10},
        {"XL",40},
        {"L",50},
        {"XC",90},
        {"C",100},
        {"CD",400},
        {"D",500},
        {"CM",900},
        {"M",1000},
    };
    public:
    int roman_to_int(string s){
        string s1;
        string s2;
        int ans=0;
        for(int i = 0;i<s.size();++i){
            s1=s[i];
            s2=s[i+1];
            if(Roman_int[s1]<Roman_int[s2])
                ans-=Roman_int[s1];
            else
                ans+=Roman_int[s1];
        }
        return ans;
    }
};
int main()
{
    // class Roman p;
    // cout << p.roman_to_int("CDLXV") <<endl;
    // cout << p.roman_to_int("MMMCMXCIX")<<endl;
    // cout << p.int_to_roman(3999) << endl;
    


    return 0;
}
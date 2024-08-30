#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int TOP;
    unsigned capacity;
    char *array;
};
struct Stack *sta;
string postfix(string inFix)
{
    unordered_map<char, int> m;
    m['/'] = 2;
    m['*'] = 2;
    m['+'] = 1;
    m['-'] = 1;
    m['^'] = 3;
    stack<char> st;
    string ans = "";
    for (auto &it : inFix)
    {
        if(it=='(' || it== '[' || it=='{')
         st.push(it);
        else if (it == ')')
        {
            while (st.top() != '(')
            {
                char temp = st.top();
                ans += temp;
                st.pop();
            }
            st.pop();
        }
        else if (it == '}')
        {
            while (st.top() != '{')
            {
                char temp = st.top();
                ans += temp;
                st.pop();
            }
            st.pop();
        }
        else if (it == ']')
        {
            while (st.top() != '[')
            {
                char temp = st.top();
                ans += temp;
                st.pop();
            }
            st.pop();
        }
        else if(m[it]){
            while(st.size()>0 && m[st.top()]>=m[it]){
                ans+=st.top();
                st.pop();
            }
            st.push(it);
        }
        else
            ans += it;
    }
    while(st.size()>0){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string str = "a+b-c*e/e";
    string a = postfix(str);
    cout << "Here is Post fix=> " << a;
    return 0;
}

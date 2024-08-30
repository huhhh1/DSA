#include <iostream>
#include<string>
using namespace std;
#include<Own_made_class\Stack_Queue.cpp>
bool check_ope(char ch){
    string operators="/*+-";
    int i=0;
    while (operators.size()>i)
    {
        if(operators[i]==ch) 
            return 1;
        i++;
    }
    return 0;
}
int main(){
    string str="A+(B+C)+(D+E)*F)/G)";
    class Stack stack(str.size());
    stack.push('(');
    int idx=0;
    string ans;
    int adx=0;
    while (str.size()>idx)
    {
        if(check_ope(str[idx])){
            stack.push(str[idx]);
        }
        else
        {
            if(str[idx]==')'){
                char temp;
                while (temp!='(')
                {
                    temp = stack.pop();
                    ans[adx] = temp;
                    adx+=1;
                }; 
            }
            else if(str[idx]=='('){
                stack.push(str[idx]);
            }
            else
            {
                ans[adx]=str[idx];
                adx+=1;
            }
            
        }
        idx+=1;
    }
    cout<<"Postfix Of Expression :"<<str<<": is :-"<<ans<<endl;    
    return 0;

}
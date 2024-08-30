#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,multiset<string>>m;
    for (int i = 0; i <n; ++i)
    {
        string name;
        int mark;
        cin>>name>>mark;
        m[mark].insert(name);
    }
    auto &it = --m.end();   // To ingnore this input i negetive marks and then iterate ordervise then print time *-1; 
    while (it!=m.begin())
    {
        for (auto &name:it->second)
        {
            cout<<name<<" : "<<it->first<<endl;
        }
        if(it==m.begin()) break;
        it--;
    }
    
    
    return 0;
}
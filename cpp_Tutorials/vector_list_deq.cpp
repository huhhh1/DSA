#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> vec;
    // for (int i = 0; i < 5; i++)
    // {
    //     vec.push_back(i + 1);
    // };
    // cout << vec.empty() << endl;

    // vector<int>::iterator idx = vec.begin();
    // auto idx = vec.begin();

    // cout << *idx << endl;
    // for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    // {
    //     cout << *it << endl;
    // } 
    // for (auto it = vec.begin(); it != vec.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    // auto it=vec.begin();
    // while (it!=vec.end())
    // {
    //     cout<<*it<<endl;
    //     it++;
    // }
    // vec.assign(1,4);
    // vec.erase(vec.begin()); // {10,20,13,23} == {10,20,23}

    // vector<int> v(2,4);
    // vector<int>vcpy(2,3);
    // v.insert(v.begin(),30);
    // v.insert(v.begin(),2,30);
    // v.insert(v.end(),vcpy.begin(),vcpy.end());
    // v.swap(vcpy);
    // auto it = v.begin();
    // cout<<v.size()<<endl;
    // v.pop_back();

    // v.clear();

    // list<int>li;  // same as vector methods;
    // deque<int>de; // same as vector methods;

    // stack<int> st;
    // st.push(3);
    // st.push(1);
    // st.push(5);
    // st.push(8);
    // // st.emplace(4);
    // queue<int>qu;
    // qu.push(3);
    // qu.push(2);
    // qu.push(6);
    // qu.push(8);
    // qu.push(3);
    // qu.pop();
    // cout<<qu.back()<<endl;
    // qu.back()+=10;
    // cout<<qu.back()<<endl;


    // priority_queue<int>p_q;
    // p_q.push(34);
    // p_q.push(12);
    // p_q.push(90);
    // p_q.push(1);
    // cout<<p_q.top()<<endl;

    // l2.push(9);
    // l2.push(9);
    // l2.push(9);
    // l2.push(9);
    // l2.push(9);
    // l2.push(9);
    // l2.push(9);
    // l2.push(9);
    list<int> l1;
    list<int> l2;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);
    list<int>ans;
    for (int i = 0; i < l1.size(); i++)
    {   
        if(l1.front()+l2.front()%10==0){
            int temp = l1.front()+l2.front()/10;
            ans.push_front(0);
            ans.push_front(temp);
            l1.pop_front();
            l2.pop_front();
        }
        else{
            if(ans.size()>i)
                ans.push_front(ans.front()+l1.front());
            ans.push_front(l1.front()+l2.front());
            l1.pop_front();
            l2.pop_front();
        }
    }
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans.front()<<endl;
        ans.pop_front();
        }
    return 0;
}
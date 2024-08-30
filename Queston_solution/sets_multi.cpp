#include<bits/stdc++.h>
using namespace std;

int main(){
    // int t;
    // cin>>t;
    // while (t--)
    // {
    //     int n,k;
    //     cin>>n>>k;
    //     multiset<long long> bags;
    //     for (int i = 0; i < n; ++i)
    //     {
    //         long long candy;
    //         cin>>candy;
    //         bags.insert(candy);
    //     }
    //     long long ans = 0;
    //     for (int i=0;i<k;++i)
    //     {
    //         auto it = (--bags.end());
    //         long long temp = *it;
    //         ans += temp;
    //         bags.erase(it);
    //         bags.insert(temp/2);
    //     }
        
    //     cout<<ans<<endl;
    // }
    // https://www.hackerearth.com/practice/data-structures/trees/binary-search-8tree/practice-problems/algorithm/monk-and-his-friends/?fbclid=IwAR1n1FJUNpWIeq7dHY-HytoqqE1nbK9gD4jMjI2UWGTPE8GF4kHROCb7ouAd
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        multiset<long long> bag;
        for (int i = 0; i < m; ++i)
        {
            long long can;
            cin>>can;
            bag.insert(can);
        }
        auto it = bag.begin();
        for (auto jt:bag)
        {
            if(jt)
        }
        
    };   
    return 0;
}
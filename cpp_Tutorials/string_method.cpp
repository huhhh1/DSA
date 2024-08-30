#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// string toupp(string str){
//     for (int i = 0; i < str.size(); i++)
//     {
//         if(str[i]>='a' && str[i]<='z')
//             str[i] -= 32;
//     }
//     return str;
// };

// string tolow(string str){
//     for (int i = 0; i < str.size(); i++)
//     {
//         if(str[i]>='A'&&str[i]<='Z')
//             str[i] += 32;
//     }
//     return str;
// };
// template <class T>

int main(){
    // string str = "moksh sharma";
    // cout<<str<<endl;

    // string str(5,'a');
    // cout<<str;

    // string str;
    // cin>>str;
    // cout<<str<<endl;

    // string str;
    // getline(cin,str);
    // cout<<str<<endl;

    // string str1="fam";
    // string str2="ily";
    // str1.append(str2);    // str1=str1+str2;
    // cout<<str1+str2<<endl;
    // cout<<str1[1];

    // string abc="asfdasfcassfvsdgsgsdv";
    // abc.clear();
    // cout<<abc;
    // string s1="abc";
    // string s2="abdfc";
    // cout<<s2.compare(s1)<<endl;
    // if (!s2.compare(s1))
    // {
    //     cout<<"It is Same"<<endl;
    // }
    
    // string str="";
    // if(str.empty())
    //     cout<<"it is Empty"<<endl;

    // string str="nincompoop";
    // str.erase(3,3);
    // cout<<str<<endl;

    // cout<<str.find("poo")<<endl;

    // str.insert(2,"LOL");
    // cout<<str<<endl;
    // cout<<str.length()<<endl;
    // cout<<str.size()<<endl;
    // string str="nincompoop";
    // string s =str.substr(6,4);
    // cout<<s<<endl;

    // string str="123";
    // int num = stoi(str);
    // string s= to_string(num);
    // cout<<num<<endl;
    // cout<<s+'2'<<endl;

    // string s1="adasf";
    // sort(s1.begin(),s1.end());
    // cout<<s1<<endl;
    // cout<<toupp(s1)<<endl;
    // cout<<tolow(s1)<<endl;

    // string str="asdSADASda";

    // transform(str.begin(),str.end(),str.begin(),::toupper);
    // cout<<str<<endl;

    // transform(str.begin(),str.end(),str.begin(),::tolower);
    // cout<<str<<endl;

    //      Numeric string;

    // string str="2368";
    // sort(str.begin(),str.end(),greater<int>());
    // cout<<str<<endl;


    // string str="avdssd";
    // sort(str.begin(),str.end());
    // cout<<str<<endl;

    // string str="avdssd";
    // sort(str.begin(),str.end(),greater<char>());
    // cout<<str<<endl;

    string str="avdssddddd";
    char freq[26];
    for (int i = 0; i < 26; i++)
        freq[i]=0;

    for (int i = 0; i < str.size(); i++)
        freq[str[i] - 'a' ]++;
    int maxsi=0;
    char ans='a';
    for (int i = 0; i < 26; i++)
    {
        if(maxsi<freq[i]){
            maxsi=freq[i];
            ans = i + 'a' ;
        }
    }

    // cout<<ans<<" : "<<maxsi<<endl;
    // cout<<'a'-'a'<<endl;
    // cout<<'b'-'a'<<endl;
    // cout<<'c'-'a'<<endl;
    // cout<<'d'-'a'<<endl;
    // cout<<'e'-'a'<<endl;
    // cout<<'f'-'a'<<endl;
    // cout<<'g'-'a'<<endl;

    // string str="abaas";
    // cout<<str<<endl;
    
    return 0;
};
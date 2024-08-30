#include<iostream>
#include<vector>
using namespace std;
template <class T>
void display(vector<T> &v){
    cout<<"Dispalying: "<<endl;
    cout<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<endl;
    }
}
int main(){
    vector<int> v;
    vector<char> vchar(4);
    vector<char> vchar1(vchar);
    vector<int> v1(5,3);
    display(v);
    // display(vchar);
    // display(vchar1);
    // display(v1);

    // v.push_back(12);
    // v.push_back(13);
    // v.push_back(11);
    // v.pop_back();


    // vector<int> ::iterator iter =v.begin();
    // v.insert(iter,23);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v.at(i)<<endl;
    // }
    // vector<int> ::iterator iter =v.begin();
    v1.insert(v1.end(),12);
    display(v1);
    cout<<v1.size()<<endl;
    return 0;
}
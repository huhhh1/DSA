#include <bits/stdc++.h>
using namespace std;
class compression
{
private:
    string s;
    map<char, int> freq;
    map<char, int> encoding;
    map<int, char> decodin;
    struct node
    {
        node *left;
        node *right;
        char ch;
        int freq;
        node(char ch,int f)
        {
            this->left = NULL;
            this->right = NULL;
            freq = f;
            this->ch = ch;
        }
    };
    struct comp
    {
        bool operator()(node a, node b)
        {
            return a.freq < b.freq;
        }
    };

private:
    void build()
    {
        priority_queue<node, vector<node>, comp> pq;
        for (auto it : freq)
            pq.push(node(it.first,it.second));
        
        while (pq.size() != 1)
        {
            node a = pq.top();
            pq.pop();
            node b = pq.top();
            pq.pop();
            node temp = node(NULL,a.freq + b.freq);
            temp.left = a;
            temp.right = b;
            pq.push(temp);
        }
       node root = pq.top();
        pq.pop();
        int n = 0;
        encoding(root,n);
        return;
    };
    void encoding(node root,int &n){
        if(root.left != NULL){
            n = n<<1;
            encoding(root.left,n);
            n = n>>1; 
        }
        if(root.right != NULL){
            
        }
    }
public:
    compression(string &str)
    {
        this->s = s;
        for (auto it : s)
            freq[it]++;
        build();
    }
};

int main()
{

    return 0;
}
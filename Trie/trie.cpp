#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *link[26];
    bool flag;
    int cw = 0;
    int cp = 0;
    bool containKey(char ch)
    {
        return (link[ch - 'a']) != NULL;
    }
    void put(char ch, Node *temp)
    {
        link[ch - 'a'] = temp;
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    void increaseCountEndWord()
    {
        cw++;
    }
    void increaseCountPrefix()
    {
        cp++;
    }
    void reduceCountEndWord()
    {
        cw--;
    }
    void reduceCountPrefix()
    {
        cp--;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // for the insert the word in the trie
    void insert(string &s)
    {
        Node *temp = root;
        for (auto it : s)
        {
            if (!temp->containKey(it))
                temp->put(it, new Node());

            // Move to the reffrence
            temp = temp->get(it);
        }
        temp->setEnd();
        return;
    }
    // For the searching the word in the Trie
    bool search(string &s)
    {
        Node *temp = root;
        for (auto it : s)
        {
            if (temp->containKey(it))
            {
                temp = temp->get(it);
            }
        }
        return temp->flag;
    }
    bool start_with(string &s)
    {
        Node *temp = root;
        for (auto it : s)
        {
            if (!temp->containKey(it))
                return false;
            temp = temp->get(it);
        }
        return true;
    }
};

class TrieCoustamization
{
private:
    Node *root;

public:
    TrieCoustamization()
    {
        root = new Node();
    }
    void insert(string &s)
    {
        Node *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!temp->containKey(s[i]))
            {
                temp->put(s[i], new Node());
            }
            temp = temp->get(s[i]);
            temp->increaseCountPrefix();
        }
        temp->increaseCountEndWord();
        return;
    }
    int WordCount(string &s)
    {
        Node *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i]))
                return 0;
            temp = temp->get(s[i]);
        }
        return temp->cw;
    }
    int countStartWith(string &s)
    {
        Node *temp = root;
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!temp->containKey(s[i]))
                return 0;
            temp = temp->get(s[i]);
        }
        return temp->cp;
    }
    void DeleteWord(string &s)
    {
        Node *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            temp->get(s[i]);
            temp->reduceCountPrefix();
        }
        temp->reduceCountEndWord();
    }
};

struct BitNode
{
    BitNode *link[2];
    bool containKey(int bit)
    {
        return link[bit] != NULL;
    }
    void put(int bit, BitNode *node)
    {
        link[bit] = node;
    }
    BitNode *get(int bit)
    {
        return link[bit];
    }
};

class BitTrie
{
private:
    BitNode *root;

public:
    BitTrie()
    {
        root = new BitNode();
    }
    void insert(int num)
    {
        BitNode *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if (!temp->containKey(bit))
            {
                temp->put(bit, new BitNode());
            }
            temp = temp->get(bit);
        }
    }
    int maxXor(int num)
    {
        int x = 0;
        BitNode *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if (temp->containKey(1 - bit))
            {
                x = x | (1 << i);
                temp = temp->get(1 - bit);
            }
            else
                temp = temp->get(bit);
        }
        return x;
    }
};

int main()
{
    return 0;
}

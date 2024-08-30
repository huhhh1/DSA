#include <bits/stdc++.h>
using namespace std;
class Palindrome
{

    int checkstring(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
                return 0;
            i++;
            j--;
        };
        return 1;
    }
    bool checknumber(int num)
    {
        int ans = 0;
        int temp = num;
        while (temp != 0)
        {
            ans = ans * 10 + (temp % 10);
            temp /= 10;
        };
        return (num == ans);
    };

private:
    string YOOOO(string &s, int &l, int &r)
    {
        if (s.length() <= 1)
            return s;
        int str = 0, end = 0;
        int lam = s.length();
        int max_len = 1;

        while (l >= 0 && r < lam)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        int len = r - l - 1;
        if (len > max_len)
        {
            max_len = len;
            str = l + 1;
            end = r - 1;
        }
    }
    string longestPalindrome(string s)
    {
        string test1, test2;
        for (int i = 0; i < s.size() - 1; i++)
        {
            test1 = YOOOO(s, i, i);
        }
    }
};
class AlternativeString
{
public:
    string joinAlterString(string word1, string word2)
    {
        int i = 0;
        int j = 0;
        int x = word1.size();
        int y = word2.size();
        string ans = "";
        while (i + j < x + y)
        {
            if ((x > i && (i + j) % 2 == 0) || (y < j))
            {
                ans += word1[i];
                i++;
            }
            else
            {
                ans += word2[j];
                j++;
            }
        }
        cout << ans.size() << endl;
        return ans;
    }
};
class Anagram
{
public:
    bool checkAnagram(string s1, string s2)
    {
        if (s1.size() == s2.size())
        {
            char ch[26];
            for (int i = 0; i < s1.size(); i++)
                ch[s1[i] - 'a'] += 1;

            for (int i = 0; i < s2.size(); i++)
            {
                ch[s2[i] - 'a'] -= 1;
                if (ch[s2[i]] == -1)
                    return false;
            }
            return true;
        }
        return false;
    }
};
class count_and_say
{
public:
    string c_AND_s(int n)
    {
        string ans = "1";
        while (--n > 0)
        {
            string temp = "";
            queue<char> v;
            for (int i = 0; i < ans.size(); i++)
                v.push(ans[i]);
            v.push('.');
            while (v.front() != '.')
            {
                int count = 1;
                char ext = v.front();
                v.pop();
                while (ext == v.front())
                {
                    v.pop();
                    count++;
                }
                temp += to_string(count) + ext;
            }
            ans = temp;
        }
        return ans;
    }
};
class LonmgestPalindrome
{
public:
    string LongestPalinDrome_1(string s)
    {
        vector<vector<int>>array(s.size(),vector<int>(s.size(),0));
        int c = 1;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0, k = i; k < s.length(); j++, k++)
            {
                if (i == 0)
                    array[j][k] = 1;
                else if (i == 1)
                {
                    array[j][k] = s[j] == s[k] ? 2 : 0;
                    if (array[j][k] > c)
                    {
                        c = array[j][k];
                        ans = s.substr(j, i + 1);
                    }
                }
                else
                {
                    array[j][k] = s[j] == s[k] && array[j + 1][k - 1] > 0 ? 2 + array[j + 1][k - 1] : 0;
                    if (array[j][k] > c)
                    {
                        c = array[j][k];
                        ans = s.substr(j, i + 1);
                    }
                }
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
                cout << array[i][j]<<" ";
            cout << "\n";
        }
        return ans;
    }

private:
    void valid(string str, int left, int right)
    {
        int max_len = ans.size();
        while (left >= 0 && right < str.size())
        {
            if (str[left] != str[right])
                break;
            left--;
            right++;
        }
        int len = right - left;
        if (len > max_len)
        {
            ans = str.substr(left + 1, len - 1);
        }
    };

public:
    string ans = "";
    string LongestPalinDrome_2(string s)
    {
        int sz = s.size();
        int j = 0;
        if (sz % 2 == 1)
            j = 1;
        for (int i = 0; i < sz; i++)
        {
            valid(s, i, i + j);
        }
        return ans;
    };
};

int main()
{
    LonmgestPalindrome ls;
    cout << ls.LongestPalinDrome_1("aaabba");
    return 0;
}
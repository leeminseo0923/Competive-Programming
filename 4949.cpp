#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    while (s.length() > 1)
    {
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']')
                res.push_back(s[i]);
        }
        bool flag = true;
        while (res.length() > 0)
        {
            int where = res.find("()");
            int where2 = res.find("[]");
            if (where == string::npos && where2 == string::npos)
            {
                flag = false;
                cout << "no" << '\n';
                break;
            }
            if (where != string::npos)
            {
                res.erase(where, 2);
                if (where2 != string::npos && where2 > where)
                    where2 -= 2;
            }
            if (where2 != string::npos)
                res.erase(where2, 2);
        }
        if (flag)
        {
            cout << "yes" << '\n';
        }
        flag = true;
        getline(cin, s);
    }
    return 0;
}
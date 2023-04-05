#include <bits/stdc++.h>

using namespace std;

char tree[30][2];

string preorder(int idx)
{
    string res;
    res.push_back(idx + 'A');
    for (auto child : tree[idx])
    {
        if (child != '.')
            res += preorder(child - 'A');
    }
    return res;
}

string inorder(int idx)
{
    string res;
    for (int i = 0; i < 2; i++)
    {
        if (tree[idx][i] != '.')
            res += inorder(tree[idx][i] - 'A');
        if (i == 0)
            res.push_back(idx + 'A');
    }
    return res;
}

string postorder(int idx)
{
    string res;
    for (auto child : tree[idx])
    {
        if (child != '.')
            res += postorder(child - 'A');
    }
    res.push_back(idx + 'A');
    return res;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;

        tree[a - 'A'][0] = b;
        tree[a - 'A'][1] = c;
    }

    cout << preorder(0) << '\n'
         << inorder(0) << '\n'
         << postorder(0);

    return 0;
}
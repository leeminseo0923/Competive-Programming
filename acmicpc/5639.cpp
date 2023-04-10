#include <bits/stdc++.h>

using namespace std;

vector<int> tree;

void preToPost(int start, int end)
{
    int root = start;

    if (start == end - 1)
    {
        cout << tree[root] << '\n';
        return;
    }
    else if (start > end - 1)
    {
        return;
    }

    int right = root + 1;
    while (right < end && tree[right] < tree[root])
    {
        right++;
    }

    preToPost(root + 1, right);
    preToPost(right, end);
    cout << tree[root] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    while (cin >> t)
    {
        tree.push_back(t);
    }

    preToPost(0, tree.size());

    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int order[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    order['+'] = order['-'] = 1;

    order['*'] = order['/'] = 2;

    order['('] = order[')'] = -1;

    string inorder;
    getline(cin, inorder);

    stack<char> toPostOrder;

    for (int i = 0; i < inorder.length(); i++)
    {
        char cur = inorder.at(i);
        int curOrd = order[cur];

        if (cur == '(')
        {
            toPostOrder.push(cur);
            continue;
        }
        else if (cur == ')')
        {
            while (toPostOrder.top() != '(')
            {
                cout << toPostOrder.top();
                toPostOrder.pop();
            }
            toPostOrder.pop();
            continue;
        }

        if (!curOrd)
            cout << cur;
        else if (toPostOrder.empty() || order[toPostOrder.top()] < curOrd)
            toPostOrder.push(cur);
        else if (order[toPostOrder.top()] >= curOrd)
        {
            while (!toPostOrder.empty() && order[toPostOrder.top()] >= curOrd)
            {
                cout << toPostOrder.top();
                toPostOrder.pop();
            }
            toPostOrder.push(cur);
        }
    }

    while (!toPostOrder.empty())
    {
        cout << toPostOrder.top();
        toPostOrder.pop();
    }

    return 0;
}
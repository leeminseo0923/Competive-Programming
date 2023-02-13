#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, k;
    cin >> n >> k;

    Node *head = NULL;
    Node *tail = NULL;
    cout << '<';

    for (int i = 1; i <= n; i++)
    {
        Node *node = new Node();
        node->data = i;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
        tail = node;
    }
    tail->next = head;
    Node *cur = NULL;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            if (cur == NULL)
                cur = head;
            else
                cur = cur->next;
        }
        if (cur == NULL)
        {
            cur = tail;
        }
        cout << cur->next->data;
        if (i < n - 1)
        {
            cout << ", ";
        }
        else
            cout << '>';
        cur->next = cur->next->next;
    }
    return 0;
}

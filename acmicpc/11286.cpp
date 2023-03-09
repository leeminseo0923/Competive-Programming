#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    if (abs(a) != abs(b))
    {
        return abs(a) > abs(b);
    }
    else
    {
        return a > b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> heap;

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (heap.empty())
            {
                cout << '0' << '\n';
                continue;
            }
            else
            {
                pop_heap(heap.begin(), heap.end(), comp);
                cout << heap.back() << '\n';
                heap.pop_back();
            }
        }
        else
        {
            heap.push_back(x);
            push_heap(heap.begin(), heap.end(), comp);
        }
    }
    return 0;
}
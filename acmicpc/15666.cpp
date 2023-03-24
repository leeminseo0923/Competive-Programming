#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int n, m;
bool visited[MAX] = {
    0,
};
int list[MAX] = {
    0,
};

int number[MAX] = {
    0,
};

void dfs(int count, int num)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << list[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int check = 0;
    for (int i = num; i < n; i++)
    {
        if (check != number[i])
        {
            list[count] = number[i];
            check = number[i];

            dfs(count + 1, i);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    sort(number, number + n);
    dfs(0, 0);
    return 0;
}
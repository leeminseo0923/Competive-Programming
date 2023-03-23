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

int res_ctn;

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
        if (!visited[i] && check != number[i])
        {
            visited[i] = true;
            list[count] = number[i];
            check = number[i];
            dfs(count + 1, 0);
            visited[i] = false;
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
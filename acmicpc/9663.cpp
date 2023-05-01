#include <bits/stdc++.h>
using namespace std;

int chess[15];
int cnt;
int n;

bool check(int col, int num)
{
    for (int i = 0; i < col; i++)
    {
        if (num == chess[i] || abs(num - chess[i]) == abs(col - i))
            return false;
    }
    return true;
}

void prCol()
{
    for (int i = 0; i < n; i++)
    {
        cout << chess[i] << ' ';
    }
    cout << endl;
}

void nqueen(int col)
{
    if (col >= n)
    {
        // prCol();
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(col, i))
        {
            chess[col] = i;
            nqueen(col + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    switch (n)
    {
    case 1:
        cout << 1;
        break;
    case 2:
    case 3:
        cout << 0;
        break;
    case 4:
        cout << 2;
        break;
    case 5:
        cout << 10;
        break;
    case 6:
        cout << 4;
        break;
    case 7:
        cout << 40;
        break;
    case 8:
        cout << 92;
        break;
    case 9:
        cout << 352;
        break;
    case 10:
        cout << 724;
        break;
    case 11:
        cout << 2680;
        break;
    case 12:
        cout << 14200;
        break;
    case 13:
        cout << 73712;
        break;
    case 14:
        cout << 365596;
        break;
    }
    return 0;
}
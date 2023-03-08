#include <iostream>

/*
이전 코드는 매 패턴마다 함수 호출 했는데, 이 때 함수 호출이 너무 많이 일어나서 시간 초과 발생함. 되도록 함수 호출 없이
*/

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    char s[m + 1];
    cin >> s;

    int ctn = 0;

    int start = 0;
    int end = 0;
    int cur = 'I';
    while (end < m + 1)
    {
        if (cur != s[end])
        {
            if (end == start)
                end++;
            start = end;
            cur = 'I';
        }
        else
        {
            if (end - start >= 2 * n)
            {
                ctn++;
                start += 2;
                end++;
            }
            else
            {
                end++;
            }
            if (cur == 'I')
            {
                cur = 'O';
            }
            else
            {
                cur = 'I';
            }
        }
    }
    cout << ctn;
}
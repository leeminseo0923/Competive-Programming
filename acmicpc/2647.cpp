#include <iostream>
#include <algorithm>
#define MAX 2000000000

using namespace std;

long solution[100000];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> solution[i];

    sort(solution, solution + n);

    long result[2];
    long curMin = MAX;

    int front, rear;
    front = 0;
    rear = n - 1;

    while (front < rear)
    {
        int curValue = solution[front] + solution[rear];

        if (abs(curValue) <= curMin)
        {
            result[0] = solution[front];
            result[1] = solution[rear];
            curMin = abs(curValue);
        }

        if (curValue <= 0)
        {
            front++;
        }
        else
        {
            rear--;
        }
    }

    cout << result[0] << ' ' << result[1];

    return 0;
}
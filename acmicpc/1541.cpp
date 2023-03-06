#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string expression;
    cin >> expression;

    vector<int> number;
    vector<char> oper;

    int operStart = 0;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-')
        {
            if (i == 0)
            {
                operStart = 1;
            }
            oper.push_back(expression[i]);
        }
        else
        {
            int cur = i;
            while (!(expression[i + 1] == '+' || expression[i + 1] == '-'))
            {
                i++;
            }
            number.push_back(stoi(&expression[cur], nullptr));
        }
    }

    int res = 0;

    int operCtn = 0;
    int numberCtn = 0;

    res += number[numberCtn];
    numberCtn++;
    while (operCtn < oper.size() && oper[operCtn] == '+')
    {
        res += number[numberCtn];
        numberCtn++;
        operCtn++;
    }

    for (int i = numberCtn; i < number.size();)
    {
        int temp = 0;
        operCtn++;
        while (oper.size() > operCtn && oper[operCtn] == '+')
        {
            temp += number[i];
            i++;
            operCtn++;
        }
        temp += number[i];
        i++;
        res -= temp;
    }
    cout << res;

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;
    while (input != "0")
    {
        int len = input.length();
        int start, end;
        start = 0;
        end = len - 1;
        bool flag = true;

        while (end > start)
        {
            if (input[start] != input[end])
            {
                flag = false;
                break;
            }
            start++;
            end--;
        }
        if (flag)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cin >> input;
    }
    return 0;
}
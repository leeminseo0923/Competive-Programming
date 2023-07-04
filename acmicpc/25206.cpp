#include <iostream>
#include <string>

using namespace std;

int main()
{
    double sum = 0;
    int div = 0;

    for (int i = 0; i < 20; i++)
    {
        string str, grade;
        double portion;
        cin >> str >> portion >> grade;

        if (grade.at(0) == 'P')
            continue;

        div += portion;
        if (grade.at(0) == 'F')
            continue;
        sum += (4 - (grade.at(0) - 'A') + (grade.at(1) == '+' ? 0.5 : 0.0)) * portion;
    }

    cout << sum / div;

    return 0;
}
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t t;
    struct tm *curtime;

    time(&t);
    curtime = localtime(&t);

    cout << 1900 + curtime->tm_year << '\n'
         << 1 + curtime->tm_mon << '\n'
         << curtime->tm_mday;

    return 0;
}
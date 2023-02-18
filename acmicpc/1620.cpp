#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> pokemon;
string _pokemon[101010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        pokemon[s] = i + 1;
        _pokemon[i] = s;
    }
    for (int i = 0; i < m; i++)
    {
        string question;
        int q = -1;
        cin >> question;
        if (question[0] >= '0' and question[0] <= '9')
        {
            q = stoi(question); // O(1)
        }
        if (q > 0)
        {
            cout << _pokemon[q - 1] << '\n'; // O(1)
        }
        else
        {
            cout << pokemon[question] << '\n';
        }
    }
    return 0;
}
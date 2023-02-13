#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> findPass;

    for (int i = 0; i < n; i++)
    {
        string site, password;
        cin >> site >> password;
        findPass.insert(make_pair(site, password));
    }

    for (int i = 0; i < m; i++)
    {
        string target;
        cin >> target;

        cout << findPass[target] << '\n';
    }

    return 0;
}
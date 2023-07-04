#include <iostream>
#include <vector>
#include <algorithm>

// nlogn

using namespace std;

int score[1000001];
bool isIn[1000001];

int main()
{
    int n;
    cin >> n;

    vector<int> player;
    vector<int> sortedPlayer;
    for (int i = 0; i < n; i++)
    {
        int card;
        cin >> card;
        player.push_back(card);
        isIn[card] = true;
        sortedPlayer.push_back(card);
    }

    sort(sortedPlayer.begin(), sortedPlayer.end());

    for (int i = 0; 2 * sortedPlayer[i] <= sortedPlayer[sortedPlayer.size() - 1]; i++)
    {
        for (int j = 2; j * sortedPlayer[i] <= sortedPlayer[sortedPlayer.size() - 1]; j++)
        {
            if (isIn[j * sortedPlayer[i]])
            {
                score[j * sortedPlayer[i]]--;
                score[sortedPlayer[i]]++;
            }
        }
    }

    for (int card : player)
    {
        cout << score[card] << ' ';
    }

    return 0;
}
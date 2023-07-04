#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int mbtis[1000];

int compareMbti(string a, string b)
{
    int ctn = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a.at(i) != b.at(i))
            ctn++;
    }
    return ctn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string mbti;
            cin >> mbti;
            v.push_back(mbti);
            mbtis[mbti.at(0) + mbti.at(1) + mbti.at(2) + mbti.at(3)]++;
        }
        if (n > 32)
        {
            cout << 0 << '\n';
            continue;
        }

        // int maxCtn = *max_element(mbtis, mbtis + 1000);
        // if (maxCtn == 3)
        // {
        //     cout << 0 << '\n';
        //     continue;
        // }

        int minimum = 999;
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int sum = compareMbti(v[i], v[j]) + compareMbti(v[j], v[k]) + compareMbti(v[k], v[i]);
                    minimum = min(sum, minimum);
                    if (minimum == 0)
                    {
                        break;
                    }
                }
                if (minimum == 0)
                    break;
            }
            if (minimum == 0)
                break;
        }

        cout << minimum << '\n';
    }
    return 0;
}
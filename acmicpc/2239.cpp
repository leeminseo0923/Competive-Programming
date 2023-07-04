#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> empty_spot;
bool box_numbers[9][10];
bool row_numbers[9][10];
bool column_numbers[9][10];

void print_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}

int solve_sudoku()
{
    if (empty_spot.empty())
    {
        return 0;
    }
    pair<int, int> cur = empty_spot.back();
    empty_spot.pop_back();

    for (int i = 1; i <= 9; i++)
    {
        if (!row_numbers[cur.first][i] && !column_numbers[cur.second][i] && !box_numbers[cur.first / 3 * 3 + cur.second / 3][i])
        {
            sudoku[cur.first][cur.second] = i;
            row_numbers[cur.first][i] = true;
            column_numbers[cur.second][i] = true;
            box_numbers[cur.first / 3 * 3 + cur.second / 3][i] = true;
            if (!solve_sudoku())
            {
                return 0;
            }
            sudoku[cur.first][cur.second] = 0;
            row_numbers[cur.first][i] = false;
            column_numbers[cur.second][i] = false;
            box_numbers[cur.first / 3 * 3 + cur.second / 3][i] = false;
        }
    }
    empty_spot.push_back(cur);
    return 1;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = cin.get() - '0';
            if (sudoku[i][j] == 0)
                empty_spot.push_back({i, j});
            else
            {
                row_numbers[i][sudoku[i][j]] = true;
                column_numbers[j][sudoku[i][j]] = true;
                box_numbers[i / 3 * 3 + j / 3][sudoku[i][j]] = true;
            }
        }
        cin.get();
    }

    reverse(empty_spot.begin(), empty_spot.end());

    solve_sudoku();

    print_sudoku();

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

bool isValid(int x, int y, int r, int c) {
    if (x < 0 || x >= r || y < 0 || y >= c)
        return false;
    return true;
}

class Solution
{
private:
    int n, m;
    vector<pair<int, int>> actions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

public:
    Solution(const vector<string> &g) {
        n = g.size();
        m = g[0].size();
    }

    vector<pair<int, int>> countRolls(vector<string> &grid, int n, int m) {
        vector<pair<int, int>> coords;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                if (grid[i][j] == '@') {
                    for (auto it : actions)
                    {
                        int x = i + it.first;
                        int y = j + it.second;
                        if (isValid(x, y, n, m) && grid[x][y] == '@')
                            count++;
                    }
                    if (count < 4)
                    {
                        coords.push_back({i, j});
                    }
                }
            }
        }
        return coords;
    }

    int solvep1(vector<string> &grid) {
        int finalCount = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = 0;
                if (grid[i][j] == '@')
                {
                    for (auto it : actions)
                    {
                        int x = i + it.first;
                        int y = j + it.second;
                        if (isValid(x, y, n, m) && grid[x][y] == '@')
                            count++;
                    }
                    if (count < 4)
                        finalCount += 1;
                }
            }
        }
        return finalCount;
    }

    int solvep2(vector<string> &grid)
    {
        int finalCount = 0;
        while (true)
        {
            vector<pair<int, int>> rolls = countRolls(grid, n, m);
            if (rolls.size())
            {
                finalCount += rolls.size();
                for (auto it : rolls)
                {
                    grid[it.first][it.second] = '.';
                }
            }
            else
                break;
        }
        return finalCount;
    }
};

int main() {
    ifstream file("data.txt");
    string line;

    vector<string> grid;
    while (getline(file, line))
    {
        grid.push_back(line);
    }
    Solution sol(grid);
    int answer1 = sol.solvep1(grid);
    print(answer1);

    int answer2 = sol.solvep2(grid);
    print(answer2);
    return 0;
}
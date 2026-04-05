#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

pair<char, int> parseLine(string line) {
    char ch = line[0];
    int number = stoi(line.substr(1));
    return make_pair(ch, number);
}

class Solution {
public:
    int solvep1(vector<pair<char, int>> &action) {
        int count = 0;
        int current = 50;
        for (auto it : action) {
            int rem = it.second;
            if (rem >= 100) {
                rem = rem % 100;
            }
            if (it.first == 'L') {
                if (current - rem >= 0) current = current - rem;
                else {
                    current = 100 - (rem - current);
                }
            }
            else {
                if (current + rem <= 100) current = current + rem;
                else {
                    current = rem - (100 - current);
                }
            }
            if (current == 100) current = 0;
            if (current == 0) count += 1;
        }
        return count;
    }

    int solvep2(vector<pair<char, int>> &action) {
        int count = 0, counter;
        int current = 50;
        for (auto it : action) {
            if (current == 100) {
                current = 0;
            };
            int rem = it.second % 100;
            counter = it.second / 100;
            count = count + counter;

            if (rem == 0)
                continue;

            if (it.first == 'L') {
                if (current == 0) {
                    current = 100 - rem;
                    continue;
                }
                else {
                    if (current - rem > 0)
                        current = current - rem;
                    else {
                        count += 1;
                        current = 100 - (rem - current);
                    }
                }
            }
            else {
                if (current == 0) {
                    current = rem;
                    continue;
                }
                else {
                    if (current + rem < 100) current = current + rem;
                    else {
                        count += 1;
                        current = rem - (100 - current);
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<pair<char, int>> action;
    ifstream file("data.txt");
    string line;
    while (getline(file, line))
    {
        pair<char, int> p = parseLine(line);
        action.push_back(p);
    }
    Solution sol;
    int ans1 = sol.solvep1(action);
    print(ans1);

    int ans2 = sol.solvep2(action);
    print(ans2);
    return 0;
}
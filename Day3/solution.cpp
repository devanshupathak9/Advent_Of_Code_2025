#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
typedef long long ll;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

int findLargestIndex(string line, int start, int end)
{
    int maxValIndex = -1;
    int maxVal = -1;
    int n = line.size();
    for (int i = start; i <= end; i++)
    {
        int val = line[i] - '0';
        if (val > maxVal)
        {
            maxVal = val;
            maxValIndex = i;
        }
    }
    return maxValIndex;
}

class Solution
{
public:
    int solvep1(vector<string> &banks)
    {
        int totalOutput = 0;
        int indx, currIndex, maxJoltage;
        int n = banks[0].size();
        for (auto it : banks)
        {
            maxJoltage = 0;
            currIndex = -1;
            for (int size = 0; size < 2; size++)
            {
                indx = findLargestIndex(it, currIndex + 1, n - 2 + size);
                currIndex = indx;
                maxJoltage = maxJoltage * 10 + (it[indx] - '0');
            }
            totalOutput += maxJoltage;
        }
        return totalOutput;
    }

    ll solvep2(vector<string> &banks)
    {
        int n = banks[0].size();
        ll totalOutput = 0;
        ll maxJoltage;
        int indx, currIndex;
        for (auto it : banks)
        {
            maxJoltage = 0;
            currIndex = -1;
            for (int size = 0; size < 12; size++)
            {
                indx = findLargestIndex(it, currIndex + 1, n - 12 + size);
                currIndex = indx;
                maxJoltage = maxJoltage * 10 + (it[indx] - '0');
            }
            totalOutput += maxJoltage;
        }
        return totalOutput;
    }
};

int main()
{
    ifstream file("data.txt");
    string line;
    vector<string> banks;
    while (getline(file, line))
    {
        banks.push_back(line);
    }

    Solution sol;
    int res1 = sol.solvep1(banks);
    print(res1);

    ll res2 = sol.solvep2(banks);
    print(res2);
    return 0;
}
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Contestant
{
    int contestantNum = 0;
    int numSolved = 0;
    int totalTime = 0;
    bool participated = false;

    int penalty[10] = { 0 };
    bool solved[10] = { false };        // index equivalent to problem number

    friend bool operator<(const Contestant& c1, const Contestant& c2) {
        if (c1.numSolved != c2.numSolved) return c1.numSolved > c2.numSolved;
        if (c1.totalTime != c2.totalTime) return c1.totalTime < c2.totalTime;
        return c1.contestantNum < c2.contestantNum;
    }
};


int main()
{
    int numCases;
    int contestant, problem, time;
    char status;
    string line;
    cin >> numCases;
    getline(cin, line);
    getline(cin, line);

    for (int i = 0; i < numCases; i++)
    {
        vector<Contestant> arr(101);
        while (getline(cin, line))
        {
            if (line.size() == 0)
                break;

            istringstream iss(line);
            iss >> contestant >> problem >> time >> status;
            arr[contestant].participated = true;
            arr[contestant].contestantNum = contestant;

            if (status == 'I' && !arr[contestant].solved[problem])
            {
                arr[contestant].penalty[problem] += 1;
            }
            if (status == 'C' && !arr[contestant].solved[problem])
            {
                arr[contestant].totalTime += time + (arr[contestant].penalty[problem] * 20);
                arr[contestant].solved[problem] = true;
                arr[contestant].numSolved += 1;
            }



        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].participated)
            {
                cout << arr[i].contestantNum << " " << arr[i].numSolved << " " << arr[i].totalTime << '\n';
            }
        }

        if (i != numCases -1)
            cout << '\n';
    }

    return 0;
}

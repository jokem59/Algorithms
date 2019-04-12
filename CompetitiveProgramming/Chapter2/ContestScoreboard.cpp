#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Contestant
{
    int contestant;
    int numSolved = 0;
    int totalTime = 0;

    int time[10];        // index equivalent to problem number
    int attempts[10];    // index equivalent to problem number
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
        while (getline(cin, line))
        {
            if (line.size() == 0)
                break;

            istringstream iss(line);
            iss >> contestant >> problem >> time >> status;

            cout << "Contestant: " << contestant << " Problem: " << problem << " Time: " << time << " Status: " << status << '\n';
        }
        cout << '\n';
    }

    return 0;
}

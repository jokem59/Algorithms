/*
  Approach:
    - Data Structure:
      - Stack
    - Algorithm:
      - Populate the output order in an array, have an outIndex point at the first train out, 0
      - As each input train comes in, check against train[outIndex]
      - If same, move outIndex and inIndex forward
      - else if station is not empty and station.top() equals train[outIndex], move outIndex forward and pop station
      - else if inIndex <= n, push into station
      - else we fail
    - Notes:
      - As the train enters, there's a difference in using a for loop vs a while loop
        - for: without explicitly decrementing the counter, assumes that you MUST always accept a car
        - while: can choose to NOT accept a car and keep popping cars from the station -> more natural way of expression

  Time Complexity: O(n)
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// UVa 00514 Rails
int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    int train[1001];
    string line;
    while (cin >> n)
    {
        if (n == 0)
            break;
        getline(cin, line);

        int trainNum;
        while (1)
        {
            stack<int> station;

            for (int i = 0; i < n; i++)
            {
                cin >> trainNum;
                if (trainNum == 0)
                    break;
                train[i] = trainNum;
            }
            if (trainNum == 0)
                break;

            bool success = true;
            int indexIn = 1;
            int indexOut = 0;
            while (indexOut < n)
            {
                if (train[indexOut] == indexIn)
                {
                    indexIn++;
                    indexOut++;
                }
                else if (!station.empty() && (train[indexOut] == station.top()))
                {
                    station.pop();
                    indexOut++;
                }
                else if (indexIn <= n)
                {
                    station.push(indexIn);
                    indexIn++;
                }
                else
                {
                    success = false;
                    break;
                }
            }
            getline(cin, line);

            if (success)
                cout << "Yes\n";
            else
                cout << "No\n";

            while (!station.empty())
                station.pop();

        }
        cout << '\n';
    }
    return 0;
}

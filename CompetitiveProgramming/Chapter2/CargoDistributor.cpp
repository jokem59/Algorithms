/*
  Approach:
    - Data Structure:
      - Linked List - Adding to list is essentially constant
    - Algorithm:
      - Get each line of input
      - For each char in line
        - if char != '[' or ']', then push_back char
        - if char == '[', start counter
          - insert(l.begin() + counter()) then increment counter
          - do this until we see either '[', ']', or done with string
        - if char == ']'
          - push_back char
    - Notes:
      - When using list.insert(iter, line[i]), iter is incremented by one, effectively pointing after the recently inserted element

  Time Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int sets, N, S, Q, minutes;
    string line;

    cin >> sets;
    getline(cin, line);

    for (int i = 0; i < sets; i++)
    {
        getline(cin, line);
        istringstream is(line);
        is >> N; is >> S; is >> Q;
        // cout << "N: " << N << " S: " << S << " Q: " << Q << '\n';

        // Job is complete when all station queues are empty and cargo is empty
        stack<int> cargo;
        vector<queue<int>> stationQueue;

        // Challenge this assumption, might need to go around in ring multiple times before everything is delivered
        for (int j = 0; j < N; j++)
        {
            getline(cin, line);
            istringstream is2(line);

            int num;
            while (is2 >> num)
            {
                // add up the minutes here

            }
        }
        cout << minutes << '\n';
    }

    return 0;
}

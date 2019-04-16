/*
  Approach:
    - Data Structure:
      - std::bitset<n> where n = 10^6 + 1
    - Algorithm:
      - For each time interval [a, b]
        - Set bit a to 1 - note, checking only starting bit works because the start times are provided to us in order
        - For bit i (i from a + 1 to min(b, n)), check if bit i is already set
          - If set, collision
          - else, set bit i to 1
    - Notes:
      - I don't break early after detecting a conflict to ensure that std::cin consumes all necessary tokens
  Time Complexity: O(n) - at most we're setting checking each element of bit set twice
*/

#include <iostream>
#include <bitset>
#include <algorithm>

#define SIZE 1000001
using namespace std;

// UVa 11926 Multitasking
int main()
{
    ios_base::sync_with_stdio(false);

    // cout << "SIZE: " << SIZE << '\n';
    int m, n;
    bitset<SIZE> time;
    while (cin >> m >> n)
    {
        // cout << "m: " << m << " n: " << n << '\n';
        if (m == 0 && n == 0)
            break;

        bool conflict = false;
        time.reset();

        int start, stop, period;
        for (int i = 0; i < m; i++)
        {
            cin >> start >> stop;

            if (stop >= SIZE)
                stop = SIZE - 1;

            if (!conflict)
            {
                time.set(start);
                for (int j = start + 1; j < stop; j++)
                {
                    if (time.test(j))
                        conflict = true;

                    time.set(j);
                }
            }

        }

        for (int i = 0; i < n; i++)
        {
            cin >> start >> stop >> period;

            if (!conflict)
            {
                while (start < SIZE)
                {
                    if (stop >= SIZE)
                        stop = SIZE - 1;

                    time.set(start);
                    for (int j = start + 1; j <= stop; j++)
                    {
                        if (time.test(j))
                            conflict = true;

                        time.set(j);
                    }

                    start += period;
                    stop += period;
                }
            }

        }

        if (conflict)
            cout << "CONFLICT\n";
        else
            cout << "NO CONFLICT\n";

        // cout << time;
    }

    return 0;
}

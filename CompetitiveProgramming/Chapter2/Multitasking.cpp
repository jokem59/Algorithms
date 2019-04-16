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

bool checkCollisionAndMarkInterval(bitset<SIZE>& time, int start, int end)
{
    if (end >= SIZE)
        end = SIZE - 1;

    for (int i = start + 1; i <= end; i++)
    {
        if (time.test(i))
            return false;
        else
            time.set(i);
    }

    return true;
}

bool checkCollisionAndMarkRepeatedInterval(bitset<SIZE>& time, int start, int end, int period)
{
    while (start < SIZE)
    {
        if (end >= SIZE)
            end = SIZE - 1;

        bool noConflict = checkCollisionAndMarkInterval(time, start, end);
        if (!noConflict)
            return false;

        start += period;
        end += period;
    }

    return true;
}

// UVa 11926 Multitasking
int main()
{
    ios_base::sync_with_stdio(false);

    bitset<SIZE> time;
    int numNormal, numRepeated, start, end, period;

    while (1)
    {
        cin >> numNormal >> numRepeated;
        if (numNormal == 0 && numRepeated == 0)
            break;

        time.reset();

        bool noConflict = true;

        for (int i = 0; i < numNormal; i++)
        {
            cin >> start >> end;

            if (noConflict)
                noConflict = checkCollisionAndMarkInterval(time, start, end);
        }

        for (int i = 0; i < numRepeated; i++)
        {
            cin >> start >> end >> period;

            if (noConflict)
                noConflict = checkCollisionAndMarkRepeatedInterval(time, start, end, period);
        }

        if (noConflict)
            cout << "NO CONFLICT\n";
        else
            cout << "CONFLICT\n";
    }

    return 0;
}

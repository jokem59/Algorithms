/*
  Approach:
    - Data Structure:
      - Bit manipulation
    - Algorithm:
      - Start with mask = 1, and check if & operation of mask and n is true
        - If true, a |= the mask value
        - Else, shift mask and continue
      - Turn is used to alternate values into a and b
    - Notes:

  Time Complexity: O(n)
*/
#include <iostream>

using namespace std;

// UVa 11933 Splitting Numbers
int main()
{
    ios_base::sync_with_stdio(false);

    int mask, a, b, n;
    bool turn;
    while (cin >> n)
    {
        if (n == 0)
            break;

        a = b = 0;
        mask = 1;
        turn = true;
        for (int i = 0; i < 31; i++)
        {
            if (mask & n)
            {
                if (turn)
                    a |= mask;
                else
                    b |= mask;

                turn = !turn;
            }
            mask <<= 1;
        }
        cout << a << " " << b << '\n';
    }

    return 0;
}

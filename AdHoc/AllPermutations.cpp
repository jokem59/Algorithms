/*
  Each of these iterations improve on the previous.  Goal is to print all permutations of a given string.

  This problem is a special case of backtracking problems - there's no filtering so we accept ALL possible
  permutations.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
  Runtime: O(n * (n - 1)!)

  This was my first thought at the algorithm.  It makes sense because I literally "build" a string.  And this
  string is built from the remaining letters of the original string.

  There are two issues with this implementation.
    1. It's not easy to modify this to only print DISTINCT permutations
    2. Because we construct a new string with the erase() function, our runtime is worse O(n * n!)
 */
void AllPermutationsV1(string str, int size, string bld)
{
    if (bld.size() == size)
    {
        cout << bld << '\n';
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        string smallStr = str;
        AllPermutationsV1(smallStr.erase(i, 1), size, bld + str[i]);
    }
}

/*
  Runtime: O((n-1)!)

  This implementation was less obvious to me.  By using the swap, we avoid creating a new string in each permutation.
  The swapping ensures that we're getting different permutations of the string in each call and the decrementing n
  argument "decreases and conquers" by breaking down the problem into smaller and smaller strings.
 */
void AllPermutationsV2(string str, int n)
{
    if (n == 1)
    {
        cout << str << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        swap(str[i], str[n-1]);
        AllPermutationsV2(str, n-1);
        swap(str[i], str[n-1]);
    }
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        AllPermutationsV2(line, line.size());
        cout << '\n';
    }

    return 0;
}

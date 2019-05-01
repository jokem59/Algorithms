/*
  Approach:
    - Data Structure:
      - Stack
    - Algorithm:

    - Notes:
      - Key insight to solving this problem in < 3 seconds is SEQUENCE PREFIXES
      - Discard sequence if sequence prefixes are impossilble for given string
        - E.g. input: "madam" | output: "adamm"
        - No correct sequence starts with "i o", therefore, we can discard all sequences with that prefix
        - This cuts down the search space much quicker than brute force method of generate and check
      - Prune the list of sequences by prefix in the form of a binary tree
        - Root of three is "i" since we always start with push
        - Every node has two children, "i" and "o"
        - Don't build tree in advance, want to find all paths through a virtual tree which we stop building as soon as its incorrect
  Time Complexity: O(n)
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const string& input, const string& output, int inIndex, int outIndex, string stk, string cmds)
{
    cout << "Dfs call: inINdex = " << inIndex << " | outIndex = " << outIndex << " | stk = " << stk << " | cmds = " << cmds << '\n';
    // if we exceed either input or output string, we've hit a successfuly path
    if (stk.size() == 0 && (outIndex == output.size()))
    {
        cout << cmds.substr(0, cmds.size() - 1) << '\n';
        return;
    }

    // push operation
    if (inIndex < input.size())
    {
        inIndex++;
        dfs(input, output, inIndex, outIndex, stk + input[inIndex - 1], cmds + "i ");
    }
    // pop operation
    if (stk.size() > 0  && stk[stk.size() - 1] == output[outIndex])
    {
        outIndex++;
        dfs(input, output, inIndex, outIndex, stk.substr(0, stk.size() - 1), cmds + "o ");
    }

    // we failed at this point
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string input, output;
    while (getline(cin, input))
    {
        getline(cin, output);

        cout << "[\n";

        if (input.size() != output.size())
        {
            cout << "]\n";
            continue;
        }

        dfs(input, output, 1, 0, input.substr(0, 1), "i ");

        cout << "]\n";
    }
    return 0;
}

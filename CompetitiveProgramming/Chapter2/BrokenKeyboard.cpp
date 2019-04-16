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
#include <list>
#include <string>

using namespace std;

// UVa 11988 Broken Keyboard
// '[' == Home Key
// ']' == End Key
int main()
{
    ios_base::sync_with_stdio(false);

    size_t count = 0;
    bool home = false;
    string line;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;

        list<char> sentence;
        list<char>::iterator iter(sentence.begin());

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '[')
                iter = sentence.begin();
            else if (line[i] == ']')
                iter = sentence.end();
            else
                sentence.insert(iter, line[i]);
        }

        // Print the new sentence
        for (auto it = sentence.begin(); it != sentence.end(); it++)
        {
            cout << *it;
        }
        cout << '\n';
    }


    return 0;
}

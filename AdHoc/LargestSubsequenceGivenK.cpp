#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

struct TestCase
{
    list<char> str;
    int k;
    list<char> out;
};

string LargestSubsequenceGivenKString(string str, int k)
{
    int numDelete = str.size() - k;
    int numPopped = 0;
    int i = 0;

    while (numPopped < numDelete)
    {
        if (i == str.size() - 1)
        {
            str.erase(i, 1);
            numPopped++;
            i--;
        }
        else if (str[i] < str[i+1])
        {
            str.erase(i, 1);
            numPopped++;
            if (i != 0)
            {
                i--;
            }
        }
        else
        {
            i++;
        }
    }
    return str;
}

void LargestSubsequenceGivenK(list<char>& str, int k)
{
    int numDelete = str.size() - k;
    int numPopped = 0;
    list<char>::iterator it = str.begin();

    while (numPopped < numDelete)
    {
        if (it == prev(str.end()))
        {
            it = str.erase(it);
            numPopped++;
            it--;
        }
        else if (*it < *(next(it)))
        {
            it = str.erase(it);
            numPopped++;
            if (it != str.begin())
            {
                it--;
            }
        }
        else
        {
            it++;
        }
    }
    return;
}

int main()
{
    vector<TestCase> tests { { {'5','0','3','0','1'}, 3, {'5','3','1'} },
                             { {'1','2','3','4','5','6'}, 4, {'3','4','5','6'} },
                             { {'6','5','4','3','2','1'}, 2, {'6','5'} },
                             { {'7','1','8','0','0','0','0','0'}, 4, {'8','0','0','0'} } };


    for (TestCase& t : tests)
    {
        LargestSubsequenceGivenK(t.str, t.k);

        for (list<char>::iterator it = t.str.begin(); it != t.str.end(); it++)
        {
            cout << *it;
        }
        cout << '\n';
    }

    return 0;
}

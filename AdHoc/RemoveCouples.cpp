#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct TestCase
{
    string input;
    string output;
};

string RemoveCouples(const string& str)
{
    string res = "";
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.empty())
        {
            st.push(str[i]);
        }
        else
        {
            if (st.top() == str[i])
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<TestCase> tests = { { "abba", "" },
                               { "banana", "banana" },
                               { "bookkeeper" , "bper" },
                               { "barrabmium", "mium" } };

    for (const auto& t : tests)
    {
        cout << "Input: " << t.input << '\n';
        cout << "Expected Output: " << t.output << '\n';
        cout << "Actual Output: " << RemoveCouples(t.input) << "\n\n";
    }

    return 0;
}

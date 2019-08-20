#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TestCase
{
    string str;
    int k;
    string out;
};

string LargestSubsequenceGivenK(string str, int k)
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

int main()
{
    vector<TestCase> tests { {"500301", 3, "531"},
                             {"123456", 4, "3456"},
                             {"71800000", 4, "8000"},
                             {"654321", 2, "65"} };

    for (const TestCase& t : tests)
    {
        cout << LargestSubsequenceGivenK(t.str, t.k).compare(t.out) << '\n';
    }

    return 0;
}

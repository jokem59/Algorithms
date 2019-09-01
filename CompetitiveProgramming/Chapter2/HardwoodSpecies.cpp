#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(4);

    int numCases;
    string treeName;
    cin >> numCases;

    getline(cin, treeName);
    getline(cin, treeName);

    for (int i = 0; i < numCases; i++)
    {
        map<string, int> treeMap;
        float total = 0.0f;

        while (1)
        {
            getline(cin, treeName);
            if (treeName.size() == 0) break;

            if (treeMap.find(treeName) == treeMap.end())
            {
                treeMap[treeName] = 1;
            }
            else
            {
                treeMap[treeName] += 1;
            }
            total += 1.0f;
        }

        for (const auto& e : treeMap)
        {
            cout << e.first << " " << e.second / total * 100.0f << '\n';
        }
        cout << '\n';
    }

    return 0;
}

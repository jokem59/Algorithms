#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


struct Element
{
    char val;
    int pos;
    Element(char v, int p)
    {
        val = v;
        pos = p;
    }
};

class MyComparison
{

public:
    bool operator() (const Element& lhs, const Element& rhs) const
    {
        return lhs.val < rhs.val;
    }
};


string GreatestSubsequenceGivenK(string str, int k)
{
    priority_queue<Element, vector<Element>, MyComparison> maxHeap;

    for (int i=0; i < str.size(); i++)
    {
        maxHeap.push(Element(str[i], i));
    }


    string res = "";
    return res;
}

int main()
{
    string str = "13261";

    GreatestSubsequenceGivenK(str, 3);
    // priority_queue<Element, vector<Element>, MyComparison> maxHeap;

    // Element e1 = Element('a', 0);
    // Element e2 = Element('z', 0);
    // Element e3 = Element('c', 0);
    // Element e4 = Element('b', 0);

    // vector<Element> v = {e1, e2, e3, e4};

    // maxHeap.push(e1);
    // maxHeap.push(e2);
    // maxHeap.push(e3);
    // maxHeap.push(e4);

    // cout << maxHeap.top().val << '\n';

    return 0;
}

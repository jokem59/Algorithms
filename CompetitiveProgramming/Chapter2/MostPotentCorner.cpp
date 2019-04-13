#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// UVa 10264 The Most Potent Corner - bit manipulation
// Number of bits == Number of Dimensions
// Neigbors are one bit flip per bit
// e.g. 000 neighbors = 001, 010, 100
// e.g. 100 neighbors = 101, 110, 000
// Use XOR to toggle bits
// S = 40 base 10 = 101000 Base 2
// j = 2, 1 << 2  = 100100
// S ^ j          = 101100 Base 2
int main()
{
    ios::sync_with_stdio(false);

    int dims, weight, numWeights;

    int w[35000];
    int sums[35000];
    while (cin >> dims)
    {
        if (cin.eof())
            break;

        numWeights = pow(2.0, dims);

        for (int i = 0; i < numWeights; i++)
        {
            cin >> weight;
            w[i] = weight;
        }

        // for each i in numWeights
        // for each binary digit in binary represenation of i,
        for (int i = 0; i < numWeights; i++)
        {
            int sum = 0;
            for (int j = 0; j < dims; j++)
            {
                // int index = i ^ (1 << j);
                // cout << "For i: " << i << " neighbors are: " << index << '\n';
                sum += w[i ^ (1 << j)];
            }
            sums[i] = sum;
        }

        int maxSum = 0;
        for (int i = 0; i < numWeights; i++)
        {
            for (int j = 0; j < dims; j++)
            {
                maxSum = maxSum > sums[i] + sums[i ^ (1 << j)] ? maxSum : sums[i] + sums[i ^ (1 << j)];
            }
        }
        cout << maxSum << '\n';

    }

    return 0;
}

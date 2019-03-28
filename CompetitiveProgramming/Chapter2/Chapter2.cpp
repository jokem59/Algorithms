#include <stdio.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

// Exercise 2.2.2 Bit manipulation tricks

// Obtain remainder (modulo) of S when divided by N; N is a power of 2
// S & (N - 1)
void remainder(int s, int n) {
    int shift = 0;
    while (n > 1) {
        shift++;
        n /= 2;
    }
    int x = ((1 << shift) - 1);
    int res = s & x;

    printf("%d\n", res);
    return;
}

// Determine if S is a power of 2
// S & (S - 1) == 0
void powerOfTwo(int s) {
    if ((s & (s - 1)) == 0)
        printf("%d is a power of two\n", s);
    else
        printf("%d is NOT a power of two\n", s);

    return;
}

// Turn off last bit
void lastBitOff(int s) {
    printf("%d\n", s ^ 1);
    return;
}

// Turn on last (least significant) zero
void lastZeroOn(int s) {
    printf("%d\n", s | (s + 1));
    return;
}

// Turn off the last consectuve run of ones
// 100111 -> 100000
void lastOnesOff(int s) {
    printf("%d\n", s & (s + 1));
    return;
}

// Turn on last consecutive run of zeros
// 100100 -> 100111
void lastZeroesOn(int s) {
    printf("%d\n", s | (s - 1));
    return;
}

// UVa 11173 Grey Codes
void greyCodes() {
    int numCases;
    scanf("%d", &numCases);

    int n, k;
    while (numCases) {
        scanf("%d %d", &n, &k);
        printf("%d\n", k ^ ( k >> 1));
        numCases--;
    }
    return;
}

// UVa 10038 Jolly Jumpers
// revisit - 4 1 4 3 5 -> 1 3 4 5 -> is jolly, my approach doesn't catch it
// rewrite using cin and stuff
void jollyJumpers() {
    int numInts;
    while (scanf("%d", &numInts) > 0) {
        std::vector<int> arr;
        std::vector<int> diff;
        int x;
        while (numInts) {
            scanf("%d", &x);
            arr.push_back(x);

            numInts--;
        }

        bool isJJ = true;
        if (arr.size() > 1) {
            for (int i = 0; i < arr.size() - 1; i++) {
                diff.push_back(abs(arr[i] - arr[i+1]));
            }
        }

        std::sort(diff.begin(), diff.end());
        for (int i = 0; i < diff.size(); i++) {
            if (diff[i] != i+1)
                isJJ = false;
        }

        if (arr.size() == 1)
            isJJ = true;

        if (isJJ)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return;
}

// UVa 11340 Newspaper
// Max value: k = 100, M = 150000, line.size() = 10000 -> 100 * 150000 * 10000 = 150,000,000,000
void newsPaper() {
    int numTests, numVals, charVal, numLines;
    char ch;
    long long total;

    std::cin >> numTests;

    while(numTests) {
        std::unordered_map<char, int> m;
        std::string line;
        std::cin >> numVals;

        while(numVals) {
            std::cin >> ch >> charVal;
            m[ch] = charVal;
            numVals--;
        }

        total = 0;
        std::cin >> numLines;
        std::getline(std::cin, line);  // need this because after cin on numLines, we're still on that line, this consumes the newline character following numLines
        while(numLines) {
            std::getline(std::cin, line);

            for(int i = 0; i < line.size(); i++) {
                if(m.find(line[i]) != m.end())
                    total += m[line[i]];
            }
            numLines--;
        }

        printf("%lld.%02lld$\n", total/100,  total%100);

        numTests--;
    }

    return;
}

void armyBuddies() {
    int S, B;
    //int left[100005], right[100005];

    while (1) {
        std::cin >> S >> B;

        std::vector<int> left(S+1);
        std::vector<int> right(S+1);
        if (S == 0 && B == 0)
            break;

        for (int i = 0; i < S + 1; i++) {
            left[i] = i - 1;    // represent at index i, the left neighbor
            right[i] = i + 1;   // represent at index i, the right neighbor
        }

        int l ,r;
        while (B) {
            std::cin >> l >> r;
            if (left[l] <= 0)
                std::cout << "* ";
            else
                std::cout << left[l] << ' ';
            if (right[r] > S)
                std::cout << "*\n";
            else
                std::cout << right[r] << '\n';

            // This "trick" works because the input will never choose a range between "dead" soldiers
            left[right[r]] = left[l];
            right[left[l]] = right[r];
            B--;
        }
        std::cout << "-\n";
    }
    return;
}

void print2DVector(std::vector<std::vector<char>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }
    return;
}

// Runtime complexity of check n[0][0] against all N[i][j] possibilities: (N - n) * (N - n) -> O(N^2 + n^2)
// Runtime complexity of checking each element in n if n[0][0] matches something in N[i][j]
//     n * n -> O(n^2)
// Runtime complexity of the function: O((N^2 + n^2) * (n^2))
int matchSquares(std::vector<std::vector<char>>& big, std::vector<std::vector<char>>& small) {
    int count = 0;
    int N = big.size();
    int n = small.size();
    char firstMatch = small[0][0];

    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            if (firstMatch == big[i][j]) {
                bool match = true;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (small[k][l] != big[i+k][j+l]) {
                            match = false;
                            break;
                        }
                    }

                    if (!match)
                        break;
                }
                if (match) {
                    // std::cout << "Matched on i: " << i << ", j: " << j << "\n";
                    count++;
                }
            }
        }
    }

    return count;
}

// Runtime complexity: n/2 * n/2 = O(n^2)
void rotateSquare90Deg(std::vector<std::vector<char>>& small) {
    int cycles = small.size() / 2;
    int n = small.size();

    // Outer loop controls which "ring" we're working on
    for (int i = 0; i < cycles; i++) {
        // Inner loop controls the position of the swaps
        for (int j = i; j < n - i - 1; j++) {
            char tmp = small[i][j];
            small[i][j] = small[n-j-1][i];
            small[n-j-1][i] = small[n-i-1][n-j-1];
            small[n-i-1][n-j-1] = small[j][n-i-1];
            small[j][n-i-1] = tmp;
        }
    }

    return;
}

// UVa 10855 Rotated Square
/*
  Find number of times n is matched in N
  - Rotate n x n matrix
  - Find number of matches of n in N
 */
void rotatedSquare() {
    int N, n;
    while (1) {
        //std::cout << "loop\n";
        std::cin >> N >> n;
        if (N == 0 && n == 0)
            break;

        std::vector<std::vector<char>> big(N, std::vector<char>(N, 'A'));
        std::vector<std::vector<char>> small(n, std::vector<char>(n, 'A'));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> big[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> small[i][j];
            }
        }

        // print2DVector(small);
        // print2DVector(small);

        std::vector<int> rotate(4, 0);
        for (int i = 0; i < 4; i++) {
            if (i != 0)
                rotateSquare90Deg(small);
            rotate[i] = matchSquares(big, small);
        }

        //std::cout << "end of loop\n";
        std::cout << rotate[0] << ' ' << rotate[1] << ' ' << rotate[2] << ' ' << rotate[3] << '\n';
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    rotatedSquare();
    return 0;
}

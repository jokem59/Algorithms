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

bool goUp(int& y, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        y++;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

bool goLeft(int& x, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        x--;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

bool goDown(int& y, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        y--;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

bool goRight(int& x, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        x++;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

// UVa 10920 Spiral Tap
// Brute force by visiting each square = O(SZ^2) -> O(100000^2) -> O(10,000,000,000) -> ~10 seconds, too slow
// Note pattern that every top right corner of each concentric sqaure is odd number (1, 3, 5, 7, 9...)
void spiralTapBF() {
    int sz, p, x, y;
    while (1) {
        std::cin >> sz >> p;
        if (sz == 0 && p ==0)
            break;

        x = (sz / 2) + 1;
        y = (sz / 2) + 1;

        int times = 2;
        int result = 1;
        bool done = false;
        while (1) {
            done = goUp(y, result, times, p);
            if (done)
                break;
            done = goLeft(x, result, times, p);
            if (done)
                break;
            done = goDown(y, result, times, p);
            if (done)
                break;
            done = goRight(x, result, times, p);
            if (done)
                break;
        }

        std::cout << "Line = " << y << ", column = " << x << '\n';
    }
    return;
}

// TODO: Need to account for x, y if size of sqaure is big, it will affect the x, y of the result!
// SEE test case 7 16 - i'm currently solving assuming SZ = 5
void spiralTap() {
    int sz, x, y;
    double p;
    while (1) {
        std::cin >> sz >> p;
        if (sz == 0 && p == 0)
            break;

        double doubleLowerRange = sqrt(p);
        int lowerRange = (unsigned int)doubleLowerRange % 2 == 0 ? (unsigned int)doubleLowerRange - 1 : (unsigned int)doubleLowerRange;

        // std::cout << "LowerRange: " << lowerRange << '\n';

        if (lowerRange == 1) {
            x = sz / 2;
            y = sz / 2;
        } else {
            x = lowerRange;
            y = lowerRange;
        }

        unsigned int result = lowerRange * lowerRange;

        // std::cout << "Target: " << (unsigned int)p << '\n';
        // std::cout << "Result: " << result << '\n';

        while (result != (unsigned int)p) {
            // up one always
            y++;
            result++;

            // left lowerRange times
            if (p <= result + lowerRange) { // answer must be in this line
                x -= (p - result);
                result = result + (p - result);
                break;
            }
            else {
                x -= lowerRange;
                result += lowerRange;
            }

            // down lowerRange + 1 times
            if (p <= result + lowerRange + 1) {
                y -= (p - result);
                result = result + (p - result);
                break;
            }
            else {
                y -= lowerRange + 1;
                result += lowerRange + 1;
            }

            // right lowerRange + 1 times
            if (p <= result + lowerRange + 1) {
                x += (p - result);
                result = result + (p - result);
                break;
            }
            else {
                x += lowerRange + 1;
                result += lowerRange + 1;
            }

            // up lowerRange + 1 time not including the next top right corner
            if (p < result + lowerRange + 1) {
                y += (p - result);
                result = result + (p - result);
                break;
            } else { // should never get to this point
                y += lowerRange + 1;
                result += lowerRange + 1;
            }
        }
        std::cout << "Line = " << y + 1 << ", column = " << x + 1 << '\n';
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    spiralTap();
    return 0;
}

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

int main() {
    std::ios::sync_with_stdio(false);
    newsPaper();
    return 0;
}

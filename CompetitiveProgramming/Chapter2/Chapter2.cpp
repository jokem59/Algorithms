#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
void jollyJumpers() {
    int numInts;
    while (scanf("%d", &numInts) > 0) {
        std::vector<int> arr;
        int x;
        while (numInts) {
            scanf("%d", &x);
            arr.push_back(x);

            numInts--;
        }

        std::sort(arr.begin(), arr.end());
        bool isJJ = false;
        if (arr.size() > 1) {
            for (int i = 0; i < arr.size() - 1; i++) {
                if ((arr[i] - arr[i + 1]) != -1) {
                    isJJ = false;
                    break;
                }
                else
                    isJJ = true;
            }
        }
        else
            isJJ = true;

        if (isJJ)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return;
}

// UVa 11340 Newspaper
// Why do I have to include newlines?
// reimplement using iostream
void newsPaper() {
    int numTests, numPaid, numLines, cents, numChars;
    float total;
    scanf("%d", &numTests);

    while (numTests) {
        scanf("%d\n", &numPaid);
        char ch;
        std::unordered_map<char, int> vals;
        printf("numPaid: %d\n", numPaid);
        while (numPaid) {
            scanf("%c %d\n", &ch, &cents);
            printf("char: %c | cents: %d\n", ch, cents);
            vals[ch] = cents;
            numPaid--;
        }

        char line[10000];
        scanf("%d\n", &numLines);

        total = 0.0;
        printf("numLines: %d\n", numLines);
        while (numLines) {
            scanf("%[^\n]", line);

            for (int i = 0;; i++) {
                if (line[i] == '\0')
                    break;
                printf("%c", line[i]);
                if (vals.find(line[i]) != vals.end()) {
                    printf("Matched: %c\n", line[i]);
                    total += vals[line[i]];
                }
            }
            numLines--;
        }
        printf("%.2f$", total / 100.0);
        numTests--;
    }

    return;
}

int main() {
    jollyJumpers();
    return 0;
}

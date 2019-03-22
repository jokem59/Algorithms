#include <stdio.h>
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
// Why do I have to include newlines, seems to only happen when grabbing characters
// reimplement using iostream
void newsPaper() {
    int Case, i, n, len;
    double sum, c, cost[260];
    char s[10005], ch;
    std::cin >> Case;
    while (Case--) {
        for (i=0;i<=255;i++)
            cost[i] = 0.0;
        scanf("%d", &n);
        while (n--) {
            scanf(" %c %lf",&ch,&c);
      //      printf("%c %d",ch,c);
            cost[ch+128] = c;
        }
        scanf("%d", &n); getchar();
        sum = 0;
        while (n--) {
            gets(s);
            len = strlen(s);
            for (i=0;i<len;i++)
                sum += cost[s[i]+128];
        }
        printf("%.2lf$\n",sum/100.0);
    }

    return;
}


int main() {
    newsPaper();
    return 0;
}

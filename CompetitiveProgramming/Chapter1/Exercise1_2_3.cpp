#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

// UVa 00272 TEX Quotes using std::cin
void replaceQuotes()
{
    bool first = true;
    std::string input;

    while (!std::getline(std::cin, input).eof()) {
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '"') {
                if (first) {
                    printf("``");
                    first = false;
                }
                else {
                    printf("''");
                    first = true;
                }
            }
            else
                printf("%c", input[i]);
        }
        printf("\n"); // std::getline uses \n as delimiter so this adds new lines back in
    }

    return;
}

// UVa 00272 TEX Quotes using scanf
void replaceQuotes2()
{
    bool first = true;
    char curChar;

    while (scanf("%c", &curChar) != EOF)
    {
        if (curChar == '"') {
            if (first) {
                printf("``");
                first = false;
            }
            else {
                printf("''");
                first = true;
            }
        }
        else
            printf("%c", curChar);
    }
    return;
}

// UVa 01124 Celebrity Jeopardy
void celebJeopardy()
{
    std::string input;

    while (!std::getline(std::cin, input).eof()) {
        for (int i = 0; i < input.size(); i++) {
            printf("%c", input[i]);
        }
        printf("\n");
    }
}

// UVa 10550 Combination Lock; first number in input is starting position of dial
void combinationLock()
{
    int start, first, second, third;

    scanf("%d %d %d %d", &start, &first, &second, &third);

    // as long as one value is NOT zero
    while (start || first || second || third) {
        // multiple by 9 to get the value in degrees; 360 / 40 = 9;
        printf("%d\n",
               1080 + ((start - first + 40) % 40 + (second - first + 40) % 40 + (second - third + 40) % 40) * 9);

        scanf("%d %d %d %d", &start, &first, &second, &third);
    }

    return;
}

// UVa 11044 Searching for Nessy
void findNessy() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases > 0) {
        int row, col;
        scanf("%d %d", &row, &col);

        // integer division always gives us min number of sonar for row and col
        printf("%d\n", (row / 3) * (col / 3));
        numCases--;
    }
    return;
}

// UVa 11172 Relational Operators
void relationalOperators() {
    int numCases;
    scanf("%d", &numCases);

    for (; numCases > 0; numCases--) {
        int first, second;
        scanf("%d %d", &first, &second);
        if (first > second)
            printf("%c\n", '>');
        if (first < second)
            printf("%c\n", '<');
        if (first == second)
            printf("%c\n", '=');
    }

    return;
}

// UVa 11498 Division of Nlogonia
void divisionNlogonia() {
    int numCases, n, m;
    scanf("%d", &numCases);

    while (numCases != 0) {
        scanf("%d %d", &n, &m);

        while (numCases > 0) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (x == n || y == m)
                printf("%s\n", "divisa");
            if (x < n && y > m)
                printf("%s\n", "NO");
            if (x < n && y < m)
                printf("%s\n", "SO");
            if (x > n && y > m)
                printf("%s\n", "NE");
            if (x > n && y < m)
                printf("%s\n", "SE");
            numCases--;
        }

        scanf("%d", &numCases);
    }

    return;
}

// UVa 11727 Cost Cutting
void costCutting() {
    int numCases, x, y, z;
    scanf("%d", &numCases);

    for (int i = 0; i < numCases; i++) {
        std::vector<int> input;
        scanf("%d %d %d", &x, &y, &z);
        input.push_back(x);
        input.push_back(y);
        input.push_back(z);
        std::sort(input.begin(), input.end());

        printf("Case %d: %d\n", i + 1, input[1]);
    }

    return;
}

// UVa 10114 Loansome Car Buyer
void carBuyer() {
    int monthNums, numDeprecations, currentDecrease, currentMonth;
    double carTotal, downPayment, loanOwed, amountPayedPerMonth;

    std::vector<int> decreaseTime;
    std::vector<double> decrease;

    scanf("%d", &monthNums);

    while (monthNums > 0)
    {
        scanf("%lf %lf %d", &downPayment, &loanOwed, &numDeprecations);

        amountPayedPerMonth = loanOwed / monthNums;

        carTotal = downPayment + loanOwed;

        decreaseTime.resize(numDeprecations + 1);
        decrease.resize(numDeprecations + 1);

        for (int i = 0; i < numDeprecations; ++i)
            scanf("%d %lf", &decreaseTime[i], &decrease[i]);

        decreaseTime[numDeprecations] = 101;

        currentDecrease = 0;

        carTotal -= carTotal * decrease[currentDecrease];

        for (currentMonth = 1; carTotal < loanOwed; ++currentMonth)
        {
            loanOwed -= amountPayedPerMonth;

            if (decreaseTime[currentDecrease + 1] == currentMonth)
                ++currentDecrease;

            carTotal -= carTotal * decrease[currentDecrease];
        }

        --currentMonth;

        if (currentMonth == 1)
            printf("%d month\n", currentMonth);
        else
            printf("%d months\n", currentMonth);

        scanf("%d", &monthNums);
    }
}

// UVa 11559 Event Planning
void eventPlanning() {
    // # participants, budget, num hotels, number of weeks

    // multiple test cases
    int numPeople, budget, numHotels, numWeeks;
    while(scanf("%d %d %d %d", &numPeople, &budget, &numHotels, &numWeeks) == 4) {
        // printf("numPeople: %d | budget: %d | numHotels: %d | numWeeks: %d\n", numPeople, budget, numHotels, numWeeks);
        bool stayHome = false;
        int cost = budget + 1;

        for(; numHotels > 0; numHotels--) {
            int dailyRate, numBeds;
            scanf("%d", &dailyRate);
            // printf("Daily rate for current hotel: %d\n", dailyRate);

            for(int i = numWeeks; i > 0; i--) {
                scanf("%d", &numBeds);
                // printf("numBeds: %d\n", numBeds);
                if (numBeds < numPeople)
                    continue;

                int curTripCost = (dailyRate * numPeople);
                // printf("curTripCost: %d\n", curTripCost);
                cost = curTripCost < cost ? curTripCost : cost;
            }
        }
        if (cost > budget)
            printf("stay home\n");
        else
            printf("%d\n", cost);
    }
    return;
}

// UVa 11799 Horror Dash
void horrorDash() {

    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);  // std::cin now faster than scanf

    horrorDash();
    return 0;
}

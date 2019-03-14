#include <string>
#include <stdio.h>
#include <iostream>

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

int main() {
    std::ios_base::sync_with_stdio(false);  // std::cin now faster than scanf

    combinationLock();
    return 0;
}

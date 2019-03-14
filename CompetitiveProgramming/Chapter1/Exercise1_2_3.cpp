#include <string>
#include <stdio.h>
#include <iostream>

// UVa 00272 TEX Quotes
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

int main() {
    std::ios_base::sync_with_stdio(false);  // std::cin now faster than scanf

    celebJeopardy();

    return 0;
}

#include <string>
#include <stdio.h>
#include <iostream>

// UVa 00272 TEX Quotes
std::string SampleInput272 = "\"To be or not to be,\" quoth the Bard, \"that\n"
                    "is the question\".\n"
                    "The programming contestant replied: \"I must disagree.\n"
                    "To `C' or not to `C', that is The Question!\"";
void replaceQuotes()
{
    bool first = true;
    std::string input;

    std::getline(std::cin, input);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '"') {
            if (first) {
                printf("%s", "``");
                first = false;
            }
            else {
                printf("%s", "''");
                first = true;
            }
        }
        else
            printf("%c", input[i]);
    }
    return;
}

int main() {

    replaceQuotes();

    return 0;
}

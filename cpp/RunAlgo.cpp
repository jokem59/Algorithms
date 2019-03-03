/*
    This "main" module takes in 
*/

#include <iostream>

int main(int argc, char* argv[]) {

    std::cout << "argc: " << argc << '\n';
    for (int i = argc; i > 1; i--) {
        printf("%s\n", argv[i-1]);
    }

    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

int recursiveSumArr(std::vector<int>& input) {
    // base case
    if (input.size() == 0)
        return 0;
    if (input.size() == 1)
        return input[0];

    // recursive case
    return input[0] + recursiveSumArr(std::vector<int>(input.begin() + 1, input.end()));
}

int binarySearch(std::vector<int>& input, int item) {
    std::sort(input.begin(), input.end());

    int low = 0;
    int mid, guess;
    int high = input.size() - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        guess = input[mid];

        if (guess == item)
            return mid;
        if (guess > item)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

std::vector<int> quickSort(std::vector<int>& in) {
    // base case
    if (in.size() <= 1)
        return in;
    
    return in;
}

int main(int argc, char* argv[]) {
    std::vector<int> in {4, 8, 2, 1, 9, 9};

    int res = binarySearch(in, 4);

    if (res >= 0)
        std::cout << "Ans: " << in[res] << '\n';
    else
        std::cout << "not found\n";
    return 0;
}

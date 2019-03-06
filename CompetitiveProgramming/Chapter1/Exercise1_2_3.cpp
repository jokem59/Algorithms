#include <string>
#include <vector>
#include <algorithm>

double pi = 3.143.14159265358979323846264338327950288419;
std::vector<std::string> week {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

void printPi(int n) {
    printf("%.*f\n", n, pi);
    return;
}

int dayOfWeek(std::string day) {
    for(int i = 0; i < week.size(); i++) {
        if (day == week[i])
            return i;
    }
    return -1;
}

void printDistinctSorted(std::vector<int> list) {
    std::sort(list.begin(), list.end());
    std::vector<int>::iterator it;
    it = std::unique(list.begin(), list.end());
    list.resize(std::distance(list.begin(), it));
    for(int i = 0; i < list.size(); i++) {
        printf("%d ", list[i]);
    }
    return;
}

void orderBirthdates(std::vector<int>& birthdates) {
    

    return;
}

int main() {

    printPi(5);

    return 0;
}
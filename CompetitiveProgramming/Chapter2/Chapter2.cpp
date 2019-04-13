#include <stdio.h>
#include <sstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <utility>

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

void print2DVector(std::vector<std::vector<char>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }
    return;
}

// Runtime complexity of check n[0][0] against all N[i][j] possibilities: (N - n) * (N - n) -> O(N^2 + n^2)
// Runtime complexity of checking each element in n if n[0][0] matches something in N[i][j]
//     n * n -> O(n^2)
// Runtime complexity of the function: O((N^2 + n^2) * (n^2))
int matchSquares(std::vector<std::vector<char>>& big, std::vector<std::vector<char>>& small) {
    int count = 0;
    int N = big.size();
    int n = small.size();
    char firstMatch = small[0][0];

    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            if (firstMatch == big[i][j]) {
                bool match = true;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (small[k][l] != big[i+k][j+l]) {
                            match = false;
                            break;
                        }
                    }

                    if (!match)
                        break;
                }
                if (match) {
                    // std::cout << "Matched on i: " << i << ", j: " << j << "\n";
                    count++;
                }
            }
        }
    }

    return count;
}

// Runtime complexity: n/2 * n/2 = O(n^2)
void rotateSquare90Deg(std::vector<std::vector<char>>& small) {
    int cycles = small.size() / 2;
    int n = small.size();

    // Outer loop controls which "ring" we're working on
    for (int i = 0; i < cycles; i++) {
        // Inner loop controls the position of the swaps
        for (int j = i; j < n - i - 1; j++) {
            char tmp = small[i][j];
            small[i][j] = small[n-j-1][i];
            small[n-j-1][i] = small[n-i-1][n-j-1];
            small[n-i-1][n-j-1] = small[j][n-i-1];
            small[j][n-i-1] = tmp;
        }
    }

    return;
}

// UVa 10855 Rotated Square
/*
  Find number of times n is matched in N
  - Rotate n x n matrix
  - Find number of matches of n in N
 */
void rotatedSquare() {
    int N, n;
    while (1) {
        //std::cout << "loop\n";
        std::cin >> N >> n;
        if (N == 0 && n == 0)
            break;

        std::vector<std::vector<char>> big(N, std::vector<char>(N, 'A'));
        std::vector<std::vector<char>> small(n, std::vector<char>(n, 'A'));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> big[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> small[i][j];
            }
        }

        // print2DVector(small);
        // print2DVector(small);

        std::vector<int> rotate(4, 0);
        for (int i = 0; i < 4; i++) {
            if (i != 0)
                rotateSquare90Deg(small);
            rotate[i] = matchSquares(big, small);
        }

        //std::cout << "end of loop\n";
        std::cout << rotate[0] << ' ' << rotate[1] << ' ' << rotate[2] << ' ' << rotate[3] << '\n';
    }
    return;
}

bool goUp(int& y, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        y++;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

bool goLeft(int& x, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        x--;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

bool goDown(int& y, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        y--;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

bool goRight(int& x, int& result, int& times, int target) {
    if (target == result)
        return true;
    for (int i = 0; i < times / 2; i++) {
        x++;
        result++;
        if (target == result)
            return true;
    }
    times++;
    return false;
}

// UVa 10920 Spiral Tap
// Brute force by visiting each square = O(SZ^2) -> O(100000^2) -> O(10,000,000,000) -> ~10 seconds, too slow
// Note pattern that every top right corner of each concentric sqaure is odd number (1, 3, 5, 7, 9...)
void spiralTapBF() {
    int sz, p, x, y;
    while (1) {
        std::cin >> sz >> p;
        if (sz == 0 && p ==0)
            break;

        x = (sz / 2) + 1;
        y = (sz / 2) + 1;

        int times = 2;
        int result = 1;
        bool done = false;
        while (1) {
            done = goUp(y, result, times, p);
            if (done)
                break;
            done = goLeft(x, result, times, p);
            if (done)
                break;
            done = goDown(y, result, times, p);
            if (done)
                break;
            done = goRight(x, result, times, p);
            if (done)
                break;
        }

        std::cout << "Line = " << y << ", column = " << x << '\n';
    }
    return;
}

// TODO: Need to account for x, y if size of sqaure is big, it will affect the x, y of the result!
void spiralTap() {
    int sz, x, y;
    double p;
    while (1) {
        std::cin >> sz >> p;
        if (sz == 0 && p == 0)
            break;

        double doubleLowerRange = sqrt(p);
        int lowerRange = (unsigned int)doubleLowerRange % 2 == 0 ? (unsigned int)doubleLowerRange - 1 : (unsigned int)doubleLowerRange;

        // std::cout << "LowerRange: " << lowerRange << '\n';

        x = sz / 2;
        y = sz / 2;
        if (sz > 1) {
            x += lowerRange / 2;
            y += lowerRange / 2;
        }

        // std::cout << "x: " << x << "y: " << y << '\n';

        unsigned int result = lowerRange * lowerRange;

        // std::cout << "Target: " << (unsigned int)p << '\n';
        // std::cout << "Result: " << result << '\n';

        while (result != (unsigned int)p) {
            // up one always
            y++;
            result++;

            // left lowerRange times
            if (p <= result + lowerRange) { // answer must be in this line
                x -= (p - result);
                result = result + (p - result);
                break;
            }
            else {
                x -= lowerRange;
                result += lowerRange;
            }

            // down lowerRange + 1 times
            if (p <= result + lowerRange + 1) {
                y -= (p - result);
                result = result + (p - result);
                break;
            }
            else {
                y -= lowerRange + 1;
                result += lowerRange + 1;
            }

            // right lowerRange + 1 times
            if (p <= result + lowerRange + 1) {
                x += (p - result);
                result = result + (p - result);
                break;
            }
            else {
                x += lowerRange + 1;
                result += lowerRange + 1;
            }

            // up lowerRange + 1 time not including the next top right corner
            if (p < result + lowerRange + 1) {
                y += (p - result);
                result = result + (p - result);
                break;
            } else { // should never get to this point
                y += lowerRange + 1;
                result += lowerRange + 1;
            }
        }
        std::cout << "Line = " << y + 1 << ", column = " << x + 1 << '.' << '\n';
    }
    return;
}

int getSumOfVector(const std::vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

void processGrid(std::vector<std::vector<int>>& g) {
    std::vector<std::vector<int>> tmp = g;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            if (i + 1 < 3)
                sum += tmp[i+1][j];
            if (i - 1 >= 0)
                sum += tmp[i-1][j];
            if (j + 1 < 3)
                sum += tmp[i][j+1];
            if (j - 1 >= 0)
                sum += tmp[i][j-1];
            g[i][j] = sum % 2;
        }
    }
    return;
}

// UVa 11581 Grid Successors
// How to compute runtime for this??
void gridSuccessors() {
    int numCases, x, y, z;
    std::string line;
    std::vector<std::vector<int>> g(3, std::vector<int>(3, 0));
    std::cin >> numCases;
    std::getline(std::cin, line);

    for (int i = 0; i < numCases; i++) {
        std::getline(std::cin, line);
        int index = 0;

        for (int j = 0; j < 3; j++) {
            std::getline(std::cin, line);
            x = (int)(line[0] - 48);
            y = (int)(line[1] - 48);
            z = (int)(line[2] - 48);
            // std::cout << x << ' ' << y << ' ' << z << '\n';
            g[j][0] = x;
            g[j][1] = y;
            g[j][2] = z;
        }

        while (1) {
            int gridSum = 0;
            for (int k = 0; k < 3; k++) {
                gridSum += getSumOfVector(g[k]);
            }

            // for (int a = 0; a < 3; a++) {
            //     for (int b = 0; b < 3; b++) {
            //         std::cout << g[a][b] << ' ';
            //     }
            //     std::cout << '\n';
            // }

            // std::cout << "gridSum = " << gridSum << "\n\n";
            if (gridSum == 0)
                break;

            processGrid(g);

            index++;
        }

        std::cout << index - 1 << '\n';
    }

    return;
}

// UVa 00146 ID Codes
// Num inputs = n -> O(n)
void idCodes() {
    std::string line;
    bool result;

    while (1) {
        std::getline(std::cin, line);

        if (line == "#")
            break;

        result = std::next_permutation(line.begin(), line.end());
        if (result)
            std::cout << line << '\n';
        else
            std::cout << "No Successor\n";
    }
    return;
}

// UVa 10107 What is the Median?
// O((N * Log N) * 10000)
void whatIsMedian() {
    std::vector<unsigned int> arr;
    unsigned int median;
    while (1) {
        long long int num = -1;
        std::cin >> num;

        if (num < 0)
            break;

        arr.push_back(num);
        std::sort(arr.begin(), arr.end());

        if (arr.size() == 1) {
            std::cout << arr[0] << '\n';
            continue;
        }

        if (arr.size() % 2 == 1) {
            median = arr[arr.size() / 2];
        }
        else {
            median = (arr[arr.size() / 2] + arr[(arr.size() / 2) - 1]) / 2;
        }
        std::cout << median << '\n';
    }
    return;
}

std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// UVa 10258 Contest Scoreboard
// Such an ugly way to grab input =(
// Use a unordere_map, with key = Contestant, val = struct data

struct Contestant {
    int contestantNumber;
    int numSolved = 0;
    int totalTime = 0;
    std::unordered_map<int, std::pair<int, bool>> solved;    // prob : { totalTime, solved }

    Contestant() {}
    Contestant(const Contestant& c2) { contestantNumber = c2.contestantNumber; solved = c2.solved; numSolved = c2.numSolved; totalTime = c2.totalTime;}
    ~Contestant() {}
    void ComputeTotals()
        {
            // std::cout << "ComputeTotals() for ContestantNumber " << contestantNumber << '\n';
            // for each
            auto iter = solved.begin();
            while (iter != solved.end())
            {
                if (iter->second.second)
                {
                    // std::cout << "Problem solved = " << iter->first << " | " << iter->second.first << '\n';
                    totalTime += iter->second.first;
                    numSolved++;
                }
                iter++;
            }
            return;
        }
};

/* COSTLY MISTAKE _ LET THIS BE A LESSON OF NOT THINKING THROUGH SOLUTION BEFORE STARTING TO CODE
   CODED OUT MOST OF THE PROBLEM WHEN I (STUPIDLY) REALIZED I SHOULD'VE USED VECTOR INSTEAD OF
   UNORDERED_MAP BECAUSE I NEED TO SORT!!!!! */

// UVa 10258 Contest Scoreboard
// Should've recognized SORT means VECTOR - can't sort an unordered_map =(
void contestScoreboard() {
    int numCases;
    std::string line;
    std::string::size_type sz;
    std::cin >> numCases;
    std::getline(std::cin, line);
    std::getline(std::cin, line);

    for (int i = 0; i < numCases; i++) {
        int contestant, problem, time;
        char status;

        std::unordered_map<int, Contestant> m;
        std::vector<std::string> tokens;
        while (std::getline(std::cin, line)) {
            if (line.size() == 0)
                break;

            tokens = splitString(line, ' ');
            contestant = stoi(tokens[0], nullptr);
            problem = stoi(tokens[1], nullptr);
            time = stoi(tokens[2], nullptr);
            status = tokens[3].c_str()[0];
            // std::cout << "Contestant: " << contestant << " Status: " << status << " Problem: " << problem << '\n';

            if (m.find(contestant) != m.end())
            {
                if (m[contestant].solved.find(problem) != m[contestant].solved.end())
                {
                    if (m[contestant].solved[problem].second == true)
                    {
                        // do nothing
                    }
                    else
                    {
                        if (status == 'I')
                        {
                            m[contestant].solved[problem].first += 20;
                        }
                        if (status == 'C')
                        {
                            //std::cout << "Previous Time: " << m[contestant].solved[problem].first
                            //          << "New Time: " << m[contestant].solved[problem].first + time << '\n';
                            m[contestant].solved[problem].first += time;
                            m[contestant].solved[problem].second = true;
                        }
                        if (status != 'C' || status != 'I') {
//                            std::cout << "Current Time: " << m[contestant].solved[problem].first << '\n';
                        }
                    }
                }
                // new entry problem entry
                else
                {
                    //std::cout << "Adding new problem entry for " << problem << "\n";
                    m[contestant].solved[problem] = std::make_pair(0, false);
                    if (status == 'I'){
                        m[contestant].solved[problem].first = 20;
                        m[contestant].solved[problem].second = false;
                    }
                    if (status == 'C') {
                        m[contestant].solved[problem].first = time;
                        m[contestant].solved[problem].second = true;
                    }
                    if (status != 'I' || status != 'C') {
                        // m[contestant].solved[problem] = std::make_pair(0, false);
                    }
                }
            }
            else // new contestant entry
            {
                m[contestant] = Contestant();
                m[contestant].contestantNumber = contestant;
                m[contestant].solved[problem] = std::make_pair(0, false);

                if (status == 'I') {
                    m[contestant].solved[problem].first = 20;
                    m[contestant].solved[problem].second = false;
                    //std::cout << "Adding I problem, with time: " << data.solved[problem].first << '\n';
                }
                if (status == 'C') {
                    m[contestant].solved[problem].first = time;
                    m[contestant].solved[problem].second = true;
                }
                if (status != 'I' || status != 'C') {
                    //m[contestant].solved[problem] = std::make_pair(0, false);
                }
                //std::cout << "Pre check, current time: " << data.solved[problem].first << '\n';
//                m[contestant] = data;
                if (contestant == 1 && problem == 2) {
                    // std::cout << "Post check, current time: " << m[contestant].solved[problem].first << '\n';
                }
            }
            //std::cout << contestant << ":" << problem << ":" << time << ":" << status << '\n';
        }

        // Print out results for current test case
        // Contestant# NumCorrectSubmissions TotalTime
        std::vector<Contestant> arr;
        auto it = m.begin();
        while (it != m.end())
        {
            arr.push_back(it->second);
            it++;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            arr[j].ComputeTotals();
        }

        // Implement multi-field sort
        std::sort(arr.begin(), arr.end(), [&](const Contestant& c1, const Contestant& c2) {
                if (c1.numSolved > c2.numSolved)
                {
                    return true;
                }
                if (c1.numSolved == c2.numSolved)
                {
                    if (c1.totalTime < c2.totalTime)
                    {
                        return true;
                    }
                    if (c1.totalTime == c2.totalTime)
                    {
                        if (c1.contestantNumber < c2.contestantNumber)
                        {
                            return true;
                        }
                    }
                }
                return false;
            });

        for (int j = 0; j < arr.size(); j++)
        {
            std::cout << arr[j].contestantNumber << " " << arr[j].numSolved << " " << arr[j].totalTime << '\n';
        }

        if (i == numCases - 1)
        { }
        else
            std::cout << '\n';
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    potentCorner();
    return 0;
}

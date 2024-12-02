#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool isMonotonic(const vector<int>& levels) {
    bool increasing = true, decreasing = true;

    for (size_t i = 1; i < levels.size(); ++i) {
        if (levels[i] > levels[i - 1]) {
            decreasing = false;
        } else if (levels[i] < levels[i - 1]) {
            increasing = false;
        }
    }
    return increasing || decreasing;
}

bool hasValidDifferences(const vector<int>& levels) {
    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = abs(levels[i] - levels[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    string line;
    int safeReportsCount = 0;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> levels;
        int level;

        while (ss >> level) {
            levels.push_back(level);
        }

        if (!levels.empty() && isMonotonic(levels) && hasValidDifferences(levels)) {
            ++safeReportsCount;
        }
    }

    inputFile.close();

    cout << safeReportsCount << endl;

    return 0;
}

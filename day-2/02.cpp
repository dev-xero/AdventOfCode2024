#include <bits/stdc++.h>

using namespace std;

bool isLevelSafe(vector<int> levels) {
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < levels.size(); i++) {
        int curr = levels.at(i);
        int prev = levels.at(i - 1);

        int diff = curr - prev;

        // It cannot be safe since it isn't within bounds
        if (prev == curr) return false;

        // Bounds is [1, 3]
        if (abs(diff) > 3) return false;

        if (curr > prev) isDecreasing = false;
        if (prev > curr) isIncreasing = false;
    }

    // Must either be increasing or decreasing
    return isIncreasing || isDecreasing;
}

// Safety dampener into consideration
bool isDampenedLevelSafe(vector<int> levels) {
    if (isLevelSafe(levels)) {
        return true;
    }

    for (size_t i = 0; i < levels.size(); i++) {
        vector<int> remaining = levels;
        remaining.erase(remaining.begin() + i);

        if (isLevelSafe(remaining)) return true;
    }

    // If we get here, the level can never be safe
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string filename = "";

    // Prompt for filename
    cout << "Input File: ";
    cout.flush();

    // Read in file name
    getline(cin, filename);

    // Read input from file
    ifstream inputFile("day-2/" + filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to read file\n";

        return 1;
    }

    // We are reading an n x m input list
    string line = "";

    int safeLevels = 0;

    // Analyze each level
    while (getline(inputFile, line)) {
        vector<int> levels;
        stringstream stream(line);

        int num;

        // Read each num into the vector
        while (stream >> num) levels.push_back(num);

        if (isDampenedLevelSafe(levels)) safeLevels++;
    }

    cout << "safe levels: " << safeLevels << '\n';

    return 0;
}
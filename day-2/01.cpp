#include <bits/stdc++.h>

using namespace std;

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

    while (getline(inputFile, line)) {
        vector<int> levels;
        stringstream stream(line);

        int num;

        // Read each num into the vector
        while (stream >> num) {
            levels.push_back(num);
        }

        int isInc = 0;  // false by default

        uint lPointer = 0;
        uint rPointer = 1;

        for (int num : levels) {
            cout << num << ' ';
        }

        cout << '\n';

        // We know each level has m numbers
        while (rPointer < levels.size()) {
            int diff = levels.at(lPointer) - levels.at(rPointer);

            // If in the first iteration and diff is positive, means we're
            // increasing
            if (lPointer == 0) {
                isInc = diff > 0;
            }

            // If we've determined it to be increasing, but diff shows
            // otherwise, means this level will never be safe.
            // Same for decreasing.
            if ((isInc && diff < 0) || (!isInc && diff > 0)) {
                break;
            }

            // If the diff is not in the range (1 - 3), it is unsafe
            if (abs(diff) < 1 || abs(diff) > 3) {
                break;
            }

            lPointer++;
            rPointer++;
        }

        // Means the levels stayed safe
        if (rPointer == levels.size()) {
            safeLevels++;
        }
    }

    cout << "safe levels: " << safeLevels << '\n';

    return 0;
}
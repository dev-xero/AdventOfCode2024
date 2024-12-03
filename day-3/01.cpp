#include <bits/stdc++.h>

using namespace std;

int computeMuls(const string& line) {
    int subComputation = 0;

    // We're going to read the substring of each (idx, idx+4) to match a
    // `mult(` sequence
    for (size_t i = 0; i+4 <= line.size(); i++) {
        if (line.substr(i, 4) == "mul(") {
            int a = 0;
            int b = 0;

            // If we can scan out an offset of the line with two integers,
            // attempt to compute it
            if (sscanf(line.c_str() + i, "mul(%d,%d)", &a, &b) == 2) {
                char ch;

                sscanf(line.c_str() + i, "mul(%d,%d%c", &a, &b, &ch);

                // Edge case: must be closed by a ')' character
                if (ch != ')') continue;
                
                subComputation += a * b;
            }
        }
    }

    // This is the result of the mul() computations for this line
    return subComputation;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Input File: ";
    string filename;

    cout.flush();
    getline(cin, filename);

    ifstream inputFile("day-3/" + filename);

    if (!inputFile.is_open()) {
        cerr << "Unable to open this file.\n";
        return 1;
    }

    // The input is a long string where each line contains some `mul(a,b)`
    // instructions
    string line;
    int computation = 0;

    while (inputFile >> line) {
        computation += computeMuls(line);
    }

    cout << "computed: " << computation << '\n';

    return 0;
}
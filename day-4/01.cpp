#include <bits/stdc++.h>

using namespace std;

int rowDir[] = {0, 1, 0, -1, 1, 1, -1, -1};
int colDir[] = {1, 0, -1, 0, 1, -1, 1, -1};

bool isSafe(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int countXMAS(const vector<string>& grid, const string& word = "XMAS") {
    int rows = grid.size();
    int cols = grid[0].size();
    int wordLen = word.size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == word[0]) {
                // Check all 8 directions
                for (int dir = 0; dir < 8; ++dir) {
                    int x = i, y = j;
                    bool found = true;

                    for (int k = 1; k < wordLen; ++k) {
                        x += rowDir[dir];
                        y += colDir[dir];

                        if (!isSafe(x, y, rows, cols) ||
                            grid[x][y] != word[k]) {
                            found = false;
                            break;
                        }
                    }

                    if (found) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string filename;
    cout << "Input file: ";
    cout.flush();

    getline(cin, filename);

    ifstream inputFile("day-4/" + filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to read input file.";
        return 1;
    }

    vector<string> grid = {};
    string line;

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    int result = countXMAS(grid);
    cout << "XMAS count: " << result << '\n';

    return 0;
}
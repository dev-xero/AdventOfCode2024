#include <bits/stdc++.h>

#include "types.hpp"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll l1 = 0;
    ll l2 = 0;

    vecLL list1 = {};
    vecLL list2 = {};

    // Read input file
    ifstream inputFile("./01/input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    // Build both lists from input
    while (inputFile >> l1 >> l2) {
        cout << "l1: " << l1 << " l2: " << l2 << '\n';

        list1.push_back(l1);
        list2.push_back(l2);
    }

    // Close file (free memory)
    inputFile.close();

    // Sort both lists
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    // Compare each element and sum absolute diff (both lists are same size)
    ll diff = 0;

    for (int i = 0; i < list1.size(); i++) {
        diff += abs(list1[i] - list2[i]);
    }

    cout << "diff: " << diff << '\n';

    return 0;
}
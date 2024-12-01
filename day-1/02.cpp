#include <bits/stdc++.h>

#include "types.hpp"

using namespace std;

/**
 * Similarity score evaluator.
 *
 * Starts by building two lists from the input file, then computes similarity
 * using the function:
 * - num * count(num) - essentially summing the product of how many times each
 * number in list one appears in list two with the number itself.
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Obtain input file
    string filename = "";

    cout << "Input file name: ";
    cout.flush();

    getline(cin, filename);

    // Read input and prepare vectors
    ifstream inputFile("day-1/" + filename);

    if (!inputFile.is_open()) {
        cerr << "Unable to read input file.\n";
    }

    ll l1 = 0;
    ll l2 = 0;

    vecLL list1 = {};
    vecLL list2 = {};

    // Build both vector lists
    while (inputFile >> l1 >> l2) {
        cout << "l1: " << l1 << " l2: " << l2 << '\n';

        list1.push_back(l1);
        list2.push_back(l2);
    }

    vecLL similarityVector = {};

    // Compute similarity
    for (ll entry : list1) {
        ll occurrences = count(list2.begin(), list2.end(), entry);
        similarityVector.push_back(entry * occurrences);
    }

    // Sum up vector
    ll similarity =
        accumulate(similarityVector.begin(), similarityVector.end(), 0);

    cout << "Similarity: " << similarity << '\n';

    return 0;
}
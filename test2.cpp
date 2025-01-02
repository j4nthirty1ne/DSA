#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

int main() {
    vector<int> numbers = {5, 3, 8, 6, 2, 7, 4, 1};

    auto start = high_resolution_clock::now();  // Start time

    sort(numbers.begin(), numbers.end());  // Sorting

    auto stop = high_resolution_clock::now();  // Stop time

    auto duration = duration_cast<microseconds>(stop - start);  // Measure duration
    cout << "Time taken to sort: " << duration.count() << " microseconds" << endl;

    return 0;
}

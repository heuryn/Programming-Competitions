#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num_draws = 10 * n;
    map<int, int> number_counts;

    for (int i = 0; i < num_draws; ++i) {
        for (int j = 0; j < 5; ++j) {
            int number;
            cin >> number;
            number_counts[number]++;
        }
    }

    vector<int> sus_numbers;
    for (const auto &entry : number_counts) {
        if (entry.second > 2 * n) {
            sus_numbers.push_back(entry.first);
        }
    }

    if (sus_numbers.empty()) {
        cout << -1 << endl;
    } else {
        sort(sus_numbers.begin(), sus_numbers.end());
        for (size_t i = 0; i < sus_numbers.size(); ++i) {
            if (i > 0) cout << " ";
            cout << sus_numbers[i];
        }
        cout << endl;
    }

    return 0;
}
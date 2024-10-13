#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int excluded_count = 0;
    for (int i = 0; i < n; ++i) {
        int difficulty;
        cin >> difficulty;
        if (difficulty % 2 != 0) {
            ++excluded_count;
        }
    }

    cout << excluded_count << endl;

    return 0;
}
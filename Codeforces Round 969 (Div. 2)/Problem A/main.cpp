#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    if (l % 2 == 0) {
        if (r % 2 == 0) {
            cout << (r - l) / 4 << endl;
        } else {
            cout << (r - l + 1) / 4 << endl;
        }
    } else {
        if (r % 2 == 0) {
            cout << (r - l + 1) / 4 << endl;
        } else {
            cout << (r - l + 2) / 4 << endl;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
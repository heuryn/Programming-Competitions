#include <iostream>
#include <cmath>

using namespace std;


bool isBeautifulSquare(int n, const string &s) {
    int r = sqrt(n);
    if (r * r != n) {
        return false;
    }

    for (int i = 0; i < r; ++i) {
        if (s[i] != '1' || s[n - r + i] != '1') {
            return false;
        }
    }

    for (int i = 1; i < r - 1; ++i) {
        if (s[i * r] != '1' || s[(i + 1) * r - 1] != '1') {
            return false;
        }
        for (int j = 1; j < r - 1; ++j) {
            if (s[i * r + j] != '0') {
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (isBeautifulSquare(n, s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

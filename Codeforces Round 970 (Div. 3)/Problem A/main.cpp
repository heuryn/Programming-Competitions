#include <iostream>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if(b % 2 == 0) {
        if (a % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    } else {
        if (a >= 2 && a % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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

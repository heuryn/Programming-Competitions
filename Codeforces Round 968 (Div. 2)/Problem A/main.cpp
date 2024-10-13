#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n < 2) {
        cout << "NO" << endl;
    }

    for(int i = 0; i < n - 1; i++) {
        if(s[i] != s[i + 1] && s[0] != s[n - 1]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}

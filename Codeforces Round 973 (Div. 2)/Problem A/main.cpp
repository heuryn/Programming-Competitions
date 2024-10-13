#include <iostream>

using namespace std;

void solve() {
    int n;
    int x, y;
    cin >> n >> x >> y;
    int s = min(x, y);
    if (n % s == 0) {
        cout << n / s << endl;
    } else {
        cout << n / s + 1 << endl;
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

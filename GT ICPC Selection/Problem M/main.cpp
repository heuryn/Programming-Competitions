#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int r_max = 0, w_max = 0;
    bool possible = true;

    for (int i = 0; i < m; i++) {
        int r_i, w_i;
        cin >> r_i >> w_i;
        r_max = max(r_max, r_i);
        w_max = max(w_max, w_i);

        if (r_max + w_max > n) {
            possible = false;
        }
    }

    if (possible) {
        string result;
        result = string(r_max, 'R') + string(n - r_max, 'W');
        cout << result << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
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

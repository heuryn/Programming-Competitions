#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> max_beauty(10, -1);

    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        d--;

        max_beauty[d] = max(max_beauty[d], b);
    }

    bool valid = true;
    int total_beauty = 0;

    for (int i = 0; i < 10; i++) {
        if (max_beauty[i] == -1) {
            valid = false;
            break;
        }
        total_beauty += max_beauty[i];
    }

    if (valid) {
        cout << total_beauty << endl;
    } else {
        cout << "MOREPROBLEMS" << endl;
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

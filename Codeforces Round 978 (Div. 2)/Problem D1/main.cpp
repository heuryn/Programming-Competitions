#include <iostream>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 2) {
        int j = i % n + 1;
        int res1 = ask(i, j);
        int res2 = ask(j, i);
        if (res1 != res2) {
            int k = (i + 1) % n + 1;
            int res3 = ask(i, k);
            int res4 = ask(k, i);
            if (res3 == res4) {
                cout << "! " << j << endl;
                break;
            } else {
                cout << "! " << i << endl;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

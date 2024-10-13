#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    ll total = 0;
    ll max_ai = 0;
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        total += ai;
        if (ai > max_ai)
            max_ai = ai;
    }
    ll customers_needed = max((total + x - 1) / x, max_ai);
    cout << customers_needed << '\n';
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

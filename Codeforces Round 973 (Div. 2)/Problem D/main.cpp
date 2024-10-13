#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n), final_a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        final_a[0] = a[0];
        for(int i = 1; i < n; ++i) {
            final_a[i] = max(a[i], final_a[i-1]);
        }
        long long result = final_a[n-1] - final_a[0];
        cout << result << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
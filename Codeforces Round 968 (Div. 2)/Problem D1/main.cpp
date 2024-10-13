#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> compute_mex_values(const vector<int>& seq) {
    set<int> s(seq.begin(), seq.end());
    int first_mex = 0;

    while (s.count(first_mex)) {
        first_mex++;
    }

    int second_mex = first_mex + 1;
    while (s.count(second_mex)) {
        second_mex++;
    }

    return {first_mex, second_mex};
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> mex_values(n);
    vector<vector<int>> sequences(n);

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        sequences[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> sequences[i][j];
        }
        mex_values[i] = compute_mex_values(sequences[i]);
    }

    vector<int> dp(m + 1);

    for (int k = m; k >= 0; k--) {
        dp[k] = k;

        for (int i = 0; i < n; i++) {
            int first_mex = mex_values[i].first;
            int second_mex = mex_values[i].second;

            dp[k] = max(dp[k], second_mex);
            dp[k] = max(dp[k], dp[first_mex]);
        }
    }

    for (int k = 0; k <= m; k++) {
        dp[k] = k;

        for (int i = 0; i < n; i++) {
            int first_mex = mex_values[i].first;
            int second_mex = mex_values[i].second;

            dp[k] = max(dp[k], second_mex);
            dp[k] = max(dp[k], dp[first_mex]);
        }
    }

    long long result_sum = 0;
    for (int k = 0; k <= m; k++) {
        result_sum += dp[k];
    }

    cout << result_sum << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

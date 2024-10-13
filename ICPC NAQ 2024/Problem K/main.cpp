#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getPoints(int timeDiff) {
    if (timeDiff <= 15) return 7;
    if (timeDiff <= 23) return 6;
    if (timeDiff <= 43) return 4;
    if (timeDiff <= 102) return 2;
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> expected(n);
    vector<int> actual(m);

    for (int i = 0; i < n; ++i) {
        cin >> expected[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> actual[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int timeDiff = abs(expected[i - 1] - actual[j - 1]);
            int points = getPoints(timeDiff);

            if (points > 0) {
                dp[i][j] = max(dp[i - 1][j - 1] + points, max(dp[i - 1][j], dp[i][j - 1]));
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
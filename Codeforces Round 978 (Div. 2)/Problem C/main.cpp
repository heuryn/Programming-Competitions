#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = -1e9;

int dp[MAX_N][4];

void solve() {
    int n;
        cin >> n;
        string s_top, s_bottom;
        cin >> s_top >> s_bottom;

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = INF;
        }
        dp[0][0] = 0;

        for (int pos = 0; pos < n; ++pos) {
            for (int mask = 0; mask < 4; ++mask) {
                if (dp[pos][mask] == INF) continue;

                if (mask == 3) {
                    dp[pos + 1][0] = max(dp[pos + 1][0], dp[pos][mask]);
                    continue;
                }

                if (mask == 0) {
                    if (pos + 2 < n) {
                        int alvaro_top_count = (s_top[pos] == 'A') + (s_top[pos + 1] == 'A') + (s_top[pos + 2] == 'A');
                        int alvaro_top_wins = (alvaro_top_count >= 2) ? 1 : 0;
                        int alvaro_bot_count = (s_bottom[pos] == 'A') + (s_bottom[pos + 1] == 'A') + (s_bottom[pos + 2] == 'A');
                        int alvaro_bot_wins = (alvaro_bot_count >= 2) ? 1 : 0;
                        dp[pos + 3][0] = max(dp[pos + 3][0], dp[pos][mask] + alvaro_top_wins + alvaro_bot_wins);
                    }

                    if (pos + 1 < n) {
                        int alvaro_count = (s_top[pos] == 'A') + (s_bottom[pos] == 'A') + (s_top[pos + 1] == 'A');
                        int alvaro_wins = (alvaro_count >= 2) ? 1 : 0;
                        dp[pos + 1][1] = max(dp[pos + 1][1], dp[pos][mask] + alvaro_wins);
                    }

                    if (pos + 1 < n) {
                        int alvaro_count = (s_top[pos] == 'A') + (s_bottom[pos] == 'A') + (s_bottom[pos + 1] == 'A');
                        int alvaro_wins = (alvaro_count >= 2) ? 1 : 0;
                        dp[pos + 1][2] = max(dp[pos + 1][2], dp[pos][mask] + alvaro_wins);
                    }
                }

                if (mask == 1) {
                    if (pos + 3 < n) {
                        int alvaro_bot_count = (s_bottom[pos] == 'A') + (s_bottom[pos + 1] == 'A') + (s_bottom[pos + 2] == 'A');
                        int alvaro_bot_wins = (alvaro_bot_count >= 2) ? 1 : 0;
                        int alvaro_top_count = (s_top[pos + 1] == 'A') + (s_top[pos + 2] == 'A') + (s_top[pos + 3] == 'A');
                        int alvaro_top_wins = (alvaro_top_count >= 2) ? 1 : 0;
                        dp[pos + 3][1] = max(dp[pos + 3][1], dp[pos][mask] + alvaro_bot_wins + alvaro_top_wins);
                    }

                    if (pos + 1 < n) {
                        int alvaro_count = (s_bottom[pos] == 'A') + (s_bottom[pos + 1] == 'A') + (s_top[pos + 1] == 'A');
                        int alvaro_wins = (alvaro_count >= 2) ? 1 : 0;
                        dp[pos + 1][3] = max(dp[pos + 1][3], dp[pos][mask] + alvaro_wins);
                    }
                }

                if (mask == 2) {
                    if (pos + 3 < n) {
                        int alvaro_top_count = (s_top[pos] == 'A') + (s_top[pos + 1] == 'A') + (s_top[pos + 2] == 'A');
                        int alvaro_top_wins = (alvaro_top_count >= 2) ? 1 : 0;
                        int alvaro_bot_count = (s_bottom[pos + 1] == 'A') + (s_bottom[pos + 2] == 'A') + (s_bottom[pos + 3] == 'A');
                        int alvaro_bot_wins = (alvaro_bot_count >= 2) ? 1 : 0;
                        dp[pos + 3][2] = max(dp[pos + 3][2], dp[pos][mask] + alvaro_top_wins + alvaro_bot_wins);
                    }

                    if (pos + 1 < n) {
                        int alvaro_count = (s_top[pos] == 'A') + (s_top[pos + 1] == 'A') + (s_bottom[pos + 1] == 'A');
                        int alvaro_wins = (alvaro_count >= 2) ? 1 : 0;
                        dp[pos + 1][3] = max(dp[pos + 1][3], dp[pos][mask] + alvaro_wins);
                    }
                }
            }
        }

        int max_alvaro_wins = dp[n][0];
        cout << max_alvaro_wins << '\n';
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

#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;
using ll = long long;

const int MOD = 998244353;

int T;
string E;
int K;

vector<int> dp;
vector<bool> max_dp;
vector<vector<char>> choices;

void solveCase(int caseNum) {
    cin >> E >> K;
    int N = E.size();
    dp.assign(N + 1, 0);
    max_dp.assign(N + 1, false);
    choices.assign(N, vector<char>());

    dp[N] = 1;
    max_dp[N] = true;

    for (int i = N - 1; i >= 0; --i) {
        int maxWays = 0;
        vector<char> digits;

        if (E[i] == '?') {
            for (char ch = '1'; ch <= '9'; ++ch) {
                maxWays = (maxWays + dp[i + 1]) % MOD;
                digits.push_back(ch);
            }
        } else if (E[i] >= '1' && E[i] <= '9') {
            maxWays = (maxWays + dp[i + 1]) % MOD;
            digits.push_back(E[i]);
        }

        if (i + 1 < N) {
            if (E[i] == '?' && E[i + 1] == '?') {
                for (char ch1 = '1'; ch1 <= '2'; ++ch1) {
                    char start = '0', end = '9';
                    if (ch1 == '2') end = '6';
                    for (char ch2 = start; ch2 <= end; ++ch2) {
                        maxWays = (maxWays + dp[i + 2]) % MOD;
                        digits.push_back(ch1);
                    }
                }
            } else if (E[i] == '?' || E[i + 1] == '?') {
                for (char ch1 = (E[i] == '?' ? '1' : E[i]); ch1 <= (E[i] == '?' ? '2' : E[i]); ++ch1) {
                    char ch2 = (E[i + 1] == '?' ? '0' : E[i + 1]);
                    char end = (ch1 == '1') ? '9' : '6';
                    if (ch2 >= '0' && ch2 <= end) {
                        if (E[i + 1] == '?') {
                            for (char ch2_it = '0'; ch2_it <= end; ++ch2_it) {
                                maxWays = (maxWays + dp[i + 2]) % MOD;
                                digits.push_back(ch1);
                            }
                        } else {
                            maxWays = (maxWays + dp[i + 2]) % MOD;
                            digits.push_back(ch1);
                        }
                    }
                }
            } else {
                string num = E.substr(i, 2);
                if (num >= "10" && num <= "26") {
                    maxWays = (maxWays + dp[i + 2]) % MOD;
                    digits.push_back(E[i]);
                }
            }
        }

        dp[i] = maxWays;
        max_dp[i] = true;

        sort(digits.rbegin(), digits.rend());
        digits.erase(unique(digits.begin(), digits.end()), digits.end());
        choices[i] = digits;
    }

    string result = E;
    ll totalWays = dp[0];
    int K_remain = K;
    function<bool(int, int)> dfs = [&](int pos, int K_remain) -> bool {
        if (pos == N) return true;
        if (E[pos] != '?') {
            int len = 1;
            bool valid = false;
            if (E[pos] >= '1' && E[pos] <= '9') {
                len = 1;
                valid = true;
            }
            if (!valid && pos + 1 < N && E.substr(pos, 2) >= "10" && E.substr(pos, 2) <= "26") {
                len = 2;
                valid = true;
            }
            if (!valid) return false;
            return dfs(pos + len, K_remain);
        } else {
            for (char ch : choices[pos]) {
                result[pos] = ch;
                int len = 1;
                bool valid = false;
                if (ch >= '1' && ch <= '9') {
                    len = 1;
                    valid = true;
                }
                if (!valid && pos + 1 < N) {
                    char next_ch = (E[pos + 1] != '?' ? E[pos + 1] : '0');
                    string num = string(1, ch) + next_ch;
                    if (num >= "10" && num <= "26") {
                        len = 2;
                        valid = true;
                    }
                }
                if (!valid) continue;

                if (dfs(pos + len, K_remain)) return true;
            }
            return false;
        }
    };

    dfs(0, K_remain);

    cout << "Case #" << caseNum << ": " << result << " " << totalWays % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        solveCase(caseNum);
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

const double INF = 1e18;
const double EPS = 1e-12;

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        int N;
        cin >> N;
        double L = 0.0;
        double R = INF;
        bool impossible = false;
        for (int i = 1; i <= N; i++) {
            int Ai, Bi;
            cin >> Ai >> Bi;
            if (Bi == 0) {
                impossible = true;
            } else {
                double L_i = i / static_cast<double>(Bi);
                L = max(L, L_i);
            }
            if (Ai > 0) {
                double R_i = i / static_cast<double>(Ai);
                R = min(R, R_i);
            } else {
            }
        }
        cout << "Case #" << case_num << ": ";
        if (impossible || L - R > EPS) {
            cout << -1 << "\n";
        } else {
            cout << fixed << setprecision(10) << L << "\n";
        }
    }
    return 0;
}

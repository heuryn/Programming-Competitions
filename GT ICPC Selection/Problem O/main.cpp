#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_RADIUS = 21;
const int MAX_ANGLE = 360;

int t;
int n;
bool grid[MAX_RADIUS][MAX_ANGLE];
bool visited[MAX_RADIUS][MAX_ANGLE];

int dr[] = {1, -1, 0, 0};
int dtheta[] = {0, 0, 1, -1};
void solve() {
    cin >> n;
        memset(grid, false, sizeof(grid));
        for (int i = 0; i < n; ++i) {
            char type;
            cin >> type;
            if (type == 'C') {
                int r, theta1, theta2;
                cin >> r >> theta1 >> theta2;
                if (theta1 < 0) theta1 += 360;
                if (theta2 < 0) theta2 += 360;
                theta1 %= 360;
                theta2 %= 360;
                if (theta1 == theta2) continue;
                if (theta2 < theta1) theta2 += 360;
                for (int theta = theta1; theta <= theta2; ++theta) {
                    grid[r][theta % 360] = true;
                }
            } else if (type == 'S') {
                int r1, r2, theta;
                cin >> r1 >> r2 >> theta;
                if (theta < 0) theta += 360;
                theta %= 360;
                for (int r = r1; r <= r2; ++r) {
                    grid[r][theta] = true;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;

        for (int theta = 0; theta < MAX_ANGLE; ++theta) {
            if (!grid[1][theta]) {
                q.push({1, theta});
                visited[1][theta] = true;
            }
        }

        bool reached_outside = false;
        while (!q.empty() && !reached_outside) {
            auto [r, theta] = q.front();
            q.pop();

            if (r == 20) {
                reached_outside = true;
                break;
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int ntheta = (theta + dtheta[k] + MAX_ANGLE) % MAX_ANGLE;
                if (nr < 1 || nr > 20) continue;
                if (!grid[nr][ntheta] && !visited[nr][ntheta]) {
                    visited[nr][ntheta] = true;
                    q.push({nr, ntheta});
                }
            }
        }

        if (reached_outside) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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

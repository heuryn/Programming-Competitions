#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> color(n);
    vector<int> result(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        color[i] = (s[i] == '0') ? 1 : 0;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int current = i;
            vector<int> cycle_nodes;
            int black_count = 0;

            while (!visited[current]) {
                visited[current] = true;
                cycle_nodes.push_back(current);
                black_count += color[current];
                current = p[current];
            }

            for (int node : cycle_nodes) {
                result[node] = black_count;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

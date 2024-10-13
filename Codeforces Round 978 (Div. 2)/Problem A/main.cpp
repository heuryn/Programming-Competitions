#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n, r;
    cin >> n >> r;
    int good_rows = 0;
    int total_singles = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        good_rows += a / 2;
        total_singles += a % 2;
    }
    int rows_for_singles = r - good_rows;
    int happy_singles;
    if (rows_for_singles > total_singles) {
        happy_singles = total_singles;
    } else {
        happy_singles = rows_for_singles * 2 - total_singles;
    }
    int happy_people = 2 * good_rows + happy_singles;
    cout << happy_people << endl;
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

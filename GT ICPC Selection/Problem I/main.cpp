#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lld;

#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;

    vector<lld> p(n);
    vector<lld> x(m + 2);
    vector<pair<lld, lld> > intervals;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    x[m] = -6969696969LL;
    x[m + 1] = 6969696969LL;
    m += 2;
    sort(x.begin(), x.end());


    lld curr = 0;
    for (int i = 0; i < n; ++i) {
        lld pos = i * 100LL;

        while (x[curr] < pos)
            curr++;

        if (x[curr] == pos)
            continue;

        lld l = max(x[curr - 1], pos - (x[curr] - pos));
        lld r = min(x[curr], pos + pos - x[curr - 1]);

        if (l < r) {
            intervals.push_back(make_pair(l, p[i]));
            intervals.push_back(make_pair(r, -p[i]));
        }
    }

    sort(intervals.begin(), intervals.end());

    lld ans = 0;
    lld current = 0;
    for (int i = 0; i < int(intervals.size()); i++) {
        auto e = intervals[i];
        current += e.s;
        if (i + 1 < int(intervals.size()) && e.f == intervals[i + 1].f)
            continue;
        ans = max(ans, current);
    }

    cout << ans ;
}

int main() {
    solve();
    return 0;
}

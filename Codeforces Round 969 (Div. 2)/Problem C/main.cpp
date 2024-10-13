#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int g = gcd(a, b);
    if(g == 1) {
        cout << 0 << endl;
        return;
    }

    set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(arr[i] % g);
    }

    int minRange = g;

    for(int i = 0; i < s.size(); i++) {
        minRange = min(*s.rbegin() - *s.begin(), minRange);
        int t = *s.begin() + g;
        s.erase(*s.begin());
        s.insert(t);
    }

    cout << minRange << endl;;
}

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

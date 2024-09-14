#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_minimum_median(vector<int>& a, int x) {
    int n = a.size();
    vector<int> temp_a = a;

    for (int i = 0; i < n; ++i) {
        if (temp_a[i] >= x) {
            temp_a[i] = temp_a[i] % x;
        }
    }

    sort(temp_a.begin(), temp_a.end());

    if (n % 2 == 0) {
        return temp_a[n / 2];
    } else {
        return temp_a[(n - 1) / 2];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < q; ++i) {
            int x = queries[i];
            int min_median = find_minimum_median(a, x);
            cout << min_median << " ";
        }
        cout << endl;
    }

    return 0;
}

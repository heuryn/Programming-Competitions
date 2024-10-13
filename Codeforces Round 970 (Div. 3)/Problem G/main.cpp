#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int findMexK(int k, int gcf, int n) {
    if (n == 1) {
        if (k <= gcf) {
            return k - 1;
        } else {
            return k;
        }
    } else if (gcf == 0) {
        return k;
    } else if (gcf == 1) {
        return n + k - 1;
    } else if (k <= (n - 1) * (gcf - 1)) {
        return (k - 1) / (gcf - 1) * gcf + (k - 1) % (gcf - 1) + 1;
    } else {
        return n + k - 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int gcf = a[0];
        for (int i = 1; i < n; ++i) {
            gcf = gcf == 1 ? 1 : gcd(gcf, a[i]);
        }
        int result = findMexK(k, gcf, n);

        cout << result << endl;
    }

    return 0;
}

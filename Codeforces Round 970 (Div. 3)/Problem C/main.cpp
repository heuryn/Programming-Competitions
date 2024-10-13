#include <iostream>

using namespace std;

void solve() {
    long long l, r;
    cin >> l >> r;

    long long diff = r - l;

    long long n = 0;
    long long left = 0;
    long long right = 1000000000;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sum = mid * (mid + 1) / 2;

        if (sum <= diff) {
            n = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << n + 1<< endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

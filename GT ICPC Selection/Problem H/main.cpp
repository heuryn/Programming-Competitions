#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>

using namespace std;

vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

void solve() {
    int w, l;
    cin >> w >> l;

    int gcd1 = gcd(w - 1, l - 1);
    int gcd2 = gcd(w, l - 2);
    int gcd3 = gcd(w - 2, l);

    set<int> valid_divisors;

    vector<int> div1 = findDivisors(gcd1);
    vector<int> div2 = findDivisors(gcd2);
    vector<int> div3 = findDivisors(gcd3);

    for (auto a : div1) {
        if (a <= w && a <= l) {
            valid_divisors.insert(a);
        }
    }
    for (auto a : div2) {
        if (a <= w && a <= l) {
            valid_divisors.insert(a);
        }
    }
    for (auto a : div3) {
        if (a <= w && a <= l) {
            valid_divisors.insert(a);
        }
    }

    valid_divisors.insert(2);

    cout << valid_divisors.size() << " ";
    for (int a : valid_divisors) {
        cout << a << " ";
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

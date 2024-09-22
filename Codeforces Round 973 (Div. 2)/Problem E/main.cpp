#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;

ll compute_min_sum(vector<int>& a) {
    int n = a.size();
    int Gcd = a[0];
    for (int i = 1; i < n; ++i) {
        Gcd = gcd(Gcd, a[i]);
    }
    int min_a = *min_element(a.begin(), a.end());
    if (Gcd == min_a) {
        ll sum = (ll)min_a * n;
        return sum;
    } else {
        vector<int> b;
        b.push_back(min_a);
        auto it = find(a.begin(), a.end(), min_a);
        a.erase(it);
        bool found = false;
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (gcd(min_a, *it) == Gcd) {
                b.push_back(*it);
                a.erase(it);
                found = true;
                break;
            }
        }
        if (!found) {
            b.push_back(a.back());
            a.pop_back();
        }
        b.insert(b.end(), a.begin(), a.end());
        int curr_gcd = b[0];
        ll min_sum = curr_gcd;
        for (int i = 1; i < n; ++i) {
            curr_gcd = gcd(curr_gcd, b[i]);
            min_sum += curr_gcd;
        }
        return min_sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> a;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        a.resize(n);
        for (int j = 0; j < n; j++) cin >> a[j];
        cout << compute_min_sum(a) << endl;
    }
}

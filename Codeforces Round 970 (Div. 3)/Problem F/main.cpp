#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long mod_inverse(long long x, long long mod) {
    return mod_exp(x, mod - 2, mod);
}

long long expected_value_product() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long S = 0, S2 = 0;

    for (int i = 0; i < n; i++) {
        S = (S + arr[i]) % MOD;
        S2 = (S2 + 1LL * arr[i] * arr[i]) % MOD;
    }

    long long P = (S * S % MOD - S2 + MOD) % MOD;
    long long Q = (1LL * n * (n - 1)) % MOD;

    long long Q_inv = mod_inverse(Q, MOD);
    long long result = (P * Q_inv) % MOD;

    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long result = expected_value_product();
        cout << result << endl;
    }

    return 0;
}

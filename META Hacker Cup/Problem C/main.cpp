#include <iostream>
#include <algorithm>
#include <numeric>

typedef long long ll;
const ll MOD = 998244353;

using namespace std;

ll modinv(ll a, ll mod) {
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;
    if (mod == 1)
        return 0;
    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

void solve_case(int case_num) {
    ll W, G, L;
    cin >> W >> G >> L;
    ll p, q;
    if (L == 0) {
        p = W - G;
        q = 1;
    } else {
        p = ((W - G) % MOD) * ((2 * (L % MOD) + 1) % MOD);
        q = 1;
        ll g = gcd(p, q);
        p /= g;
        q /= g;
    }
    p %= MOD;
    q %= MOD;
    ll q_inv = modinv(q, MOD);
    ll result = (p * q_inv) % MOD;
    cout << "Case #" << case_num << ": " << result << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
        solve_case(i);
    return 0;
}

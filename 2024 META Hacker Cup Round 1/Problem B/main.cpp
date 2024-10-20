#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int count_n_subtracterizations(int n, const vector<bool>& is_prime) {
    int count = 0;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            for (int q = 2; q <= n; ++q) {
                if (is_prime[q] && p - q > 0 && is_prime[p - q]) {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    vector<int> test_cases(T);
    int max_n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> test_cases[i];
        max_n = max(max_n, test_cases[i]);
    }

    vector<bool> is_prime = sieve(max_n);

    for (int i = 0; i < T; ++i) {
        int n = test_cases[i];
        int result = count_n_subtracterizations(n, is_prime);
        cout << "Case #" << (i + 1) << ": " << result << endl;
    }

    return 0;
}
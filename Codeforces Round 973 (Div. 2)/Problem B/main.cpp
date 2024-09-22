#include <iostream>

using namespace std;

void solve() {
    long long n;
    long long last;
    long long last2;
    cin >> n;
    if(n == 2) {
        cin >> last2;
        cin >> last;
        cout << last - last2 << endl;;
        return;
    }
    long long first = 0;
    while (n > 2) {
        long long t;
        cin >> t;
        first += t;
        n--;
    }
    cin >> last2;
    cin >> last;
    cout << last - (last2 - first) << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

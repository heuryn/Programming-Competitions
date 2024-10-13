#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;

        string s = "";
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (s.length() == n) break;

            string s0 = '0' + s;
            cout << "? " << s0 << endl;
            cout.flush();

            int res;
            cin >> res;
            cnt++;

            if (res == 1) {
                s = s0;
                continue;
            }

            string s1 = '1' + s;
            cout << "? " << s1 << endl;
            cout.flush();

            cin >> res;
            cnt++;

            if (res == 1) {
                s = s1;
                continue;
            }

            while (s.length() < n) {
                s += '0';
            }
            break;
        }

        cout << "! " << s << endl;
        cout.flush();
    }

    return 0;
}

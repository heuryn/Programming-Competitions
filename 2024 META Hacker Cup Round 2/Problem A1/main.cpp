#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int T;
    fin >> T;

    vector<long long> peaks;

    for (int d = 1; d <= 9; d++) {
        int max_k = 9 - d;
        for (int k = 0; k <= max_k; k++) {
            vector<int> digits_inc;
            for (int i = 0; i <= k; i++) {
                digits_inc.push_back(d + i);
            }
            vector<int> digits_dec = digits_inc;
            digits_dec.pop_back();
            reverse(digits_dec.begin(), digits_dec.end());
            vector<int> peak_digits = digits_inc;
            peak_digits.insert(peak_digits.end(), digits_dec.begin(), digits_dec.end());
            long long peak_num = 0;
            for (int digit : peak_digits) {
                peak_num = peak_num * 10 + digit;
            }
            peaks.push_back(peak_num);
        }
    }

    sort(peaks.begin(), peaks.end());

    for (int t = 1; t <= T; t++) {
        string A_str, B_str, M_str;
        fin >> A_str >> B_str >> M_str;

        long long A = stoll(A_str);
        long long B = stoll(B_str);
        long long M = stoll(M_str);

        auto lower = lower_bound(peaks.begin(), peaks.end(), A);
        auto upper = upper_bound(peaks.begin(), peaks.end(), B);

        int count = 0;
        for (auto it = lower; it != upper; it++) {
            if (*it % M == 0) {
                count++;
            }
        }
        fout << "Case #" << t << ": " << count << endl;
    }

    return 0;
}

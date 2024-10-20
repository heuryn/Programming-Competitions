#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long ull;

void generate_number(int pos, int total_length, int last_digit, ull number_so_far, const string& state, int M, ull limit, vector<ull>& result) {
    if (pos > total_length) {
        if (number_so_far <= limit) {
            result.push_back(number_so_far);
        }
        return;
    }

    int middle_pos = (total_length + 1) / 2;

    if (pos == middle_pos) {
        if (state == "increasing" && M < last_digit) {
            return;
        }
        ull new_number = number_so_far * 10 + M;
        generate_number(pos + 1, total_length, M, new_number, "decreasing", M, limit, result);
    } else if (state == "increasing") {
        for (int digit = last_digit; digit <= 9; digit++) {
            if (digit == M || digit == 0) continue;
            ull new_number = number_so_far * 10 + digit;
            generate_number(pos + 1, total_length, digit, new_number, "increasing", M, limit, result);
        }
    } else if (state == "decreasing") {
        for (int digit = last_digit; digit >= 1; digit--) {
            if (digit == M || digit == 0) continue;
            ull new_number = number_so_far * 10 + digit;
            generate_number(pos + 1, total_length, digit, new_number, "decreasing", M, limit, result);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ull limit = 1000000000000000000ULL;
    vector<ull> mountain_numbers;

    for (int L = 1; L <= 19; L += 2) {
        int k = (L - 1) / 2;
        int total_length = L;
        int middle_pos = k + 1;
        for (int M = 1; M <= 9; M++) {
            if (k == 0) {
                mountain_numbers.push_back(M);
            } else {
                for (int first_digit = 1; first_digit <= 9; first_digit++) {
                    if (first_digit == M || first_digit == 0) continue;
                    ull number_so_far = first_digit;
                    int last_digit = first_digit;
                    int pos = 2;
                    string state = "increasing";
                    generate_number(pos, total_length, last_digit, number_so_far, state, M, limit, mountain_numbers);
                }
            }
        }
    }

    sort(mountain_numbers.begin(), mountain_numbers.end());

    int T;
    fin >> T;

    for (int t = 1; t <= T; t++) {
        ull A, B, M;
        fin >> A >> B >> M;

        auto lower = lower_bound(mountain_numbers.begin(), mountain_numbers.end(), A);
        auto upper = upper_bound(mountain_numbers.begin(), mountain_numbers.end(), B);

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

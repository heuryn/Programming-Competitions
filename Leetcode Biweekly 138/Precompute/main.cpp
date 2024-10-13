#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canFormKPalindromic(int num, int k, int n) {
        string s = to_string(num);

        if (s.length() != n) return false;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        string first_half = "";
        char middle_char = 0;
        int odd_count = 0;

        for (auto &entry : freq) {
            if (entry.second % 2 != 0) {
                odd_count++;
                middle_char = entry.first;
            }
            first_half += string(entry.second / 2, entry.first);
        }

        if (n % 2 == 0) {
            if (odd_count > 0) return false;
        } else {
            if (odd_count > 1) return false;
        }

        sort(first_half.begin(), first_half.end());

        do {
            string full_palindrome = first_half;
            if (n % 2 != 0) {
                full_palindrome += middle_char;
            }
            if(first_half[0] == '0') {
                continue;
            }
            full_palindrome += string(first_half.rbegin(), first_half.rend());

            int possible_palindrome = stoi(full_palindrome);
            if (possible_palindrome % k == 0) {
                return true;
            }
        } while (next_permutation(first_half.begin(), first_half.end()));

        return false;
    }

    long long countGoodIntegers(int n, int k) {
        int start = pow(10, n - 1);
        int end = pow(10, n);
        long long count = 0;

        for (int num = start; num < end; num++) {
            if (canFormKPalindromic(num, k, n)) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;

    for (int n = 1; n <= 10; ++n) {
        for (int k = 1; k <= 9; ++k) {
            long long goodCount = solution.countGoodIntegers(n, k);
            cout << "Number of good integers for n = " << n << ", k = " << k << " is: " << goodCount << endl;
        }
    }

    return 0;
}

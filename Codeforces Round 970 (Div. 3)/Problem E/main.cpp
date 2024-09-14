#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int minOps;
    if (n < 2) {
        cout << 1 << endl;
        return;
    }

    unordered_map<char, int> evenFreq, oddFreq;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenFreq[s[i]]++;
        } else {
            oddFreq[s[i]]++;
        }
    }

    char maxEvenChar = 0, maxOddChar = 0;
    int maxEvenFreq = 0, maxOddFreq = 0;

    for (const auto& pair : evenFreq) {
        if (pair.second > maxEvenFreq) {
            maxEvenFreq = pair.second;
            maxEvenChar = pair.first;
        }
    }

    for (const auto& pair : oddFreq) {
        if (pair.second > maxOddFreq) {
            maxOddFreq = pair.second;
            maxOddChar = pair.first;
        }
    }

    if(n % 2 == 0) {
        minOps = (n / 2 - maxEvenFreq) + ((n + 1) / 2 - maxOddFreq);
    } else {
        minOps = n;
        for (int i = 0; i < n; i++) {
            string modified = s.substr(0, i) + s.substr(i + 1);

            unordered_map<char, int> evenFreqModified, oddFreqModified;

            for (int j = 0; j < modified.length(); j++) {
                if (j % 2 == 0) {
                    evenFreqModified[modified[j]]++;
                } else {
                    oddFreqModified[modified[j]]++;
                }
            }

            int maxEvenFreqModified = 0, maxOddFreqModified = 0;

            for (const auto& pair : evenFreqModified) {
                maxEvenFreqModified = max(maxEvenFreqModified, pair.second);
            }

            for (const auto& pair : oddFreqModified) {
                maxOddFreqModified = max(maxOddFreqModified, pair.second);
            }

            int replaceOpsModified = (modified.length() / 2 - maxEvenFreqModified) + ((modified.length() + 1) / 2 - maxOddFreqModified);
            minOps = min(minOps, replaceOpsModified + 1);
        }
    }

    cout << minOps << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}

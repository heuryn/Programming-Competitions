#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

string reorderString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for (auto& entry : freq) {
        maxHeap.push({entry.second, entry.first});
    }

    string result = "";
    pair<int, char> prev = {0, '#'};

    while (!maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();

        result += current.second;

        if (prev.first > 0) {
            maxHeap.push(prev);
        } else if (current.first > 1){
            maxHeap.push({current.first - 1, current.second});
        } else {
            prev = {current.first - 1, current.second};
        }
    }

    return result;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << reorderString(s) << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

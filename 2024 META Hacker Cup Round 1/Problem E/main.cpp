#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#define MOD 998244353

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int wildcardBranches;
    TrieNode() : wildcardBranches(0) {}
};

class Trie {
public:
    TrieNode* root;
    int nodeCount;

    Trie() {
        root = new TrieNode();
        nodeCount = 1; // root node
    }

    void insert(const string& s) {
        TrieNode* current = root;
        for (char ch : s) {
            if (ch == '?') {
                int wildcardNewNodes = 26 - current->children.size();
                nodeCount = (nodeCount + wildcardNewNodes) % MOD;
                current->wildcardBranches = (current->wildcardBranches + wildcardNewNodes) % MOD;
            } else {
                if (current->children.find(ch) == current->children.end()) {
                    current->children[ch] = new TrieNode();
                    nodeCount = (nodeCount + 1) % MOD;
                }
                current = current->children[ch];
            }
        }
    }
};

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<string> strings(N);
        for (int i = 0; i < N; ++i) {
            cin >> strings[i];
        }

        Trie trie;
        for (const string& s : strings) {
            trie.insert(s);
        }

        cout << "Case #" << t << ": " << trie.nodeCount << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
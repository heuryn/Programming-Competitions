#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reduceString(const string& s) {
    stack<char> stack;
    for (char c : s) {
        if (!stack.empty() && stack.top() == c) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }
    string res;
    while(!stack.empty()) {
        res = stack.top() + res;
        stack.pop();
    }
    return res;
}

void solve() {
    string u, v;
    cin >> u >> v;

    int countA_u = 0, countB_u = 0, countC_u = 0;
    int countA_v = 0, countB_v = 0, countC_v = 0;

    for (char c : u) {
        if (c == 'A') countA_u++;
        else if (c == 'B') countB_u++;
        else if (c == 'C') countC_u++;
    }
    for (char c : v) {
        if (c == 'A') countA_v++;
        else if (c == 'B') countB_v++;
        else if (c == 'C') countC_v++;
    }

    if (countA_u % 2 != countA_v % 2 || countB_u % 2 != countB_v % 2 || countC_u % 2 != countC_v % 2) {
        cout << "NO\n";
        return;
    }

    string u_noB, v_noB;
    for (char c : u) {
        if (c != 'B') u_noB += c;
    }
    for (char c : v) {
        if (c != 'B') v_noB += c;
    }

    string reduced_u = reduceString(u_noB);
    string reduced_v = reduceString(v_noB);

    if (reduced_u == reduced_v) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

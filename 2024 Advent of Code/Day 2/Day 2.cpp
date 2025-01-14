#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
------
Part 1
------
int main() {
    ifstream cin("txt.in");
    ofstream cout("txt.out");
    string s;
    int ans = 0;
    while(getline(cin, s)) {
        ans++;
        vector<int> lvl;
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                lvl.push_back(num);
                num = 0;
            } else {
                num = num * 10 + s[i] - '0';
            }
        }
        if (!s.empty()) {
            lvl.push_back(num);
        }

        if (lvl[0] < lvl[1] && lvl[1] - lvl[0] <= 3) {
            for (int i = 1; i < lvl.size(); i++) {
                if (lvl[i] <= lvl[i - 1] || lvl[i] - lvl[i - 1] > 3) {
                    ans--;
                    for(auto &num : lvl) {
                        cout << num << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
        } else if (lvl[0] > lvl[1] && lvl[0] - lvl[1] <= 3) {
            for (int i = 1; i < lvl.size(); i++) {
                if (lvl[i] >= lvl[i - 1] || lvl[i - 1] - lvl[i] > 3) {
                    ans--;
                    for(auto &num : lvl) {
                        cout << num << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
        } else {
            ans--;
            for(auto &num : lvl) {
                cout << num << " ";
            }
            cout << "\n";
        }
    }
    cout << ans;
}
*/


/*
------
Part 2
------
*/

bool isSafe(const vector<int>& lvl) {
    if (lvl[0] < lvl[1] && lvl[1] - lvl[0] <= 3) {
        for (int i = 1; i < lvl.size(); i++) {
            if (lvl[i] <= lvl[i - 1] || lvl[i] - lvl[i - 1] > 3) {
                return false;
            }
        }
    } else if (lvl[0] > lvl[1] && lvl[0] - lvl[1] <= 3) {
        for (int i = 1; i < lvl.size(); i++) {
            if (lvl[i] >= lvl[i - 1] || lvl[i - 1] - lvl[i] > 3) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

int main() {
    ifstream cin("txt.in");
    ofstream cout("txt.out");
    string s;
    int ans = 0;
    while(getline(cin, s)) {
        vector<int> lvl;
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                lvl.push_back(num);
                num = 0;
            } else {
                num = num * 10 + s[i] - '0';
            }
        }
        if (!s.empty()) {
            lvl.push_back(num);
        }

        if (isSafe(lvl)) {
            ans++;
        } else {
            bool canFix = false;
            for (int i = 0; i < (int)lvl.size(); i++) {
                vector<int> modified;
                for (int j = 0; j < (int)lvl.size(); j++) {
                    if (j != i) modified.push_back(lvl[j]);
                }
                if (isSafe(modified)) {
                    canFix = true;
                    break;
                }
            }
            if (canFix) ans++;
        }
    }
    cout << ans;
}
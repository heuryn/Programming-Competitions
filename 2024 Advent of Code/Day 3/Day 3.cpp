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
    vector<int> list1;
    vector<int> list2;
    int a, b;
    while(cin >> a) {
        cin >> b;
        list1.push_back(a);
        list2.push_back(b);
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int ans = 0;
    for(int i = 0; i < list1.size(); i++) {
        ans += abs(list1[i] - list2[i]);
    }
    cout << ans;
}
*/

/*
------
Part 2
------

int main() {
    ifstream cin("txt.in");
    ofstream cout("txt.out");
    vector<int> list1;
    unordered_map<int, int> map2;
    int a, b;
    while(cin >> a) {
        cin >> b;
        list1.push_back(a);
        map2[b]++;
    }
    sort(list1.begin(), list1.end());

    int ans = 0;
    for(int i = 0; i < list1.size(); i++) {
        ans += list1[i] * map2[list1[i]];
    }
    cout << ans;
}
*/
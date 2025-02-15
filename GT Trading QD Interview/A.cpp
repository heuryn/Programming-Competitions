#include <iostream>
#include <unordered_set>

using namespace std;

struct Process{
    int t;
    int id;
    int l;
    int m;
    unordered_set<int> p;
    int k;
    vector<int> y;
    unordered_set<int> d;
};

int main() {
    int n;
    cin >> n;
    vector<Process> processes (n + 1);

    for(int i = 1; i <= n; i++) {
        int l, m, k, t;
        cin >> l >> m;
        unordered_set<int> p;
        for (int j = 0; j < m; j++) {
            cin >> t;
            p.insert(t);
        }
        cin >> k;
        vector<int> y;
        if (k > 0) {
            cin >> y[k - 1];
        }
    
        for (int j = k - 2; j >= 0; j--) {
            cin >> t;
            y[j] = t - y[j + 1];
        }
        processes.push_back({0, i, l, m, p, k, y, {}});
    }

    for(int i = 1; i <= n; i++) {
        for (auto t : processes[i].p) {
            processes[t].d.insert(i);
        }
    }

    priority_queue<Process> q;
    for (auto process : processes) {
        if (process.m == 0) {
            q.push(process);
        }
    }

    int currt = 0;
    while(!q.empty()) {
        Process pro = q.top();
        q.pop();
        if (pro.l == 0) {
            for (auto i : pro.d) {
                processes[i].m--;
                processes[i].p.erase(pro.id);
                if (processes[i].m == 0) {
                    q.push(processes[i]);
                }
            }
        } else {
            pro.t = currt + pro.y[pro.k];
            pro.k--;
            pro.l -= pro.y[pro.k];
        }
        currt++;
    }
}
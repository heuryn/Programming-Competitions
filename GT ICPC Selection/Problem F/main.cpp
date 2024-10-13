#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct SegmentTreeMin {
    int size;
    vector<pair<int, int>> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, {INF, -1});
    }

    void build(const vector<int>& values) {
        for (int i = 0; i < values.size(); ++i) {
            tree[size + i] = {values[i], i};
        }
        for (int i = size - 1; i >= 1; --i) {
            if (tree[2 * i].first <= tree[2 * i + 1].first)
                tree[i] = tree[2 * i];
            else
                tree[i] = tree[2 * i + 1];
        }
    }

    void update(int pos, int value) {
        pos += size;
        tree[pos].first = value;
        while (pos > 1) {
            pos >>= 1;
            if (tree[2 * pos].first <= tree[2 * pos + 1].first)
                tree[pos] = tree[2 * pos];
            else
                tree[pos] = tree[2 * pos + 1];
        }
    }

    pair<int, int> query(int l, int r, int i, int tl, int tr, int threshold) {
        if (l > r) return {INF, -1};
        if (l == tl && r == tr) {
            if (tree[i].first <= threshold)
                return tree[i];
            else
                return {INF, -1};
        }
        int tm = (tl + tr) >> 1;
        auto left = query(l, min(r, tm), 2 * i, tl, tm, threshold);
        if (left.first <= threshold) return left;
        return query(max(l, tm + 1), r, 2 * i + 1, tm + 1, tr, threshold);
    }

    int queryIndex(int l, int r, int threshold) {
        auto res = query(l, r, 1, 0, size - 1, threshold);
        return res.second;
    }
};

struct SegmentTreeMax {
    int size;
    vector<pair<int, int>> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, {-INF, -1});
    }

    void build(const vector<int>& values) {
        for (int i = 0; i < values.size(); ++i) {
            tree[size + i] = {values[i], i};
        }
        for (int i = size - 1; i >= 1; --i) {
            if (tree[2 * i].first >= tree[2 * i + 1].first)
                tree[i] = tree[2 * i];
            else
                tree[i] = tree[2 * i + 1];
        }
    }

    void update(int pos, int value) {
        pos += size;
        tree[pos].first = value;
        while (pos > 1) {
            pos >>= 1;
            if (tree[2 * pos].first >= tree[2 * pos + 1].first)
                tree[pos] = tree[2 * pos];
            else
                tree[pos] = tree[2 * pos + 1];
        }
    }

    pair<int, int> query(int l, int r, int i, int tl, int tr, int threshold) {
        if (l > r) return {-INF, -1};
        if (l == tl && r == tr) {
            if (tree[i].first >= threshold)
                return tree[i];
            else
                return {-INF, -1};
        }
        int tm = (tl + tr) >> 1;
        auto right = query(max(l, tm + 1), r, 2 * i + 1, tm + 1, tr, threshold);
        if (right.first >= threshold) return right;
        return query(l, min(r, tm), 2 * i, tl, tm, threshold);
    }

    int queryIndex(int l, int r, int threshold) {
        auto res = query(l, r, 1, 0, size - 1, threshold);
        return res.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        --a; --b;

        vector<int> pi(n);
        for (int i = 0; i < n; ++i) {
            cin >> pi[i];
        }

        vector<int> lj(n), rj(n);
        for (int j = 0; j < n; ++j) {
            lj[j] = j - pi[j];
            rj[j] = j + pi[j];
        }

        SegmentTreeMin treeMin;
        treeMin.init(n);
        treeMin.build(lj);

        SegmentTreeMax treeMax;
        treeMax.init(n);
        treeMax.build(rj);

        vector<bool> visited(n, false);
        vector<int> dist(n, INF);
        queue<int> q;
        q.push(a);
        visited[a] = true;
        dist[a] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int r = min(n - 1, i + pi[i]);
            while (true) {
                int idx = treeMin.queryIndex(i + 1, r, i);
                if (idx == -1) break;
                if (!visited[idx]) {
                    visited[idx] = true;
                    dist[idx] = dist[i] + 1;
                    q.push(idx);
                }
                treeMin.update(idx, INF);
                treeMax.update(idx, -INF);
            }

            int l = max(0, i - pi[i]);
            while (true) {
                int idx = treeMax.queryIndex(l, i - 1, i);
                if (idx == -1) break;
                if (!visited[idx]) {
                    visited[idx] = true;
                    dist[idx] = dist[i] + 1;
                    q.push(idx);
                }
                treeMin.update(idx, INF);
                treeMax.update(idx, -INF);
            }
        }

        cout << dist[b] << '\n';
    }

    return 0;
}

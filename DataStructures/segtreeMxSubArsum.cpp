#include <bits/stdc++.h>
using namespace std;
template<typename T, typename R>
struct SegmentTree {
    int maxSize;
    int height;
    int neutral;
    const long long INF = -2e9;
    int elements;
    struct node {
        R prefsum;
        R sufsum;
        R totsum;
        R subarsum;
    };
    vector<node> nodes;
    SegmentTree(int n, int assign_v) {
        height = ceil(log2(n));
        maxSize = 2 * (int)pow(2, height) - 1;
        nodes.resize(maxSize);
        elements = n;
        neutral = assign_v;
        constructST(0, n - 1, 0);
    }
    SegmentTree(vector<T>& ar) {
        height = ceil(log2(ar.size()));
        maxSize = 2 * (int)pow(2, height) - 1;
        nodes.resize(maxSize);
        elements = ar.size();
        constructST(this->nodes, ar, 0, ar.size() - 1, 0);
    }
    void constructST(int l, int r, int pos) {
        if (l == r) {
            nodes[pos].prefsum = nodes[pos].sufsum = nodes[pos].totsum = nodes[pos].subarsum = neutral;
            return;
        }
        int mid = (l + r) / 2;
        constructST(l, mid, 2 * pos + 1);
        constructST(mid + 1, r, 2 * pos + 2);
        nodes[pos] = merge(nodes[2 * pos + 1], nodes[2 * pos + 2]);
    }
    void constructST(vector<node>& dest, vector<T>& src, int l, int r, int pos) {
        if (l == r) {
            dest[pos].prefsum = dest[pos].sufsum = dest[pos].totsum = dest[pos].subarsum = src[l];
            return;
        }
        int mid = (l + r) / 2;
        constructST(dest, src, l, mid, 2 * pos + 1);
        constructST(dest, src, mid + 1, r, 2 * pos + 2);
        dest[pos] = merge(dest[2 * pos + 1], dest[2 * pos + 2]);
    }
    node merge(node a, node b) {
        node c;
        c.prefsum = max(a.prefsum, a.totsum + b.prefsum);
        c.sufsum = max(b.sufsum, b.totsum + a.sufsum);
        c.subarsum = max({ a.subarsum, b.subarsum, a.sufsum + b.prefsum });
        c.totsum = a.totsum + b.totsum;
        return c;
    }
    void modif(int i, int l, int r, int pos, int val) {
        if (l > pos || r < pos)
            return;

        if (l == pos && r == pos) {
            nodes[i].prefsum = nodes[i].sufsum = nodes[i].totsum = nodes[i].subarsum = val;
            return;
        }
        
        int mid = (l + r) / 2;
        modif(2 * i + 1, l, mid, pos, val);
        modif(2 * i + 2, mid + 1, r, pos, val);
        nodes[i] = merge(nodes[2 * i + 1], nodes[2 * i + 2]);
    }

    void modif(int pos, int val) {
        modif(0, 0, elements - 1, pos, val);
    }
};

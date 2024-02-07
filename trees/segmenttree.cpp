#include <bits/stdc++.h>
#define maxN 2000001
using namespace std;

int a[maxN], n, q;
long long t[4 * maxN];

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    t[id] = t[2 * id] + t[2 * id + 1];
}

long long get(int id, int l, int r, int u, int v)
{
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return t[id];

    int mid = (l + r) / 2;
    long long t1 = get(2 * id, l, mid, u, v);
    long long t2 = get(2 * id + 1, mid + 1, r, u, v);
    return t1 + t2;
}

void update(int id, int l, int r, int pos, int val)
{
    if (r < pos || pos < l) return;
    if (l == r)
    {
        t[id] = val;
        a[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);

    t[id] = t[2 * id] + t[2 * id + 1];
}

void ReadData()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int type, pos, val, u, v;
        cin >> type;
        if (type == 1)
        {
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else
        {
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ReadData();
    return 0;
}

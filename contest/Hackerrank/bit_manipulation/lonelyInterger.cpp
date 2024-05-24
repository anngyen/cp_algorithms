/*
    De giai quyet bai nay trong O(n), ta se su dung tinh chat cua phep XOR
    - Mot so ^ voi chinh no bang 0
    - Mot so ^ voi 0 bang chinh no
    Khi do, tat ca cap so bang nhau se co gia tri ^ bang 0, so con lai chinh la ket qua
*/

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e2 + 2;

int a[maxN], n;

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans ^= a[i];
    cout << ans << '\n';
    return 0;
}

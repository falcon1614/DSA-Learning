
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int m;
    cin >> m;

    vector<long long> usb, ps2;
    for (int i = 0; i < m; i++) {
        long long val;
        string type;
        cin >> val >> type;
        if (type == "USB")
            usb.push_back(val);
        else
            ps2.push_back(val);
    }

    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());

    long long total_cost = 0;
    long long total_used = 0;

    int u = 0, p = 0;

    // USB-only computers
    while (u < a && u < (int)usb.size()) {
        total_cost += usb[u++];
        total_used++;
    }

    // PS/2-only computers
    while (p < b && p < (int)ps2.size()) {
        total_cost += ps2[p++];
        total_used++;
    }

    // Hybrid computers
    vector<long long> leftover;
    for (int i = u; i < (int)usb.size(); i++) leftover.push_back(usb[i]);
    for (int i = p; i < (int)ps2.size(); i++) leftover.push_back(ps2[i]);

    sort(leftover.begin(), leftover.end());

    for (int i = 0; i < c && i < (int)leftover.size(); i++) {
        total_cost += leftover[i];
        total_used++;
    }

    cout << total_used << " " << total_cost << "\n";
    return 0;
}

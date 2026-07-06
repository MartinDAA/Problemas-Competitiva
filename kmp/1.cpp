#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using ll = long long;

const bool HAS_CASE = false;

vector<int> prefix_function(const string& s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string s, t;
    cin >> s >> t;

    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }
    int m = t.size();
    vector<int> pi = prefix_function(t);
    int overlap = pi[m - 1];

    string ans;

    auto place = [&](char c) -> bool {
        if (c == '0' && cnt0 > 0) { ans.push_back('0'); cnt0--; return true; }
        if (c == '1' && cnt1 > 0) { ans.push_back('1'); cnt1--; return true; }
        return false;
    };

    for (char c : t) {
        if (!place(c)) {
            ans.append(cnt0, '0');
            ans.append(cnt1, '1');
            cout << ans << '\n';
            return;
        }
    }
    while (cnt0 + cnt1 > 0) {
        for (int i = overlap; i < m; i++) {
            if (!place(t[i])) {
                ans.append(cnt0, '0');
                ans.append(cnt1, '1');
                cout << ans << '\n';
                return;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    int t = 1;
    if (HAS_CASE) cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
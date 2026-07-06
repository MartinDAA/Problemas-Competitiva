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
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi = prefix_function(s);

    vector<int> cnt(n + 1, 1);
    
    for (int i = n - 1; i >= 0; i--) {
        if (pi[i] > 0) {
            cnt[pi[i] - 1] += cnt[i];
        }
    }

    vector<pair<int, int>> ans;
    int len = pi[n - 1];
    while (len > 0) {
        ans.push_back({len, cnt[len - 1]});
        len = pi[len - 1];
    }
    ans.push_back({n, 1});

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto [l, c] : ans) {
        cout << l << " " << c << "\n";
    }
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
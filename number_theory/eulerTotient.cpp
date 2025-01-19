#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define loop(s, n) for (ll i = s; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vch vector<char>
vector<pair<ll, ll>> spff(vll &s, ll n) {
    vector<pair<ll, ll>> ans;
    while (n != 1) {
        ll count = 0;
        ll x = s[n];
        while (s[n] == x) {
            count++;
            n = n / s[n];
        }
        ans.push_back({x, count});
    }
    return ans;
}

int main() {
    ll n = 18;
    vll spf(n + 1, 1e9);
    spf[0] = spf[1] = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (spf[i] == 1e9) {
            spf[i] = i;
            for (ll j = i * i; j <= n; j = j + i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
    vector<pair<ll, ll>> ans = spff(spf, 18);
    for (auto it : ans) {
        n = n - (n / it.first);
    }
    cout << n << nl;
    return 0;
}
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
ll binary_exponentiation(ll a, ll p) {
    ll b = p - 2;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b = b >> 1;
    }
    return res;
}
int main() {
    ll n = 1LL * 1e9 + 7;
    cout << binary_exponentiation(2, n) << nl;  // multiplicative inverse
    return 0;
}
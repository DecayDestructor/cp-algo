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
    ll n = 1000;
    vll fact(n + 1);
    ll p = (ll)1e9 + 7;
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= n; i++) {
        fact[i] = i * fact[i - 1] % p;
    }
    vll inverseFact(n + 1);
    inverseFact[n] = binary_exponentiation(fact[n], p);
    for (ll i = n - 1; i >= 0; i--) {
        inverseFact[i] = (i + 1) * inverseFact[i + 1] % p;
    }
    for (ll i = 0; i <= n; i++) {
        cout << "Factorial is " << fact[i] << " and inverse fact is " << inverseFact[i] << nl;
    }
    return 0;
}
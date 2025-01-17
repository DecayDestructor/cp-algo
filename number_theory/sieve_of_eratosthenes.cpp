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
int main() {
    ll n;
    cin >> n;
    vector<bool> isPrime(n + 1, false);
    isPrime[0] = isPrime[1] = true;
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    return 0;
}
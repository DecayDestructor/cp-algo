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
    vll arr;
    for (ll i = 1; i * i <= n; i++) {
        if (!(n % i)) {
            arr.push_back(i);
            if (i * i != n) {
                arr.push_back(n / i);
            }
        }
    }
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << nl;
    return 0;
}
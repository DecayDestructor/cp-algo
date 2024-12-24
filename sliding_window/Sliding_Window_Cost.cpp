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
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void debug(auto &arr) {
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << nl;
}
template <typename T>
void outputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << nl;
    }
}
bool RSORT(ll a, ll b) {
    return a > b;
}
template <typename T>
vector<T> factorization(int n) {
    vector<T> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
// Prime Factorization
void primeFactorisation(ll n, map<ll, ll> &mpp) {
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }
    if (n != 1)
        mpp[n]++;
}
// Sieve of Eratosthenes
vector<ll> sieveOfEratosthenes(int n) {
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;  // 0 and 1 are not primes
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;  // Mark multiples of i as non-prime
            }
        }
    }
    return sieve;  // Return the sieve vector
}
// Sum of first n natural numbers
ll sumOfNaturalNumbers(ll n) {
    return (n * (n + 1)) / 2;  // Formula to calculate the sum
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited) {
    return row < n && col < m && row >= 0 && col >= 0 && !visited[row][col];
}
// Binary Exponentiation
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void balance(multiset<ll> &low, multiset<ll> &high, ll &leftSum, ll &rightSum) {
    if (low.size() < high.size()) {  // the case where lowm multiset has x elements and right one has x+1, so we transfer the first element from right to left to maintain the order of the elements
        low.insert(*high.begin());
        high.erase(high.begin());
        leftSum += *low.rbegin();
        rightSum -= *low.rbegin();
    }
    // the case where left one has x+2 and right one has x elements, this case arises when insertion happens when left had x+1 and right had x elements, so we transfer largest element from left to right, which becomes the smallest element in the right one, maintaining the order of the overall array.
    if (high.size() + 1 < low.size()) {
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
        leftSum -= *high.begin();
        rightSum += *high.begin();
    }
}
void medianArray(vll &ans, vll &arr, ll k, ll &leftSum, ll &rightSum) {
    multiset<ll> low, high;
    ll n = arr.size();
    for (ll i = 0; i < n; i++) {
        if (low.empty() || arr[i] <= *low.rbegin()) {
            low.insert(arr[i]);
            leftSum += arr[i];
        } else {
            high.insert(arr[i]);
            rightSum += arr[i];
        }
        balance(low, high, leftSum, rightSum);

        if (i >= k) {
            ll remove = arr[i - k];
            if (remove <= *low.rbegin()) {
                low.erase(low.find(remove));
                leftSum -= remove;
            }

            else {
                high.erase(high.find(remove));
                rightSum -= remove;
            }
            balance(low, high, leftSum, rightSum);
        }
        if (i >= k - 1) {
            ll median = *low.rbegin();
            // cout << median << " " << " " << leftSum << " " << rightSum << " ";
            ans.push_back((low.size() * median - leftSum) + rightSum - (high.size() * median));
        }
        // cout << nl;
    }
    return;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vll arr(n);
    for (auto &it : arr) {
        cin >> it;
    }
    // debug(arr);
    ll leftSum = 0, rightSum = 0;
    vll ans;
    medianArray(ans, arr, k, leftSum, rightSum);
    ll curr = 0;
    // vll cost(ans.size());
    debug(ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
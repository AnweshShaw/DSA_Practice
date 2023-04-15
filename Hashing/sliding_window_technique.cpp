#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    int s = 0, ans = INT_MAX;
    rep(i, 0, k)
    {
        s += a[i];
    }
    ans = min(ans, s);
    rep(i, 1, n - k - 1)
    {
        s -= a[i - 1];
        s += a[i + k - 1];
        ans = min(ans, s);
    }
    cout << ans << endl;
    return 0;
}
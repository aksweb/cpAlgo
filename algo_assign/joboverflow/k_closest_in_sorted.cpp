    // TSETEN RGIPT
    // ΣDAY
    #include <bits/stdc++.h>
    #define ll long long int
    using namespace std;
    #define ll long long int
    #define br << endl
    #define rep(i, n) for (ll i = 0; i < n; i++)
    #define repi(i, n) for (ll i = 1; i <= n; i++)
    #define repii(i, n) for (ll i = 1; i < n; i++)
    #define gcd __gcd
    const ll MOD = 1e9 + 7;

    // question rd k l
    // constraits
    // consider tc
    // isse achha approach nhi melega bhai.

    // Ye kab tk likhoge
    ll gcd(ll a, ll b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
    ll lcm(ll a, ll b)
    {
        return a * (b / gcd(a, b));
    }

    bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    }

    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
    // Code Begins Here
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

    int pred(ll m, ll x)
    {
        if (m < x)
            return 0;
        else
            return 1;
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];
        ll k, x;
        cin >> k >> x;
        // cout << k << " " << x br;
        ll l = -1, r = n;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (pred(a[m], x) == 0)
                l = m;
            else
                r = m;
        }

        ll pos = r;
        ll p1 = r - 1, p2 = r + 1;
        vector<ll> ans;
        while ((p1 >= 0 || p2 < n) && k > 0)
        {
            if (k >= 2)
            {
                if (p1 >= 0 && p2 < n)
                {
                    ans.push_back(a[p1]);
                    ans.push_back(a[p2]);
                    p1--;
                    p2++;
                    k -= 2;
                }
                else if (p1 < 0)
                {
                    while (k-- && p2 < n)
                    {
                        ans.push_back(a[p2]);
                        p2++;
                    }
                }
                else
                {
                    while (k-- && p1 >= 0)
                    {
                        ans.push_back(a[p1]);
                        p1--;
                    }
                }
            }
            else
            {
                if (p1 >= 0 && p2 < n)
                {
                    ans.push_back(min(a[p1], a[p2]));
                    k--;
                }
                else if (p1 < 0)
                {

                    ans.push_back(a[p2]);
                    p2++;
                    k--;
                }
                else
                {

                    ans.push_back(a[p1]);
                    p1--;
                    k--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        rep(i, ans.size()) cout << ans[i] << " ";
        return 0;
    }
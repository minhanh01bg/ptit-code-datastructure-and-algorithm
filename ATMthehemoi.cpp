#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define endl      <<endl
#define pii       pair<int, int>
#define MIN       INT_MIN
#define MAX       LLONG_MAX
#define m         %u

#define res(x)          resize(x)
#define sz()            size()
#define er              erase
#define pb              push_back
#define eleV            vector <ele>
#define all(vec)        vec.begin(), vec.end()
#define rs(A,x)         memset(A, x, sizeof(A))
#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define pq(x)           priority_queue<x>
#define neg_pq(x)       priority_queue<x, vector<x>, greater<x>>
#define vec2(C,x,y,tp)  vector<vector<tp> > C(x, vector<tp> (y, 0))

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

// --------------------------------------------------------- //

ll a[64], w, c, s2, s3;

void reset();
void getip();

void pprc()
{
    FOR(i, 0, 16)
    {
        ll j = 4 * i, z = pow(10, i);
        a[j]     = z * 1000;
        a[j + 1] = z * 2000;
        a[j + 2] = z * 3000;
        a[j + 3] = z * 5000;
    }
}

ll power(ll a, ll b)
{
	if (b == 0) return 1;
	if (b == 1) return a;
	ll x = power(a, b / 2);
	return (b & 1) ?  x * x * a : x * x;
}	

void nWays(string s)
{
    int j = s.sz() - 3 - c;
    FOR(i, j, s.sz())
        if (s[i] == '4' || s[i] == '6')
            s2++;
        else if (s[i] == '9')
            s3++;
    
    j--;
    if (j > 0 && s[j - 1] != '0')
    {
        if (s[j] == '4' || s[j] == '9')
            s3++;
        if (s[j] == '1' || s[j] == '6')
            s2++;
    }
    else
    {
        if (s[j] == '4' || s[j] == '6')
            s2++;
        else if (s[j] == '9')
            s3++;
    }
}

void solve()
{
    ll index = c * 4 + 3, cnt = 0, way = 1;
    string s = to_string(w);
	// stringstream s;
	// s << w;
	// s >> ss;

    if (w % 1000)
    {
        cout << 0 endl;
        return;
    }

    while (w)
    {
        while (w / a[index] == 0)
            index--;
        ll s1 = w / a[index];
        cnt += s1;
        w -= s1 * a[index];
    }

    s2 = 0, s3 = 0;
    nWays(s);
    way *= power(2, s2) * power(3, s3);

    cout << cnt << " " << way endl; 
}

int main ()
{
    faster();
    pprc();
    run()
    {
        getip();
        solve();
    }
    return 0;
}


// --------------------------------------------------------- //
void getip()
{
    cin >> w >> c;
    reset();
}

void reset()
{
    
}
// 5000 * 10^5 = 5 * 10^8
// 5
// 11000 0
// 14000 0
// 16000 0
// 19000 0
// 46939456000 5
#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).resize(unique(ALL(v)) - (v).begin())
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
using namespace std;
const ll mod = 1e9 + 7;
const int N = 1e6;

ll res;
ll cnt[2],sum[2];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n;  cin >> n;
    
    for (int i=1;i<= n;i++ ){
        ll x;  cin >> x;
        res = (res + sum[(x & 1) ^ 1] + 1LL*cnt[(x & 1) ^ 1]*x % mod) % mod;
        cnt[x & 1]++;
        sum[x & 1] = (sum[x & 1] + x) % mod;
    }

    cout << res;
}
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
const int N = 2e5;
const ll mod = 1e9 + 7;

int n,k;
ll fact[N + 5],inv[N + 5];

ll binaryExpo(ll base,ll k){
    ll res = 1;
    for (;k > 0;k >>= 1){
        if (k & 1)  res = (res * base) % mod;
        base = (base * base) % mod;
    }
    return res;
}

ll Com(int r,int i){
    if (i > r)  return 0;
    if (i == 0 || i == r)   return 1;
    return (((1LL*fact[r]*inv[i]) % mod)*inv[r - i]) % mod;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    
    fact[0] = 1;
    for (int i=1;i<= N;i++ )
        fact[i] = (1LL*fact[i - 1]*i) % mod;
    inv[N] = binaryExpo(fact[N],mod - 2);
    for (int i=N - 1;i>= 0;i-- )
        inv[i] = (1LL*inv[i + 1]*(i + 1)) % mod;

    while (numTest-- ){
        cin>>n>>k;
        int numOne = 0,numZero = 0;
        for (int i=1;i<= n;i++ ){
            int x;  cin>>x;
            (x == 1 ? numOne++ : numZero++);
        }

        int need = (k + 1) / 2;
        int limit = min(numOne,k);
        ll res = 0;
        for (int i=max(need,k - numZero);i<= limit;i++ )
            res = (res + 1LL*Com(numOne,i)*Com(numZero,k - i))% mod;
        cout<<res<<'\n';

    }
}
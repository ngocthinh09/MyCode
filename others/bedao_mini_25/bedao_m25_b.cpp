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

ll n,a,b,c;
ll lcmAll,sub;

ll lcm(ll x,ll y){
    //assert(__gcd(x,y) != 0);
    return (x/__gcd(x,y))*y;
}

ll res;

ll countDiv(ll x){
    ll val = x;
    ll cnt = 1;
    for (ll i=2;i*i<= x;i++ ){
        if (val % i == 0){
            ll num = 0;
            while (val % i == 0){
                val /= i;
                num++;
            }
            cnt *= (num + 1);
        }
    }

    if (val > 1)
        cnt *= 2;

    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> a >> b >> c;
    lcmAll = lcm(lcm(a,b),c);

    // cout << lcmAll <<'\n';

    // cout << lcm(a,b) <<'\n';
    // cout << lcm(b,c) <<'\n';
    // cout << lcm(a,c) <<'\n';

    if ((n % lcm(a,b)) == 0){
        res += countDiv(n / lcm(a,b));
        sub++;
    }

    if ((n % lcm(b,c)) == 0){
        res += countDiv(n / lcm(b,c));
        sub++;
    }

    if ((n % lcm(a,c)) == 0){
        res += countDiv(n / lcm(a,c));
        sub++;
    }

    if (n % lcmAll == 0)
        res -= 1LL*(sub - 1)*countDiv(n / lcmAll);

    cout << res;
}
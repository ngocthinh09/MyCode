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

ll n,x;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n>>x;
        ll res = 0;
        for (ll a=1;a<= x;a++ )
            for (ll b=1;b<= n/a;b++ ){
                ll limC =  min((n - a*b)/(a + b),x - a - b);
                if (limC > 0)
                    res += limC;
            }

        cout<<res<<'\n';
    }
}
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
const int K = 100;

int k;
ll p[K + 5];
ll C,X;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>k;
    for (int i=1;i<= k;i++ )    cin>>p[i];
    cin>>C;
    for (ll X=1;X<= (ll)1e6;X++ )
        if ((ll)X*X*X == C){
            cout<<X;
            break;
        }

}
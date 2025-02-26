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
const double pi = acos(0);

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    ll x0,y0;   cin>>x0>>y0;
    ll x1,y1;   cin>>x1>>y1;
    double cos = (1.0*(x0*x1 + y0*y1)/(sqrt(x0*x0 + y0*y0) * sqrt(x1*x1 + y1*y1)));
    double rad = acos(cos);
    if (rad < 0)    rad = rad + M_PI;
    cout<<fixed<<setprecision(9)<<rad;
}
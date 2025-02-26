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
const int N = 1e5;

struct Point{
    ll x,y;
    Point(ll _x = 0,ll _y = 0){
        x = _x,y = _y;
    }
};

struct VecTor{
    ll x,y;
    VecTor (ll _x = 0,ll _y = 0){
        x = _x,y = _y;
    }
    VecTor (Point A,Point B){
        x = B.x - A.x, y = B.y - A.y;
    }

    ll cross(const VecTor &other) const{
        return 1LL*(x*other.y - y*other.x);
    }

    double length(){
        return sqrt(x*x + y*y);
    }
};

int n;
Point pt[N + 5];
double res;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n;
    for (int i=1;i<= n;i++ )    cin>>pt[i].x>>pt[i].y;

    for (int i=3;i<= n;i++ )
        res = res + 1.0*abs(VecTor(pt[1],pt[i - 1]).cross(VecTor(pt[1],pt[i])))/2;

    cout<<fixed<<setprecision(9)<<res;

}

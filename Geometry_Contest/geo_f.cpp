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

struct Point{
    ll x,y;
    Point (ll _x = 0,ll _y = 0){
        x = _x,y = _y;
    }
};

struct Line{
    ll A,B,C;
    Line (ll _A = 0,ll _B = 0,ll _C = 0){
        A = _A, B = _B, C = _C;
    }
    Line (Point pA,Point pB){
        A = pA.y - pB.y;
        B = pB.x - pA.x;
        C = -1LL*A*pA.x - 1LL*B*pA.y;
    }

    double distance(const Point &pt) const{
        return 1.0*abs(A*pt.x + B*pt.y + C)/sqrt(A*A + B*B);
    }
};

Point pt;
Line line;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>pt.x>>pt.y;
    Point A,B;  cin>>A.x>>A.y>>B.x>>B.y;
    line = Line(A,B);
    cout<<fixed<<setprecision(6)<<line.distance(pt);
}
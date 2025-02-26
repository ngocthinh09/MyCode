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

    friend istream &operator >> (istream &is, Point &pt){
        is>>pt.x>>pt.y;
        return is;
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

    int sign(const Point &pt){
        ll val = A*pt.x + B*pt.y + C;
        if (val > 0)    return 1;
        else if (val < 0)   return -1;
        return 0;
    }

    double distance(const Point &pt) const{
        return 1.0*abs(A*pt.x + B*pt.y + C)/sqrt(A*A + B*B);
    }
};

bool BelongToRay(Point P,Point O,Point T){  // check P belong to OT ray
    VecTor OP(O,P),OT(O,T);
    return ((OP.x * OT.y == OP.y * OT.x) && ((1.0*OP.x/OT.x) >= 0) ? true : false);
}   

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    Point P,A,B;
    cin>>P>>A>>B;
    
    if (BelongToRay(P,A,B) && BelongToRay(P,B,A))
        cout<<"YES";
    else cout<<"NO";

    return 0;
}
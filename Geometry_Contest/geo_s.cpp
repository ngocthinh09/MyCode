#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define ld long double
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

    ll dot(const VecTor &other) const{
        return 1LL*(x*other.x + y*other.y);
    }

    ll cross(const VecTor &other) const{
        return 1LL*(x*other.y - y*other.x);
    }

    ld length(){
        return sqrt(x*x + y*y);
    }
};

struct Line{
    ll A,B,C;
    Line (ll _A = 0,ll _B = 0,ll _C = 0){
        A = _A, B = _B, C = _C;
        if (A < 0)  A = -A, B = -B, C = -C;
    }
    Line (Point pA,Point pB){
        A = pA.y - pB.y;
        B = pB.x - pA.x;
        C = -A*pA.x - B*pA.y;
        if (A < 0)  A = -A, B = -B, C = -C;
    }

    friend istream &operator>>(istream &is,Line &ln){
        return (is>>ln.A>>ln.B>>ln.C);
    }

    friend ostream &operator<<(ostream &os,Line &ln){
        return (os<<ln.A<<' '<<ln.B<<' '<<ln.C);
    }

    friend bool operator==(const Line &lhs,const Line &rhs){
        return (lhs.A == rhs.A && lhs.B == rhs.B && lhs.C == rhs.C);
    }

    bool checkParallel(const Line &other){
        return (A == other.A && B == other.B && C != other.C);
    }

    int sign(const Point &pt){
        ll val = A*pt.x + B*pt.y + C;
        if (val > 0)    return 1;
        else if (val < 0)   return -1;
        return 0;
    }

    ld distance(const Point &pt) const{
        return 1.0*abs(A*pt.x + B*pt.y + C)/sqrt(A*A + B*B);
    }
};

ld DisFromPointToSeg(Point A,Point B,Point C){ // distance from A to segment BC
    ld length = 1e18;
    if (VecTor(B,A).dot(VecTor(B,C)) >= 0 && VecTor(C,A).dot(VecTor(C,B)) >= 0)
        length = Line(B,C).distance(A);
    else length = min(VecTor(B,A).length(),VecTor(C,A).length());
    return length;
}

bool BelongToRay(Point P,Point O,Point T){  // check P belong to ray OT
    VecTor OP(O,P),OT(O,T);
    return ((OP.x * OT.y == OP.y * OT.x) && ((1.0*OP.x/OT.x) >= 0) ? true : false);
}

bool BelongToSegment(Point A,Point B,Point C){ 
    return (BelongToRay(A,B,C) && BelongToRay(A,C,B));
}

bool checkIntersected(Point A,Point B,Point C,Point D){
    bool flag = false;
    flag = (flag | BelongToSegment(A,C,D) | BelongToSegment(B,C,D) | BelongToSegment(C,A,B) | BelongToSegment(D,A,B));
    Line AB(A,B),CD(C,D);
    if ((AB.sign(C)*AB.sign(D) < 0) && (CD.sign(A)*CD.sign(B) < 0))
        flag |= 1;
    
    return flag;
}

ld DisFromSegmentToSegment(Point A,Point B,Point C,Point D){    // distance to segment AB to segment CD
    ld res = 1e18;
     if (checkIntersected(A,B,C,D))
        res = 0;
    else    res = min({DisFromPointToSeg(A,C,D),DisFromPointToSeg(B,C,D),DisFromPointToSeg(C,A,B),DisFromPointToSeg(D,A,B)});
    return res;
}

ld DisFromPointToRay(Point A,Point B,Point C){
    ld length = 1e18;
    if (VecTor(B,A).dot(VecTor(B,C)) < 0)
        length = VecTor(B,A).length();
    else    length = Line(B,C).distance(A);
    return length;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".in","r",stdin);
    freopen(problem".out","w",stdout);
    Point A,B,C,D;  cin>>A>>B>>C>>D;
    Line AB(A,B),CD(C,D);
    VecTor vecAB(A,B),vecCD(C,D);

    ld length = 1e18;

    if (AB == CD){
        if (1.0*vecAB.x/vecCD.x < 0 || 1.0*vecAB.y/vecCD.y < 0){
            if (BelongToRay(A,C,D) || BelongToRay(C,A,B))
                length = 0;
            else length = VecTor(A,C).length();
        }
        else length = 0;
    }
    else if (AB.checkParallel(CD))
        length = min(DisFromPointToRay(A,C,D),DisFromPointToRay(C,A,B));
    else{
        double det = (AB.A*CD.B - CD.A*AB.B);
        double x = 1.0*(CD.C*AB.B - AB.C*CD.B)/det;
        double y = 1.0*(AB.C*CD.A - AB.A*CD.C)/det;

        if (1.0*(x - A.x)/vecAB.x >= 0 && 1.0*(y - A.y)/vecAB.y >= 0 && 1.0*(x - C.x)/vecCD.x >= 0 && 1.0*(y - C.y)/vecCD.y >= 0)
            length = 0;
        else length = min(DisFromPointToRay(A,C,D),DisFromPointToRay(C,A,B));
    }

    cout<<fixed<<setprecision(6)<<length;
}
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

double A,B,C,R;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);

    cin>>A>>B>>C>>R;

    double C1 = C + R*sqrt(A*A + B*B);
    double C2 = C - R*sqrt(A*A + B*B);

    cout<<fixed<<setprecision(10);
    cout<<A<<' '<<B<<' '<<C1<<'\n';
    cout<<A<<' '<<B<<' '<<C2<<'\n';
}
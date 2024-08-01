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

int n,q;
int a[N + 5];

struct FenwickTree{
    ll bit[N + 5];
    void updatePoint(int x,int val){
        for (;x <= n;x += (x & (-x)))
            bit[x] += val;
    }

    ll getPoint(int x){
        ll ret = 0;
        for (;x > 0;x -= (x & (-x)))
            ret += bit[x];
        return ret;
    }

    ll getRange(int l,int r){
        return getPoint(r) - getPoint(l - 1);
    }
};

FenwickTree fen[10];


bool check(int num,int need){
    if (num % need == 0)    return true;
    while (num > 0){
        if (need == (num % 10)) return true;
        num /= 10;
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<= n;i++ )    cin>>a[i];
    for (int k=1;k<= 9;k++ )
        for (int i=1;i<= n;i++ )
            if (check(i,k))
                fen[k].updatePoint(i,2*a[i]);
            else fen[k].updatePoint(i,a[i]);
    
    for (int i=1;i<= q;i++ ){
        int type;   cin>>type;
        if (type == 1){
            int x,y;    cin>>x>>y;
            int delta = y - a[x];
            a[x] = y;
            for (int k=1;k<= 9;k++ )
                if (check(x,k))
                    fen[k].updatePoint(x,2*delta);
                else fen[k].updatePoint(x,delta);
        }
        else{
            int x,y,k;  cin>>x>>y>>k;
            cout<<fen[k].getRange(x,y)<<'\n';
        }
    }

}
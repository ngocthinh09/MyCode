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

ll u,v,mod;

ll binaryMul(ll a,ll b){
    if (b == 0) return 0;
    ll x = binaryMul(a,b/2);
    if (b & 1)
        return (2LL*x + a) % mod;
    return (2LL*x) % mod;
}

struct Matrix{
    int r,c;
    vector<vector<ll>> mat;

    Matrix (int _r = 0,int _c = 0) : r(_r), c(_c){
        mat.resize(r,vector<ll> (c,0));
    }

    friend Matrix operator *(const Matrix &lhs,const Matrix &rhs){
        Matrix res(lhs.r,rhs.c);
        for (int i=0;i< lhs.r;i++ )
            for (int j=0;j < rhs.c;j++ )
                for (int k=0;k < lhs.c;k++ )
                    res.mat[i][j] = (res.mat[i][j] + binaryMul(lhs.mat[i][k],rhs.mat[k][j])) % mod;

        return res;
    }
};

Matrix expo(Matrix base,ll k){
    Matrix res(2,2);
    res.mat = {{1,0},{0,1}};

    while (k > 0){
        if (k & 1)  res = res * base;
        base = base*base;
        k >>= 1;
    }

    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>u>>v>>mod;
    ll _gcd = __gcd(u,v);

    Matrix base(2,2);
    base.mat = {{0,1},{1,1}};

    Matrix init(1,2);
    init.mat = {{0,1}};

    init = init*expo(base,_gcd);

    cout<<init.mat[0][0];
}
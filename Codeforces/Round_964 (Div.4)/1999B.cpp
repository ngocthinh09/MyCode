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

int solve(int a,int b,int c,int d){
    int suneet = 0,slavic = 0;
    if (a > c)  
        suneet++;
    else if (a < c) 
        slavic++;
    if (b > d)  
        suneet++;
    else if (b < d) 
        slavic++;

    return (suneet > slavic);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        int res = 0;
        res += solve(a1,a2,b1,b2);
        res += solve(a1,a2,b2,b1);
        res += solve(a2,a1,b1,b2);
        res += solve(a2,a1,b2,b1);
        cout<<res<<'\n';
    }
}
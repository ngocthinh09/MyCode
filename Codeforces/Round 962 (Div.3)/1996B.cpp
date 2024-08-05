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
const int N = 1000;

int n,k;
char a[N + 5][N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n>>k;
        for (int i=1;i<= n;i++ )
            for (int j=1;j<= n;j++ )
                cin>>a[i][j];
        for (int i=1;i<= n;i+= k,cout<<'\n')
            for (int j=1;j<= n;j+= k)
                cout<<a[i][j];
    }
}
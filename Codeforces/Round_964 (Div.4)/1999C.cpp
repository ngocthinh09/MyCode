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

int n;
ll s,m;
ll l[N + 5],r[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n>>s>>m;
        for (int i=1;i<= n;i++ )
            cin>>l[i]>>r[i];
        l[0] = r[0] = 0;
        l[n + 1] = r[n + 1] = m;
        
        bool flag = false;
        for (int i=1;i<= n + 1;i++ )
            if (l[i] - r[i - 1] >= s){
                flag = true;
                break;
            }

        cout<<(flag ? "YES" : "NO")<<'\n';
    }
}
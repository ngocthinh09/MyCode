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
const int N = 1e6;

int n,Q;
string str;
int prefix[N + 5][26];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>Q;
    cin>>str;
    str = ' ' + str;
    for (int i=1;i<= n;i++ )
        for (int j=0;j<= 25;j++ )
            prefix[i][j] = prefix[i - 1][j] + ((str[i] - 'a') == j);

    while(Q-- ){
        int l,r;    cin>>l>>r;
        l++,r++;
        int odd = 0;
        for (int i=0;i<= 25;i++ )
            if ((prefix[r][i] - prefix[l - 1][i]) & 1)
                odd++;
        cout<<odd/2<<'\n';
    }
}
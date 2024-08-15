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

ll n,m,k,w;
ll gorillas[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>n>>m>>k>>w;
        for (int i=1;i<= w;i++ )
            cin>>gorillas[i];
        
        vector<vector<ll>> prefix;
        prefix.resize(n + 2,vector<ll> (m + 2,0));

        for (int i=1;i + k - 1<= n;i++ )
            for (int j=1;j + k - 1<= m;j++ ){
                int x = i,y = j,u = i + k - 1,v = j + k - 1;
                prefix[u + 1][v + 1]++;
                prefix[u + 1][j]--;
                prefix[i][v + 1]--;
                prefix[x][y]++;
            }

        vector<int> value;
        for (int i=1;i<= n;i++ )
            for (int j=1;j<= m;j++ ){
                prefix[i][j] += (prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]);
                value.push_back(prefix[i][j]);
            }

        sort(ALL(value),greater<ll>());
        sort(gorillas + 1,gorillas + w + 1,greater<ll>());
        ll res = 0;
        for (int i=1;i<= w;i++ )
            res += 1LL*value[i - 1]*gorillas[i];
        
        cout<<res<<'\n';
    }
}
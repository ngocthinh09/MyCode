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
string a,b;
int prefix[2][N + 5][26];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n>>q>>a>>b;
        a = ' ' + a;
        b = ' ' + b;
        for (int i=1;i<= n;i++ )
            for (int j=0;j<= 25;j++ ){
                prefix[0][i][j] = prefix[0][i - 1][j] + ((a[i] - 'a') == j);
                prefix[1][i][j] = prefix[1][i - 1][j] + ((b[i] - 'a') == j);
            }

        while (q-- ){
            int l,r;    cin>>l>>r;
            int numDiff = 0;
            for (int i=0;i<= 25;i++ ){
                int cntA = prefix[0][r][i] - prefix[0][l - 1][i];
                int cntB = prefix[1][r][i] - prefix[1][l - 1][i];
                numDiff += abs(cntA - cntB);
            }
            cout<<numDiff/2<<'\n';
        }
    }
}
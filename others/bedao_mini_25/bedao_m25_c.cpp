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
ll c[N + 5],a[N + 5];
vector<ll> color[N + 5],prefix[N + 5];
ll sumAll,sumSub[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n;
    for (int i=1;i<= n;i++ ){
        cin >> a[i] >> c[i];
        color[c[i]].push_back(a[i]);
    }

    for (int i=1;i<= N;i++ )
        if ((int)color[i].size()){
            int sz = (int)color[i].size();
            prefix[i].resize(sz + 1,0);
            prefix[i][0] = color[i][0];
            for (int j=1;j< sz;j++ )
                prefix[i][j] = prefix[i][j - 1] + color[i][j];
        }

    cin >> q;
    while (q-- ){
        int type;   cin >> type;
        if (type == 1){
            ll col,x;   cin >> col >> x;
            sumAll += x;
            sumSub[col] -= x;
        }
        else{
            ll col,y;   cin >> col >> y;
            int lo = 0,hi = (int)color[col].size() - 1,ans = -1;
            while (lo <= hi){
                int mid = (lo + hi) >> 1;
                ll val = prefix[col][mid] + 1LL*(mid + 1)*(sumAll + sumSub[col]);
                if (val <= y){
                    ans = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }

            cout << ans + 1 <<'\n';
        }
    }

}
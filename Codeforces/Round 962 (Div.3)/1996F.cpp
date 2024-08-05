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
const int N = 10;

int n,numTurn;
int a[N + 5],b[N + 5];

bool check(ll mid){
    ll total = 0;
    for (int i=1;i<= n;i++ ){
        if (a[i] < mid) continue;
        ll turn = (a[i] - mid)/b[i] + 1;
        total += turn;
    }
    return (total <= numTurn);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n>>numTurn;
        for (int i=1;i<= n;i++ )    cin>>a[i];
        for (int i=1;i<= n;i++ )    cin>>b[i];

        ll lo = 0,hi = *max_element(a + 1,a + n + 1) + 1;
        ll minValue = hi;
        while (lo <= hi){
            ll mid = (lo + hi) >> 1;
            if (check(mid)){
                hi = mid - 1;
                minValue = mid;
            }
            else lo = mid + 1;
        }

        ll res = 0;
        for (int i=1;i<= n;i++ ){
            if (a[i] < minValue)    continue;
            ll turn = (a[i] - minValue)/b[i] + 1;
            res += (turn*a[i] - ((turn - 1)*turn/2)*b[i]);
            numTurn -= turn;
        }

        if (minValue > 0)
            res += numTurn*(minValue - 1);

        cout<<res<<'\n';
    }
}
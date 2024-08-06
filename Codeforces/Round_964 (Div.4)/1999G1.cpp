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

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        int lo = 2,hi = 999,ans = lo;
        while (lo <= hi){
            int mid = (lo + hi) >> 1;
            cout<<"? "<<1<<' '<<mid<<'\n'<<flush;
            int digit = 0;
            cin>>digit;
            if (digit == mid)
                lo = mid + 1;
            else{
                ans = mid;
                hi = mid - 1;
            }
        }

        cout<<"! "<<ans<<'\n';
    }
}
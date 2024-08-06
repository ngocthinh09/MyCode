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
    for (int test=1;test<= numTest;test++ ){

        int lo = 2,hi = 999;
        while (hi - lo > 2){
            int mid1 = lo + (hi - lo)/3;
            int mid2 = hi - (hi - lo)/3;
            cout<<"? "<<mid1<<' '<<mid2<<'\n'<<flush;
            int digit = 0;
            cin>>digit;
            if (digit == (mid1 + 1)*(mid2 + 1))
                hi = mid1;
            else if (digit == mid1*(mid2 + 1)){
                lo = mid1 + 1;
                hi = mid2;
            }
            else if (digit = mid1*mid2)
                lo = mid2 + 1;
        }

        if (hi - lo == 2){
            cout<<"? "<<lo<<' '<<lo + 1<<'\n'<<flush;
            int digit = 0;
            cin>>digit;
            if (digit == (lo + 1)*(lo + 2))
                cout<<"! "<<lo<<'\n';
            else if (digit == lo*(lo + 2))
                cout<<"! "<<lo + 1<<'\n';
            else cout<<"! "<<hi<<'\n';
        }
        else if (hi - lo == 1){
            cout<<"? "<<1<<' '<<lo<<'\n'<<flush;
            int digit = 0;
            cin>>digit;
            if (digit == lo)
                cout<<"! "<<lo + 1<<'\n';
            else cout<<"! "<<lo<<'\n'; 
        }
        else if (hi - lo == 0)
            cout<<"! "<<lo<<'\n';
    }
}
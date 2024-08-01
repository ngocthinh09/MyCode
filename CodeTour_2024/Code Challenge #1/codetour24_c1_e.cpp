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
const int LOG = 17;

int n;
ll a[N + 5],prefix[N + 5];
vector<int> pos;

struct Sparse_Table{
    ll spt[LOG + 1][N + 5];
    Sparse_Table(){}

    void build(){
        for (int lg=1;MASK(lg)<= n;lg++ )
            for (int i=1;i + MASK(lg) - 1 <= n;i++ )
                spt[lg][i] = max(spt[lg - 1][i],spt[lg - 1][i + MASK(lg - 1)]);
    }

    ll getMax(int l,int r){
        int lg = 31 - __builtin_clz(r - l + 1);
        return max(spt[lg][l],spt[lg][r - MASK(lg) + 1]);
    }
} maxPlus,maxMinus;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>n;
        pos.clear();
        for (int i=1;i<= n;i++ ){
            cin>>a[i];
            if (a[i] == 1)  pos.push_back(i);
            prefix[i] = prefix[i - 1] + a[i];
            maxPlus.spt[0][i] = a[i] + prefix[i];
            maxMinus.spt[0][i] = a[i] - prefix[i - 1];
        }

        maxPlus.build();
        maxMinus.build();

        bool flag = false;

        for (int i : pos){
            ll maxValuePlus = maxPlus.getMax(1,i - 1);
            ll maxValueMinus = maxMinus.getMax(i,n);
            if (maxValuePlus <= 1 + prefix[n] && maxValueMinus <= 1 - prefix[i - 1]){
                flag = true;
                break;
            }
        }

        cout<<(flag ? "YES" : "NO")<<'\n';
    }
}
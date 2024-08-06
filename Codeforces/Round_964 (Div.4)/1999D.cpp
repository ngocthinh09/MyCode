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

int lenStr,lenMust;
string str,must;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while(numTest-- ){
        cin>>str>>must;
        lenStr = (int)str.length();
        lenMust = (int)must.length();
        str = ' ' + str;
        must = ' ' + must;
        bool flag = true;
        for (int i=1,j = 0;i<= lenMust;i++ ){
            for (j = j + 1;j<= lenStr;j++ ){
                if (must[i] == str[j])
                    break;
                else if (str[j] == '?'){
                    str[j] = must[i];
                    break;
                }
            }

            if (j == (lenStr + 1)){
                flag = false;
                break;
            }
        }

        if (flag == false)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            for (int i=1;i<= lenStr;i++ ){
                if (str[i] == '?')
                    str[i] = 'a';
                cout<<str[i];
            }
            cout<<'\n';
        }
    }
}
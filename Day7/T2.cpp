#include<bits/stdc++.h>
using namespace std;
multiset<int> st;
int q,n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    while(q--){
        int opt;
        cin>>opt;
        if(opt==1){
            int x;
            cin>>x;
            if(st.count(x)!=0){
                st.erase(st.find(x));
                int mint = *st.begin();
                int maxt = *st.rbegin();
                cout<<2*abs(maxt-mint)<<'\n';
            }
            else{
                cout<<"-1\n";
            }
        }
        else{
            int x;
            cin>>x;
            st.insert(x);
            int mint = *st.begin();
            int maxt = *st.rbegin();
            cout<<2*abs(maxt-mint)<<'\n';
        }
    }
}
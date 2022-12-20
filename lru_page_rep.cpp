#include <bits/stdc++.h>
using namespace std;
#define            send {ios_base::sync_with_stdio(false);}
#define            help {cin.tie(NULL); cout.tie(NULL);}
 

void solve(){
     //  lru
     int n;
     cin>>n;
     int capacity;
     cin >> capacity;
    
    vector<int> pages(n);
    for(int i=0;i<n;++i) cin>>pages[i];
    vector<int> t;
    int pageFault=0;
    for(int i=0;i<n;++i){
        auto it=find(begin(t),end(t),pages[i]);
        if(it==t.end()){
            if(t.size()==capacity){
                t.erase(t.begin());
            }
            pageFault++;
            t.push_back(pages[i]);

        }else{
            t.erase(it);
            t.push_back(pages[i]);
        }
    }
         
      cout<<"No of page faults are: "<<pageFault<<endl;

}


int32_t main() {

send help

#ifndef ONLINE_JUDGE
freopen("_input.txt", "r", stdin);
freopen("_output.txt", "w", stdout);
#endif 

int tc = 1;
// cin >> tc;
   
while (tc--) {
     solve();
}
return 0;
} 
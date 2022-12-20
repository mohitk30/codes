#include <bits/stdc++.h>
using namespace std;
#define            send {ios_base::sync_with_stdio(false);}
#define            help {cin.tie(NULL); cout.tie(NULL);}

// first come first serve
void solve(){

    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    int a;
    int pageFault = 0;
    vector<int> t, pages(n);
    for (auto &it : pages)
        cin >> it;
    for (int i = 0; i < n; ++i)
    {
        auto it = find(t.begin(), t.end(), pages[i]);
        if (it == t.end())
        {
            pageFault++;
            if (t.size() == capacity)
            {
                t.erase(t.begin());
            }
            t.push_back(pages[i]);
        }
    }
    cout << "Page Faults: " << pageFault << endl;
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
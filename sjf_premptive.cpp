 
//  preemptive jobs
//  sjf

 

#include <bits/stdc++.h>
using namespace std;
#define            send {ios_base::sync_with_stdio(false);}
#define            help {cin.tie(NULL); cout.tie(NULL);}
vector<int> doneJobs(1000,0);

vector<vector<int> > rq;
bool comp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}
 
void solve(){

    // cout<<"Enter No. of programs: ";
    int n;
    cin>> n;

    vector<vector<int>> vt(n);
    for(int i=0;i<n;++i){
        int bt,at;
        cin>>bt>>at;
        vt[i]={bt,at,i+1};
    }
    sort(begin(vt),end(vt),comp);
    int t=vt[0][1];
    int time=0;

    int pDone=0;
    vector<vector<int>> processSeq;
    while(pDone < n){

        for(int i=0;i<n;++i){
            if(!doneJobs[i] && vt[i][1]<=time){
                rq.push_back(vt[i]);
                doneJobs[i]=1;
            }
        }
        sort(begin(rq),end(rq));

        //   for(auto it:rq){
        //         for(auto itt:it){
        //             cout<<itt<<" ";
        //         }
        //         cout<<endl;
        //     }
        //  cout<<endl;

        if(!rq.empty()){

            if(processSeq.empty()){

                processSeq.push_back({rq[0][0],1,rq[0][2]});

            }else{

                if(processSeq.back()[2] == rq[0][2]){
                    auto it=processSeq.back();
                    processSeq.pop_back();
                    it[1]++;
                    processSeq.push_back(it);
                }else{
                    processSeq.push_back({rq[0][0],1,rq[0][2]});
                }

            }

            int ct=rq[0][0];
        
            ct--;
            if(ct >0){
                rq[0][0]=ct;
            }else{
                rq.erase(rq.begin());
                pDone++;
            }


      }

        time++;
     


    }
   cout<<"Process occurs in this manner"<<endl;
   cout<<"CompleteTime     "<<"TimeInCpu   "<<"ProgramNo."<<endl;
   
   for(int i=0;i<processSeq.size();++i){  
        t+=processSeq[i][1];
        processSeq[i][0]=t;
        cout<<(processSeq[i][0])<<"\t\t\t\t\t "<<processSeq[i][1]<<" \t\t\t"<<processSeq[i][2]<<endl;
   }

   int totalWaitTime=0;
   vector<int> frq(n+1,-1);

   for(int i=processSeq.size()-1;i>=0;--i){  
        if(frq[processSeq[i][2]]==-1){
            frq[processSeq[i][2]]=processSeq[i][0];
        }
   }
  int totalTurnaroundTime=0;
  int tnt=0;
 for(int i=1;i<=n;++i) {
    // cout<<(totalTurnaroundTime+=(frq[i]-vt[i-1][1]))<<" ";
    totalTurnaroundTime+=(frq[i]-vt[i-1][1]);
    tnt=(frq[i]-vt[i-1][1]);
    totalWaitTime+=tnt-vt[i-1][0];
    }
//  cout<<endl;

cout<<"Avg wait time:- "<<(double(totalWaitTime)/n)<<endl;
cout<<"Avg turnaround time:- "<<(double(totalTurnaroundTime)/n)<<endl;


     
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



 

  
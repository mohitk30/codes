 
//  Round robin jobs
 
#include <bits/stdc++.h>
using namespace std;
#define            send {ios_base::sync_with_stdio(false);}
#define            help {cin.tie(NULL); cout.tie(NULL);}

vector<int> doneJobs(1000,0);
queue<vector<int>> rq;
bool comp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

void solve(){
    // cout<<"Enter No. of programs: ";
    int n;
    cin>> n;
    int quantum=0;
     cin>> quantum;

    vector<vector<int>> vt(n);
    for(int i=0;i<n;++i){
        int bt,at;
        cin>>bt>>at;
        vt[i]={bt,at,i+1};
    }
      sort(begin(vt),end(vt),comp);
    int t=vt[0][1];
    
    int time=0;

    int processComp=0;
    vector<vector<int>> processSeq;
    while(processComp<n){ 

        for(int i=0;i<n;++i){
            if(!doneJobs[i] && vt[i][1]<=time){
                rq.push(vt[i]);
                doneJobs[i]=1;
            }
        }


         if(!rq.empty()){
                auto it=rq.front();
                // for(auto ik:it) cout<<ik<<" ";
                //   cout<<endl;
                rq.pop();

                for(int i=0;i<min((int)quantum,(int)it[0]);++i){
                    time++;
                    for(int i=0;i<n;++i){
                    if(!doneJobs[i] && vt[i][1]<=time){
                        rq.push(vt[i]);
                        doneJobs[i]=1;
                    }
                    }
                    
                }

                if(it[0]>quantum){
                    it[0]-=quantum;
                    processSeq.push_back({quantum,it[1],it[2]});
                    rq.push(it);
                }else{
                    processSeq.push_back(it);
                    processComp++;
                }
      }
      else{
        time++;
      }


        // time+=min((int)quantum,(int)it[0]);
        // time++;
        // cout<<time<<endl;
    }

   cout<<"Process occurs in this manner"<<endl;
   cout<<"CompleteTime     "<<"ArrivalTime   "<<"ProgramNo."<<endl;

    
    for(int i=0;i<processSeq.size();++i){  
            t+=processSeq[i][0];
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



 

  
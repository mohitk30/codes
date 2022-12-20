// Write a program in C++ to calculate average waiting time and average turn around time 
// using Shortest Job First scheduling algorithm.

#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>& a,vector<int>& b){
    if(a[1]==b[1]){
      return a[2]<b[2];
    }
    return a[1]<=b[1];
}
bool comp2(vector<int>& a,vector<int>& b){
   
    return a[2]<=b[2];
}
int main(){
    // n=> no. of programs
    int n; 
    cin>>n;

    vector<vector<int> > vt(n);

    for(int i=0;i<n;++i){
       int a,b,c;
       // a=> prog no. // b=> arrival time // c=> burst time
       cin>>a>>b>>c;
       vt[i].push_back(a);
       vt[i].push_back(b);
       vt[i].push_back(c);
       
    }
    
    sort(begin(vt),end(vt),comp);
    int avg_wait_time=0;
    int time=0;
    int completeat=0;
    int wt=0;
    int totalt=0;
    
    vector<int> vis(n+1,0);
    int complt=0;
    while(complt!=n){
      
      vector<vector<int> > temp;
      for(int j=0;j<n;++j){
         if(vis[vt[j][0]]) continue;
         if(vt[j][1]<=time) temp.push_back(vt[j]);
      }

      if(temp.size()==0) {
         time++;
         continue;
      }
        sort(begin(temp),end(temp),comp2);

       if(temp.size()>0){
         auto it=temp[0];
         cout<<"Program "<<it[0]<<" with arrival time:- "<<it[1]<<" brust time:- "<<it[2]<<endl;
         cout<<"Total Wait time : "<<(avg_wait_time=(time-it[1] >=0? time-it[1]: 0 ))<<endl;
         vis[it[0]]=1;
         time+=it[2];
         wt+=avg_wait_time;
         totalt+=it[2]+avg_wait_time;
         complt++;
        }

  
    }
      cout<<endl;
      cout<<"Avg waiting time ="<<((double)wt/n)<<endl;
      cout<<"Avg turn around time ="<<((double)totalt/n)<<endl;

}

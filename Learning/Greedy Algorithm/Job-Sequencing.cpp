#include<iostream>
using namespace std;

bool comp(job a, job b){
    return a.profit > b.profit;
}

class solution{
    public:
        vector<int>jobseculiding(job arr[], int n){
            sort(job,job+n,com);

            int deadline = 0;
            for(int i=0; i<n; i++)
             deadline = max(deadline,arr[i].dead);

            vector<bool>Task(deadline+1,0);

            vector<int>ans(2,0);

            for(int i=0; i<n; i++){
                // Can I compile this task before or on deadline 
                for(int j=arr[i].dead; j>0; j--){
                    if(!Task[j]){
                        Task[j]=1;
                        ans[0]++;
                        ans[1]+=ans[i].profit;
                        break;
                    }
                }
            }
        }
}
int main(){

}
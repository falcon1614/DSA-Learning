// https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1704772982/

#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();
        for(int i=0; i<n; i++){
            q.push(i);
        }

        int Time = 0;

        while(tickets[k]!=0){
            tickets[q.front()]--;
            // Kaya Line Me lage Gaa
            if(tickets[q.front()])
            q.push(q.front());
            q.pop();
            Time++;
        }
        return Time;
    }

    int main() {
        vector<int> tickets = {2, 3, 2};
        int k = 2;
        cout << timeRequiredToBuy(tickets, k) << endl; // Output: 6
        return 0;
    }

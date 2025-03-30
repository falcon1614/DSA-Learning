#include<iostream>
#include<vector>
using namespace std;
// Undirected Graph  (No Weight)
// int main(){
//     int vertex,edges;
//     cout<<"Enter the number of vertices: ";
//     cin>>vertex;
//     cout<<"Enter the number of edges: ";
//     cin>>edges;

//     vector<int> AdjList[edges];

//     int u,v;
//     for(int i=0; i<edges; i++){
//         cin>>u>>v;
//         AdjList[u].push_back(v);
//         AdjList[v].push_back(u);
//     }
//     // Print Adj List
//     for (int i = 0; i < vertex; i++){
//         cout<<i<<" -> ";
//         for(int j=0; j<AdjList[i].size(); j++){
//             cout<<AdjList[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


int main(){
    int vertex,edges;
    cout<<"Enter the number of vertices: ";
    cin>>vertex;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    vector<pair<int,int>>AdjList[vertex];

    int u,v,weight;
    for(int i=0; i<edges; i++){
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v,weight));
        AdjList[v].push_back(make_pair(u,weight));
    }
    // Print Adj List
    for (int i = 0; i < vertex; i++){
        cout<<i<<" -> ";
        for(int j=0; j<AdjList[i].size(); j++){
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}

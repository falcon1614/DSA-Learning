#include<bits/stdc++.h>
using namespace std;

/* ************************************ Remove Duplicates *************************** */
 //***|| https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1 ||***
// ************************************ Remove Duplicates ****************************||

// ************************************ Approach 1: Using Extra Space *****************************
// int main() {
//     vector<int> arr = {1,2,3,3,3,4,5,5,6,6};
//     int note = -1;  // something not in arr
//     vector<int> ans;
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] != note) {
//             ans.push_back(arr[i]);
//             note = arr[i];
//         }
//     }
//     // Print
//     for (int x : ans) {
//         cout << x << " ";
//     }
//     return 0;
// }

// ************************************ Approach 2: Without Extra Space ***************************
// int main(){
//     vector<int> arr = {1,2,3,3,3,4,5,5,6,6};
//     int n = arr.size();
//     int index = 0;
//     int note = -1;
//     for(int i=0; i<n; i++){
//         if(arr[i]!=note){
//             note = arr[i];
//             arr[index] = arr[i];
//             index++;
//         }
//     }
//     for(int i=0; i<index; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// ************************************ Approach 3: Using Two Pointers ****************************
// int main(){
//     vector<int> arr = {1,2,3,3,3,4,5,5,6,6};
//     int n = arr.size();
//     int start = 0;
//     int end = 1;
//     while (start < n && end < n){
//         if(arr[start]!=arr[end]){
//             cout<<arr[start]<<" ";
//             end++;
//             start++;
//         }
//         else{
//             start++;
//             end++;
//         }
//     }
//     cout <<arr[end-1]<<" ";
//     return 0;
// }



/****************************************************** Sub array With Given Sum ********************************************/
            //
// **************************************************** Sub array With Given Sum ********************************************||

// ************************************** Approach 1: Using Double For Loop *******************
// int main(){
//     vector<int> arr = {2,4,5,10,11,13,17};
//     int target = 22;
//     int n = arr.size();
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             int sum = arr[i] + arr[j];
//             if(sum == target){
//                 cout << "Subarray found  indexes " << i << " and " << j << endl;
//             }
//         }
//     }
//     return 0;
// }

// ************************************* Approach 2: O(N log N) *************************************
// int main(){
//     vector<int> arr = {2,4,5,10,11,13,17};
//     int target = 22;
//     int n = arr.size();
//     for(int i=0; i<n-1; i++){
//         int  find = target - arr[i];
//         // Apply Binary Search
//         int start = i+1;
//         int end = n-1;
//         while(start <= end){
//             int mid = start + (end - start) / 2;
//             if(arr[mid]==find){
//                 cout << "Subarray found  indexes " << i << " and " << mid << endl;
//             }
//             else if(arr[mid] < find){
//                 start = mid + 1;
//             }
//             else{
//                 end = mid - 1;
//             }
//         }
//     }
//     return 0;
// }

// ************************************ Approach 3: Using Two Pointer ***********************
// int main(){
//     vector<int> arr = {2,4,5,10,11,13,17};
//     int target = 22;
//     int n = arr.size();
//     int start = 0;
//     int end = n - 1;
//     while(start<end){
//         int sum = arr[start] + arr[end];
//         if(sum == target){
//             cout << "Subarray found  indexes " << start << " and " << end << endl;
//             return 0;
//         }
//         else if(sum < target){
//             start++;
//         }
//         else{
//             end--;
//         }
//     }
//     return 0;
// }


/****************************************************** Sub array With Given Multiplication ********************************************/
            //
// ************************************************** Sub array With Given Multiplication ********************************************||

// ********************************** Using two pointer ****************************
// int main(){
//     vector<int> arr = {2,4,5,10,11,13,17};
//     int target = 22;
//     int n = arr.size();
//     int start = 0;
//     int end = n-1;
//     while(start < end){
//         int product = arr[start] * arr[end];
//         if(product == target){
//             cout << "Subarray found  indexes " << start << " and " << end << endl;
//             return 0;
//         }
//         else if(product < target){
//             start++;
//         }
//         else{
//             end--;
//         }
//     }
//     return 0;
// }


/****************************************************** Sub array With Given Substring ********************************************/
//
// **************************************************** Sub array With Given Substring ********************************************||

// ********************************** Using two pointer ****************************
// int main(){
//     vector<int> arr = {1,2,5,6,7,8,9};
//     int target = 3;
//     int start = 0;
//     int end  = 1;
//     while(start <= end){
//         int sub  = arr[end] - arr[start];
//         if(sub == target){
//             cout << "Subarray found  indexes " << start << " and " << end << endl;
//             return 0;
//         }
//         else if(sub < target){
//             end++;
//         }
//         else{
//             start++;
//         }
//     }
//     return 0;
// }


/****************************************************** Union of Two Arrays ********************************************/
//

// **************************************************** Union of Two Arrays ********************************************||
// int main(){
//     return 0;
// }



/****************************************************** water trapping  ********************************************/
//

// **************************************************** Approach 1: water trapping  ********************************************||
// int main(){
//     vector<int> arr = {3,1,2,4,5};
//     int n = arr.size();
//     int waterTrapped = 0;
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             int minHeight = arr[j] - arr[i] * min(arr[i], arr[j]);
//             waterTrapped  = max(waterTrapped, minHeight);
//         }
//     }
//     cout << "Maximum water trapped: " << waterTrapped << endl;
//     return 0;
// }

// ************************************************** Approach 2: Using Two Pointers ********************************************
int main(){
        vector<int> arr = {3,1,2,4,5};
        int n = arr.size();

        
    return 0;
}

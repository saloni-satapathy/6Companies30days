// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        if(arr.size()==0)
          return ans; 
         
         sort(arr.begin(),arr.end());
         int N=arr.size();
         
         for(int i=0;i<N;i++){
             
             for(int j=i+1;j<N;j++){
                 int sum1=arr[i]+arr[j];
                 int remsum=k-sum1;
                 int left=j+1,right=N-1;
                 while(left <right){
                     if(remsum>arr[left]+arr[right]){
                       left++;  
                     }else if(remsum<arr[left]+arr[right]){
                      right--;   
                     }else{
                         vector<int>quadruple(4);
                         quadruple[0]=arr[i];
                         quadruple[1]=arr[j];
                         quadruple[2]=arr[left];
                         quadruple[3]=arr[right];
                         
                         ans.push_back(quadruple);
                         while(left<right && arr[left]==quadruple[2])
                         ++left;
                         while(left<right && arr[right-1]==quadruple[3])
                         --right;
                         
                         
                     }
                    
                 }
                 while(j+1<N and arr[j+1]==arr[j])
                     j++;
             }
             while(i+1<N and arr[i+1]==arr[i])
                     i++;
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
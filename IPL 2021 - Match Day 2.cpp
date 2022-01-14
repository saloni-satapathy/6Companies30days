// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int> dq;
        vector<int> ans;
        if(k>=n){
            ans.push_back(*max_element(arr.begin(),arr.end()));
            return ans;
        }else{
             //int max=arr[0];
            for(int i=0;i<k;i++){
              
                      while(!dq.empty() && arr[dq.back()]<=arr[i] ){
                          dq.pop_back();
                      }
               dq.push_back(i);      
            }
            ans.push_back(arr[dq.front()]);
            for(int i=k;i<n;i++){
                if(i-k>=dq.front()){
                    dq.pop_front();
                }
                
            while(!dq.empty() && arr[dq.back()]<=arr[i] ){
                            dq.pop_back();
            }
            dq.push_back(i);
                    
            
                
                ans.push_back(arr[dq.front()]);
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
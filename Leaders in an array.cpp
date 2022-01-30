// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        
         vector<int>ans;
         vector<int>led(n,0);
         led[n-1]=1;
          for(int i=n-2;i>=0;i--){
              if(led[i+1]==1){
                    led[i]=(a[i+1]<=a[i])?1:0;
              }
              else{
                  int j=i+1;
                   while(a[j]<=a[i] && j<n){
                       if(led[j]==1){
                        led[i]=1;
                        break;
                       }
                       j++;
                   }
              }
          }
          
           for(int i=0;i<n;i++){
               if(led[i])
               ans.push_back(a[i]);
           }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends
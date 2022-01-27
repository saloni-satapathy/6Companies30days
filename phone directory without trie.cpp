// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans(s.length());
        vector<string>temp;
        int flag=0;
                for(int i=0;i<n;i++){
          if(s[0]==contact[i][0]){
            temp.push_back(contact[i]);
            flag=1;
          }
          if(!flag){
             temp.push_back("0");
          }
        }
        sort(temp.begin(),temp.end());
        ans[0].push_back(temp[0]);
        for(int i=1;i<temp.size();i++){
            if(temp[i].compare(temp[i-1])!=0){
                ans[0].push_back(temp[i]);
            }
        }
       
         for(int i=1;i<s.length();i++){
           flag=0;
              for(int j=0;j<ans[i-1].size();j++){
                if(s[i]==ans[i-1][j][i]){
                 ans[i].push_back(ans[i-1][j]);
                 flag=1;
                }
              }
              if(!flag){
              ans[i].push_back("0");
              }
         }
         return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends

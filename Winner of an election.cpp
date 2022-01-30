// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string,int>count;
         for(int i=0;i<n;i++){
             count[arr[i]]++;
         }
         int max=INT_MIN;
         string ans="";
         for(auto x:count){
             if(x.second>max){
               ans=x.first; 
               max=x.second;
             }else if(x.second==max){
                 ans=(ans<x.first)?ans:x.first;
                 
             }
             
         }
         vector<string>res;
         res.push_back(ans);
         res.push_back(to_string(max));
      return res;   
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        if(S.length()>8)
         return "-1";
         stack <int> st;
          vector<int>vec;
          
         int num=1;
         for(int  i=0;i<S.length();i++){
              if(S[i]=='D'){
                  st.push(num);
                  num++;
                  
              }else{
                  
                  st.push(num);
                  num++;
                  while(!st.empty()){
                   vec.push_back(st.top());
                   st.pop();
                  }
                   
              }
         }
         
         st.push(num);
         while(!st.empty()){
                   
                   vec.push_back(st.top());
                   st.pop();
                  }
         string s="";
        for(int i=0;i<vec.size();i++){
             s+=to_string(vec[i]);
        } 
         return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends

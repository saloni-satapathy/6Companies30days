//long method

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
       stack<int>st_num;
stack<string>temp;
stack<string>st_string;
for(int i=0;i<s.length();i++){
  
   if((s[i]-48)>=0&&(s[i]-48)<=9){
 string b="";
    while((s[i]-48)>=0&&(s[i]-48)<=9){
    b+=s[i];
  i++;
    }
    i--;
     st_num.push(stoi(b));
   }
else if(s[i]=='['){
    
      st_string.push(to_string(s[i]));
   }
else if(((s[i]-96)>=1&&(s[i]-96)<=26)){
   
     string s2="";

    while((s[i]-96)>=1&&(s[i]-96)<=26){
     
      s2+=s[i];
      i++;
    }
    i--;
  
    st_string.push(s2);
   }
   
   else if(s[i]==']'){
     string s1="";
     int n;
     while((st_string.top()).compare("91")!=0){
       temp.push(st_string.top());
       
       st_string.pop();
      }
   
      while(!temp.empty()){
       s1+=temp.top();
       temp.pop();
       
      }
 
    n=st_num.top();
    st_num.pop();
    string a=s1;
    while(n>1){
     s1 +=a;
     n--;
    
    }
   
    st_string.pop();
    st_string.push(s1);  
   }

 }


 return st_string.top();
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
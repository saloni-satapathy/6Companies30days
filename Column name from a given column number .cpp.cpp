// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    
    
     string Formation( long long int n){
         //char a;
         string ans="";
         if(n>0){
         //string ans="";
         long long int r= (n%26)==0?26:(n%26);
         string a="";
         a+=(char)(64+r);
         long long int q= n%26==0?(n/26)-1:n/26;
         ans=Formation(q);
         ans+=a;
         //return ans;
         }
         return ans;
         
     }
    string colName (long long int n)
    {
        // your code here
        string s="";
        s=Formation(n);
        
        return s; 
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
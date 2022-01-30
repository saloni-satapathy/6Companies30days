// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0,sign=1;
        int num=0;

        if(str[i]=='-')
        {sign=-1;
        i++;}
        while(i!=str.length()){
            if(str[i]-'0'>=0 && str[i]-'0'<=9){
             num= num*10+(str[i]-'0');
            i++;   
            }
            else{
            return -1;
            }
        }
         
         return sign*num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
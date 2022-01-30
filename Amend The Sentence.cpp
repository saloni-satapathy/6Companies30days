// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string str="";
        for(int i=0;i<s.length();i++){
            
            if(s[i]-'A'>=0 && s[i]-'A'<=25){
                string a="";
                a+= (s[i]-'A')+'a';
                i++;
                while(s[i]-'a'>=0 && s[i]-'a'<=25 &&i<s.length()){
                    a+=s[i];
                    i++;
                }
                i--;
                if(i==s.length()-1)
                str+=a;
                else
                str+=a+" ";
            }else{
                while(s[i]-'a'>=0 && s[i]-'a'<=25){
                    str+=s[i];
                    i++;
                }
                str+=" ";
                i--;
            }
        }
        return str;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends

//Complex method
#include<bits/stdc++.h>
 using namespace std;
  int MountainLength(int arr[],int n){
        int longestMountain(vector<int>& arr) {
       int left_count=0,right_count=0;
    int i=0,a=0,b=0;
     int ans=0;
     //cout<<"***"<<endl;
   int n=arr.size();
    while(i<n-1){
      
       left_count=0,right_count=0;
      if(arr[i+1]>arr[i]){
        while(i<n-1 &&arr[i+1]>arr[i]  )  {
            
         left_count++;
        
         i++;
             
        }
       
         while(i<n-1 && arr[i+1]<arr[i] ){
           
           right_count++;
           i++;
           b=i;
           
           
         }
         if(right_count!=0){
         ans= (ans<left_count+right_count+1)?(left_count+right_count+1):ans;
         }
         a=b;
         
      }else{
        a=i+1;
        i++;
      }
    
    }
    return ans;
        
    }
  }

  int main(){
    int n;
    cin>>n; 
    int arr[n];
     for(int i=0;i<n;i++){
       cin>>arr[i];
     }
     cout<<endl;
     cout<<MountainLength(arr,n);
  }
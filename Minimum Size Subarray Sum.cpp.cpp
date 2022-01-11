   int minSubArrayLen(int target, vector<int>& nums) {
       int i=0,j=0,sum=0;
    int ans=INT_MAX;
     while(i<nums.size()  && j<nums.size()){
       sum += nums[j];
        while(sum >= target){
            ans = min(ans,j-i+1);
              sum -=nums[i];
              i++;

        }
        
        j++;
     }
     return (ans!=INT_MAX)?ans:0;
    }
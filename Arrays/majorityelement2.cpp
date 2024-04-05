class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0,count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(count1==0 && ele2!=nums[i]){
                count1=1;
                ele1=nums[i];
                
            }
            else if(count2==0 && ele1!=nums[i]){
                count2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){ 
                count1++;
            }
            else if(nums[i]==ele2){ 
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) count1++;
            if(nums[i]==ele2) count2++;
        }
        int mini=int(n/3)+1;
        if(count1>=mini) ans.push_back(ele1);
        if(count2>=mini) ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

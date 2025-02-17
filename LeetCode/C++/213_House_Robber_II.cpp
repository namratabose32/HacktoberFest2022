// Link : https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int maxA(vector<int> nums){
        int prev=nums[0],prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int notTake=prev;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=nums.size()-1)
                temp2.push_back(nums[i]);
        }
        return max(maxA(temp1),maxA(temp2));
    }
};
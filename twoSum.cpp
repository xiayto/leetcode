class Solution{
public:
  vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> m;
    vector<int> res;
    for(int i=0;i<nums.size();i++){
      if(m.count(target-nums[i])){
        return {i,m[target-nums[i]]
      };
      m[nums[i]]=i;
    }
}
  
      
  








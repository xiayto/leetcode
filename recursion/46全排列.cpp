// 20ms
// 9.3MB

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recusive(nums, 0, res);
        return res;
    }
    
    void recusive(vector<int> &nums, int k, vector<vector<int>> &res){
        if(k == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = k; i < nums.size(); i++){
            swap(nums[k], nums[i]);
            recusive(nums, k+1, res);
            swap(nums[k], nums[i]);
        }
    }
    
};




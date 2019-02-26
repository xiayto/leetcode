//递归版本：
//用时：24ms
//内存消耗：12.7MB

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        res.push_back(item);
        generateSubsets(res, item, nums, 0);
        return res;
    }
    
    void generateSubsets(vector<vector<int>> &res, vector<int> &item, vector<int> &nums, int i){
        if (i >= nums.size())
            return;
        item.push_back(nums[i]);
        res.push_back(item);
        generateSubsets(res, item, nums, i + 1);
        item.pop_back();
        generateSubsets(res, item, nums, i + 1);
    }
};

//位运算版本：
//用时：16ms
//内存消耗：9.1MB
//用循环解决问题，每一位对应数组中的一个数，0不加入，1加入。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsetNums = 1 << n;
        vector<vector<int>> res(subsetNums, vector<int>());
        for(int i = 0; i < subsetNums; i++){
            for(int j = 0; j < n; j++){
                if((i >> j) & 1)
                    res[i].push_back(nums[j]);
            }
        }
        return res;
    }
};

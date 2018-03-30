class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> item;
        generate(res, item, n, k, 1);
        return res;
    }
    
    void generate(vector<vector<int>> &res, vector<int> &item, int n, int k, int i){
        if(k == 0){
            res.push_back(item);
            return;
        }
        if(n-i+1 < k)
            return;
        item.push_back(i);
        generate(res, item, n, k-1, i+1);
        item.pop_back();
        generate(res, item, n, k, i+1);
    }
};

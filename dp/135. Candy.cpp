//贪心的思想，两遍找上升序列

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if(n == 0)
            return 0;
        vector<int> assign(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i-1] < ratings[i])
                assign[i] = assign[i-1] + 1;
        }
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                if(assign[i+1] + 1 > assign[i])
                    assign[i] = assign[i+1] + 1;
        }
        int res = 0;
        for(int i = 0; i < assign.size(); i++)
            res += assign[i];
        return res;
    }
};

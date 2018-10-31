class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //先映射到hash表中。
        unordered_map<string, int> hashMap;
        for(int i = 0; i < words.size(); i++)
            hashMap[words[i]]++;
        
        //用优先队列代表小根堆，维护一个k大的小根堆
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> smallHeap;
        for(auto it = hashMap.begin(); it != hashMap.end(); it++){
            if(smallHeap.size() < k){
                smallHeap.push(make_pair(it->second, it->first));
            }
            else{
                pair<int, string> tmpTop = smallHeap.top();
                if(tmpTop.first < it->second || (tmpTop.first == it->second && tmpTop.second > it->first)){
                    smallHeap.pop();
                    smallHeap.push(make_pair(it->second, it->first));
                }
            }
        }
        
        // 排序
        vector<pair<int, string>> tmp;
        while(!smallHeap.empty()){
            tmp.push_back(smallHeap.top());
            smallHeap.pop();
        }
        sort(tmp.begin(), tmp.end(), myCompare);
        vector<string> res;
        for(int i = 0; i < tmp.size(); i++){
            res.push_back(tmp[i].second);
        }
        return res;
    }

private:
    struct cmp{
        bool operator() (pair<int, string> p1, pair<int, string> p2){
            if(p1.first == p2.first)
                return p1.second < p2.second;
            else
                return p1.first > p2.first;
        }
    };
    
    static bool myCompare(pair<int, string> p1, pair<int, string> p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        else{
            return p1.first > p2.first;
        }
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet;
        for(int t = 0; t < wordDict.size(); t++){
            wordSet.insert(wordDict[t]);
        }
        int n = s.size();
        if(n == 0)
            return true;
        vector<bool> bVec(n+1, false);
        bVec[0] = true;
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(bVec[j]){
                    if(isInSet(s, j, i, wordSet) == true){
                        bVec[i+1] = true;
                        break;
                    }
                }
            }
        }
        return bVec[n];
    }
    
    bool isInSet(string s, int i, int j, set<string> &dict){
        string temp = s.substr(i, j-i+1);
        if(dict.find(temp) == dict.end())
            return false;
        else
            return true;
    }
};

// 构造图，用邻接链表表示图，用广度优先搜索

bool connect(const string &word1, const string &word2){
    int count = 0;
    for (int i = 0; i < word1.length(); i++){
        if (word1[i] != word2[i]){
            count ++;
        }
    }
    return count == 1;
}

void construct_graph(string &beginWord, vector<string> &wordList, 
                    map<string, vector<string>> &graph){
    wordList.push_back(beginWord);
    //初始化图
    for (int i = 0; i < wordList.size(); i++){
        graph[wordList[i]] = vector<string>();
    }
    for (int i = 0; i < wordList.size(); i++){
        for (int j = i+1; j < wordList.size(); j++){
            if (connect(wordList[i],wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    } 
}

int BFS(string &beginWord, string &endWord, map<string, vector<string>> &graph){
    queue<pair<string, int>> Q;
    set<string> visit;
    Q.push(make_pair(beginWord, 1));
    visit.insert(beginWord);
    while (!Q.empty()){
        string node = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        if (node == endWord){
            return step;
        }
        const vector<string> &neighbors = graph[node];
        for (int i = 0; i < neighbors.size(); i++){
            if (visit.find(neighbors[i]) == visit.end()){
                Q.push(make_pair(neighbors[i], step + 1));
                visit.insert(neighbors[i]);
            }
        }
    }
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> graph;
        construct_graph(beginWord, wordList, graph);
        return BFS(beginWord, endWord, graph);
    }
};

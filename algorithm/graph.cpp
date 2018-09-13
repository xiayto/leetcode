//图的定义
struct GraphNode{
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x):label(x){}
};

//-----------------------------------------------------------------------

// 给数组赋予初值，memset函数 memset(数组名, value, n*sizeof(int))
int a[50];
memset(a, 0, 50*sizeof(int));
//深度优先搜索
void DFS(GrpahNode *node, int visit[]){
    visit[node->label] == 1;
    for(int i=0; i<node->neighbors.size(); i++){
        if(visit[node->neighbors[i]->label] == 0){
            DFS(node->neighbors[i], visit);
        }
    }
}

// leetcode 207 变为考察图中有无环
struct GraphNode{
    int val;
    vector<GraphNode*> neighbors;
    GraphNode(int x):val(x){};
};

bool DFS(GraphNode* node, vector<int> &visit){
    visit[node->val] = 0;
    for(int i = 0; i < node->neighbors.size(); i++){
        if(visit[node->neighbors[i]->val] == -1){
            if(DFS(node->neighbors[i], visit) == 0){
                return false;
            }
        }
        else if(visit[node->neighbors[i]->val] == 0){
            return false;
        }
    }
    visit[node->val] = 1;
    return true;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit;
        vector<GraphNode*> graph;
        for(int i = 0; i < numCourses; i++){
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        for(int i = 0; i < prerequisites.size(); i++){
            GraphNode* end = graph[prerequisites[i].first];
            GraphNode* begin = graph[prerequisites[i].second];
            begin->neighbors.push_back(end);
        }
        for(int i = 0; i < graph.size(); i++){
            if(!DFS(graph[i], visit) || visit[i] == -1)
                return false;
        }
        for (int i = 0; i < numCourses; i++){
            delete graph[i];
        }
        return true;
    }
};


//-----------------------------------------------------------------------

//广度优先搜索
void BFS(GraphNode* node, int visit[]){
    queue<GraphNode*> Q;
    Q.push(node);
    visit[node->label] = 1;
    while(!Q.empty()){
        GrpahNode *node = Q.front();
        Q.pop();
        for(int i=0; i < node->neighbors.size(); i++){
            if(visit[node->neighbors[i]->label] == 0){
                Q.push(node->neighbors[i]);
                visit[node->neighbors[i]->label] = 1;
            }
        }
    }
}

// leetcode 207 广度优先解法，入度为0的节点加入队列






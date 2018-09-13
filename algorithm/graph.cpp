//图的定义
struct GraphNode{
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x):label(x){}
};

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

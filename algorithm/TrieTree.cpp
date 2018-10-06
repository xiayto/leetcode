// 数据结构定义：
#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false){
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
            child[i] = 0;
        }
    }
};

// 获取全部单词：（递归的读取整个树）
void get_all_word_from_trie(TrieNode *node, string &word, vector<string> &word_list){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
        if (node->child[i]){
            word.push_back(i + 'a');
            if (node->child[i]->is_end){
                word_list.push_back(word);
            }
            get_all_word_from_trie(node, word, word_list);
            word.erase(word.length()-1, 1);   //删除 erase(pos, n) 从pos开始删除n个
        }
    }
}

//插入
void insert(const char *word, TrieNode root){
    TrieNode *ptr = &root;
    while(word){
        int pos = *word - 'a';      // -a可找到英文字母对应的数字
        if (!ptr->child[pos]){
            ptr->child[pos] = new TrieNode();      // 无路径是0，有路径放一个TrieNode
        }
        ptr = ptr->child[pos];
        word++;
    }
    ptr->is_end = true;         //最后标记这个单词
}

//搜索，与插入类似
bool search(const char *word, TrieNode root){
    TrieNode *ptr = &root;
    while(word){
        int pos = *word - 'a';
        if(!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        word++;
    }
    return ptr->is_end;
}

//前缀查询
//搜索是否存在前缀，与字符串搜索类似，最后不是返回is_end而是存在就返回true。
bool startsWith(const char *word, TrieNode *root){
    TrieNode *ptr = root;
    while(word){
        int pos = *word - 'a';
        if(!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        word++;
    }
    return true;
}








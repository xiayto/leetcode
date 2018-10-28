#define TRIE_MAX_CHAR_NUM 26

struct TrieNode{
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    bool is_end = false;
    TrieNode() : is_end(false){
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
            child[i] = 0;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = &root;
        for(int i = 0; i < word.length(); i++){
            int pos = word[i] - 'a';
            if(!ptr->child[pos])
                ptr->child[pos] = new TrieNode();
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = &root;
        for(int i = 0; i < word.length(); i++){
            int pos = word[i] - 'a';
            if(!ptr->child[pos])
                return false;
            ptr = ptr->child[pos];
        }
        return ptr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = &root;
        for(int i = 0; i < prefix.length(); i++){
            int pos = prefix[i] - 'a';
            if(ptr->child[pos] == 0)
                return false;
            ptr = ptr->child[pos];
        }
        return true;
    }
private:
    TrieNode root; 
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

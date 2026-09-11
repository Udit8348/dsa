class PrefixTree {
    array<PrefixTree*, 26> children {};
    // char c;
    bool is_end = false;

public:
    PrefixTree() {}
    
    void insert(string word) {
        PrefixTree* curr = this;
        PrefixTree* prev = nullptr;   
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new PrefixTree();
            }
            prev = curr;
            curr = curr->children[index];
        }

        // mark the node containing the last char as the end of some input
        prev->is_end = true;
    }
    
    // check if we end on a true
    bool search(string word) {
        PrefixTree* curr = this;
        PrefixTree* prev = nullptr;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            prev = curr;
            curr = curr->children[index];
        }

        return prev->is_end;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        PrefixTree* prev = nullptr;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            prev = curr;
            curr = curr->children[index];
        }

        return true;
    }
};

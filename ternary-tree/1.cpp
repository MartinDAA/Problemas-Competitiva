class WordDictionary {
private:
    struct Node {
        char c;
        Node* left;
        Node* mid;
        Node* right;
        bool isEnd;
        Node(char ch = 0) : c(ch), left(nullptr), mid(nullptr), right(nullptr), isEnd(false) {}
    };

    Node* root = nullptr;

    void insert(Node*& x, const string& word, int pos) {
        if (!x) x = new Node(word[pos]);
        if (word[pos] < x->c)
            insert(x->left, word, pos);
        else if (word[pos] > x->c)
            insert(x->right, word, pos);
        else {
            if (pos == word.size() - 1)
                x->isEnd = true;
            else
                insert(x->mid, word, pos + 1);
        }
    }

    bool search(Node* x, const string& word, int pos) {
        if (!x) return false;
        if (pos == word.size()) return x->isEnd;  // por seguridad

        char ch = word[pos];
        if (ch == '.') {
            if (pos == word.size() - 1 && x->isEnd) return true;

            if (search(x->left, word, pos)) return true;
            if (search(x->right, word, pos)) return true;

            if (pos + 1 < word.size()) {
                if (search(x->mid, word, pos + 1)) return true;
            }
            return false;
        } else {
            if (ch < x->c) return search(x->left, word, pos);
            if (ch > x->c) return search(x->right, word, pos);
            if (pos == word.size() - 1) return x->isEnd;
            return search(x->mid, word, pos + 1);
        }
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        insert(root, word, 0);
    }

    bool search(string word) {
        return search(root, word, 0);
    }
};
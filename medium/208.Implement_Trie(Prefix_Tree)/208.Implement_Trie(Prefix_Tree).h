#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() {
        isEnd = false;
        next = vector<Trie*>(26);
    }
    
    void insert(string& word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string& word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return false;
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return false;
            }
        }
        return true;
    }

private:
    bool isEnd;
    vector<Trie*> next;
};
/*
Implement Trie (Prefix Tree)

A prefix tree (also known as a trie) is a tree data structure used to efficiently store and retrieve keys in a set of strings. Some applications of this data structure include auto-complete and spell checker systems.

Implement the PrefixTree class:

PrefixTree() Initializes the prefix tree object.
void insert(String word) Inserts the string word into the prefix tree.
boolean search(String word) Returns true if the string word is in the prefix tree (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/
class TrieNode {
    public:
    bool end_of_word;
    TrieNode* children[26];

   
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        end_of_word = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word) {
            int i = c - 'a';
            if(curr->children[i] == nullptr) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->end_of_word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word) {
            int i = c - 'a';
            if(curr->children[i] == nullptr) {
                return false;
            }
            curr = curr->children[i];
        }
        return curr->end_of_word;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix) {
            int i = c - 'a';
            if(curr->children[i] == nullptr){
                return false;
            }
            curr = curr->children[i];
        }
        return true;
    }
};

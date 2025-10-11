#include <iostream>
#include <string>
using namespace std;

// Node structure for Trie
struct Node {
    Node* links[26];  // Array to store links to child nodes for each character 'a' to 'z'
    bool flag = false; // Flag to indicate end of a word

    // Checks if there is a link (child) for the given character
    bool containskey(char ch) { 
        return (links[ch - 'a'] != NULL); 
    }

    // Puts a new node for the given character link
    void put(char ch, Node* node) { 
        links[ch - 'a'] = node; 
    }

    // Gets the node linked to given character
    Node* get(char ch) { 
        return links[ch - 'a']; 
    }

    // Marks this node as end of a word
    void setEnd() { 
        flag = true; 
    }

    // Checks if this node is end of a word
    bool isEnd() { 
        return flag; 
    }
};

// Trie data structure
class Trie {
private:
    Node* root;

public:
    // Constructor initializes root node
    Trie() { 
        root = new Node(); 
    }

    // Inserts a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i])) {
                node->put(word[i], new Node());
            }
            // Move to the next reference node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    // Searches for a whole word in the Trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    // Checks if there is any word that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containskey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Searching for words
    cout << boolalpha; // Print boolean values as true/false
    cout << "Search 'apple': " << trie.search("apple") << endl;  // true
    cout << "Search 'app': " << trie.search("app") << endl;      // true
    cout << "Search 'apples': " << trie.search("apples") << endl;// false

    // Searching prefixes
    cout << "Starts with 'app': " << trie.startsWith("app") << endl;  // true
    cout << "Starts with 'bat': " << trie.startsWith("bat") << endl;  // true
    cout << "Starts with 'cat': " << trie.startsWith("cat") << endl;  // false

    return 0;
}

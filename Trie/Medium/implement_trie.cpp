/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/ 

class trieNode
{
public:
    unordered_map<char, trieNode*>child; //Every character of string has link to map
    bool endFlag;   
};

class Trie 
{
    trieNode* root; 
public:
    Trie() 
    {
        root = new trieNode();
    }
    
    void insert(string word) 
    {
        trieNode* current = root; //Set current to root and check if current is null then return
        if (root == NULL)
            return;
        //Iterate through all characters of given word to be inserted and check if count of char in map is 0 or not
        //if cout is 0, means new then create new trie node and once finish with all chars, set endFlag to true.
        for(auto x: word)
        {
            if(current->child.count(x)==0)
            {
                current->child[x] = new trieNode();
            }
            current = current->child[x];
        }
        current->endFlag = true;
    }
    
    bool search(string word) 
    {
        trieNode* current = root;
        if (root==NULL)
            return false;
        for(auto x: word)
        {
            if(current->child.count(x)==0)
            {
                return false;
            }
            current = current->child[x];
        }
        return current->endFlag;
        
    }
    
    bool startsWith(string prefix) 
    {
        trieNode* current = root;
        if (root==NULL)
            return false;
        for(auto x: prefix)
        {
            if(current->child.count(x)==0)
            {
                return false;
            }
            current = current->child[x];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

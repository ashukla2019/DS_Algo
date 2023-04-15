#include <iostream>
#include <unordered_map>
using namespace std;

class Trie 
{
public:
    Trie()
    {
        leaf = false;
    }
 
    unordered_map<char, Trie*> children;
    bool leaf;
    
    void add(string s) 
    {
        auto root = this;
        for (const auto &n: s) 
        {
            if (!root->children[n]) 
            {
                root->children[n] = new Trie();
            }
            root = root->children[n];
        }
        root->leaf = true;
    }
 
    bool exists(string word) 
    {
        auto root = this;
        for (const auto &n: word) 
        {
            if (!root->children[n]) 
            {
                return false;
            }
            root = root->children[n];
        }        
        return root && root->leaf;
    }
 
    bool startswith(string p) 
    {
        auto root = this;
        for (const auto &n: p) 
        {
            if (!root->children[n]) 
            {
                return false;
            }
            root = root->children[n];
        }        
        return root != NULL;      
    }
};

int main()
{
    Trie trie;
    trie.add("hello");
    bool startwith = trie.startswith("hel"); // true
    bool exist = trie.exists("hel");
    cout<<"startwith"<<startwith<<"\n";
    cout<<"exist"<<exist<<"\n";
    return 0;
}
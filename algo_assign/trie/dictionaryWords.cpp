#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    TrieNode *getRoot()
    {
        return root;
    }

private:
    TrieNode *root;
};

bool wordBreakUtil(const string &s, TrieNode *root, int start, vector<string> &temp, vector<string> &result)
{
    if (start == s.size())
    {
        result = temp;
        return true;
    }

    TrieNode *node = root;
    for (int end = start; end < s.size(); ++end)
    {
        char c = s[end];
        if (node->children.find(c) == node->children.end())
        {
            break;
        }
        node = node->children[c];
        if (node->isEndOfWord)
        {
            temp.push_back(s.substr(start, end - start + 1));
            if (wordBreakUtil(s, root, end + 1, temp, result))
            {
                return true;
            }
            temp.pop_back(); // backtrack
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    Trie trie;
    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;
        trie.insert(word);
    }

    string s;
    cin >> s;

    vector<string> temp, result;
    if (wordBreakUtil(s, trie.getRoot(), 0, temp, result))
    {
        cout << "yes\n";
        for (const string &word : result)
        {
            cout << word << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "no\n";
    }

    return 0;
}

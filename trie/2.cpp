#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26] = {};
    int endOf = -1;
};

class Solution {
    TrieNode root;

    void add(string &s, int i) {
        auto node = &root;
        for (auto c: s){
            int idx = c - 'a';
            if (!node->next[idx]){
                node->next[idx] = new TrieNode();
            }
            node = node->next[idx];
        }
        node->endOf = i;
    }

    string dfs(vector<string>& words){
        string ans = "";
        stack<TrieNode*> stack;
        stack.push(&root);
        while (!stack.empty()){
            auto node = stack.top();
            stack.pop();
            if (node->endOf >= 0 || node == &root){
                if (node != &root){
                    string s = words[node->endOf];
                    if (s.size() > ans.size() || s.size() == ans.size() && s < ans){
                        ans = s;
                    }
                }
                for (int i=0; i<26; i++){
                    if (node->next[i])
                        stack.push(node->next[i]);
                }
            }
        }
        return ans;
    }
    
public:
    string longestWord(vector<string>& words) {
        for (int i=0; i<words.size(); i++) add(words[i], i);

        return dfs(words);
    }
};

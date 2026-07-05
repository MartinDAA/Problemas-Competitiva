#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
    TrieNode root; // suffix trie

    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) i++, j--;
        return i >= j;
    }

    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i);
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i);
    }

    void search(vector<string> &words, int i, vector<vector<int>> &ans){
        auto s = words[i];
        auto node = &root;
        for (int j = 0; j < s.size(); j++) {
            if (node->index != -1 &&
            node->index != i &&
            isPalindrome(s, j, s.size() - 1)){
                ans.push_back({ i, node->index }); 
            }
            int c = s[j] - 'a';
            node = node->next[c];
            if (!node) return;
        }
        for (int j : node->palindromeIndexes) { 
            if (i != j) ans.push_back({ i, j });
        }
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();

        for (int i = 0; i < n; i++)
            add(words[i], i);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            search(words, i, ans);

        return ans;
    }
};

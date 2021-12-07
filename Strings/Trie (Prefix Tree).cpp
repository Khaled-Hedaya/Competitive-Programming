#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);

const int SIZE = 26; // assuming that we deal with small english letters only (a-z)

struct node {
    int cnt; // represents how many times we path through the current node - (helps in counting prefixes)
    bool endOfWord;
    node *childs[SIZE];

    node() {
        cnt = 0;
        endOfWord = 0;
        for (int i = 0; i < SIZE; ++i)
            childs[i] = nullptr;
    }

    ~node() {
        for (int i = 0; i < SIZE; ++i) {
            if (childs[i] != nullptr)
                delete childs[i];
        }
    }
};

struct Trie {
    void insert(node *root, string s) {
        node *tmp = root;
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (tmp->childs[idx] == nullptr)
                tmp->childs[idx] = new node();
            tmp = tmp->childs[idx];
        }
        tmp->endOfWord = 1;
    }

    bool search(node *root, string s) {
        node *tmp = root;
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (tmp->childs[idx] == nullptr)
                return false;
            tmp = tmp->childs[idx];
        }
        return tmp->endOfWord;
    }

    void delNode(int n, node *root) {
        node *tmp = root;
        for (int i = 30; i >= 0; i--) {
            bool byt = n & (1 << i);
            tmp = tmp->childs[byt];
            tmp->cnt--;
        }
    }
};


int main() {
//    FastIO()
//#ifdef ONPC
//    freopen("in.txt", "r", stdin);
//#endif

    node *root = new node();
    Trie tr;
    for (int i = 0; i < 3; ++i) {
        int typ;
        string s;
        cin >> typ;
        cin >> s;
        if (typ == 1) {
            tr.insert(root, s);
        } else {
            if (tr.search(root, s))
                cout << "Yes, Found\n";
            else
                cout << "No, Not found\n";
        }
    }

    delete root;
    return 0;
}

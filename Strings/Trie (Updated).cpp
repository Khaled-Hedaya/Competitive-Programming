#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 5e3 + 10, M = 1e2 + 7, OO = 0x3f3f3f3f, mod = 1e9 + 7;



typedef struct trienode
{
	int cntPrefix;
	trienode *child[26];
	bool isEnd;

	trienode() {
		cntPrefix = 0;
		isEnd = false;
		for (int i = 0 ; i < 26; ++i)
			child[i] = nullptr;
	}
	~trienode() {
		for (int i = 0 ; i < 26; ++i)
			delete child[i];
	}

} trienode;



void insert(trienode*root, string word) {
	int n = (int)word.size();
	trienode *tmp = root;
	for (int i = 0 ; i < n; ++i) {
		int index = word[i] - 'a';
		if (tmp->child[index] == nullptr)
			tmp->child[index] = new trienode();
		tmp = tmp->child[index];
	}
	tmp->isEnd = true;
}
bool search(trienode *root, string word) {
	trienode *tmp = root;
	int len = (int)word.size();
	for (int i = 0 ; i < len; ++i) {
		int index = word[i] - 'a';
		if (tmp->child[index] == nullptr)
			return false;
		tmp = tmp->child[index];
	}
	return (tmp->isEnd);
}

bool isLeaf(trienode *node) {

	for (int i = 0 ; i < 26; ++i) {
		if (node->child[i])
			return 0;
	}
	return 1;
}

trienode * delnode(trienode *root, string word, int depth = 0) {

	if (!root) return nullptr;

	if (depth == (int)word.size()) {
		if (root->isEnd)
			root->isEnd = false;
		if (isLeaf(root)) {
			delete root;
			root = nullptr;
		}
		return root;
	}
	int index = word[depth] - 'a';
	root->child[index] = delnode(root->child[index], word, depth + 1);
	if (isLeaf(root) && root->isEnd == false) {
		delete root;
		root = nullptr;
	}
	return root;
}



int main() {
	FastIO()

#ifdef ONPC
	freopen("inp.txt", "r" , stdin);
	freopen("out.txt", "w", stdout);
#endif


	string keys[] = { "the", "a", "there",
	                  "answer", "any", "by",
	                  "bye", "their", "hero", "heroplane"
	                };

	int n = sizeof(keys) / sizeof(keys[0]);

	trienode* root = new trienode();


	//Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	// Testing !!
	search(root, "the") ? cout << "Yes" : cout << "No";
	cout << "\n";
	search(root, "these") ? cout << "Yes" : cout << "No";
	cout << "\n";
	cout.flush();
	cout << "##################\n";
	search(root, "heroplane") ? cout << "Yes" : cout << "No";
	cout << "\n";
	delnode(root, "heroplane");
	//search(root, "hero") ? cout << "Yes" : cout << "No";
	search(root, "heroplane") ? cout << "Yes" : cout << "No";
	cout << "\n";
	delnode(root, "ahmed");
	search(root, "ahmed") ? cout << "Yes" : cout << "No";
	cout << "\n";
	insert(root, "ahmed");
	search(root, "ahmed") ? cout << "Yes" : cout << "No";
	cout << "\n";

	delete root;


	return 0;
}

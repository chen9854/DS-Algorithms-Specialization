#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next[Letters];
	struct Node *children[Letters];
	bool is_leaf;

	Node ()
	{
		fill (next, next + Letters, NA);
		is_leaf = false;
		for (int i = 0; i < Letters; ++i)
        	this->children[i] = NULL;
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

struct Node* buildTrie(const vector <string>& patterns) {
	struct Node* root = new Node;
	for (auto pattern : patterns) {
		struct Node* curr = root;
		for (int i = 0; i < pattern.size(); ++i) {
			int index = letterToIndex(pattern[i]);
			if (!curr->children[index]) {
				curr->children[index] = new Node;
			}
			curr = curr->children[index];
		}
		curr->is_leaf = true;
	}
	return root;
}

vector<int> trieMatching(const string& text, struct Node* trie) {
	vector<int> result;
	string tmp = text;
	for (int i = 0; i < text.size(); ++i) {
		struct Node* curr = trie;
		for (int j = i; j < text.size(); ++j) {
			int index = letterToIndex(text[j]);
			if (!curr->children[index]) {
				break;
			}
			curr = curr->children[index];
		}
		if (curr->is_leaf) {
			result.push_back(i);
		}
	}
	return result;
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

	// write your code here
	// make the patterns into a trie
	struct Node* root = buildTrie(patterns);
	// trimamtching
	result = trieMatching(text, root);
	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}

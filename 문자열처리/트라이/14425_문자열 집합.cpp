#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int ptr_num = 26;

struct Trie {
	Trie* child[ptr_num];
	bool finish;
	Trie() {
		fill(child, child + ptr_num, nullptr);
		finish = false;
	}
	~Trie() {
		for (int i = 0; i < ptr_num; i++)
			if (child[i])
				delete child[i];
	}
	void insert(char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int next = *key - 'a';
			if (!child[next])
				child[next] = new Trie;
			child[next]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (*key == '\0') {
			if (finish)
				return true;
			else
				return false;
		}
		else {
			int next = *key - 'a';
			if (!child[next])
				return false;
			else
				return child[next]->find(key + 1);
		}
	}
	void order(char* str, int depth) {
		if (finish)
			printf("%s\n", str);
		for (int i = 0; i < 26; i++) {
			if (child[i]) {
				str[depth] = i + 'a';
				str[depth + 1] = '\0';
				child[i]->order(str, depth + 1);
			}
		}
	}
};

int main() {
	int n, m, cnt = 0;
	scanf("%d%d", &n, &m);
	Trie* root = new Trie;
	for (int i = 0; i < n; i++) {
		char arr[501];
		scanf("%s", &arr);
		root->insert(arr);
	}
	for (int i = 0; i < m; i++) {
		char temp[501];
		scanf("%s", &temp);
		if (root->find(temp))
			cnt++;
	}
	delete root;
	printf("%d", cnt);
}
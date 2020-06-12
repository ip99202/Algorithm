#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int ptr_num = 95;
int num;

struct Trie {
	Trie* child[ptr_num];
	int finish;
	Trie() {
		fill(child, child + ptr_num, nullptr);
		finish = 0;
	}
	~Trie() {
		for (int i = 0; i < ptr_num; i++)
			if (child[i])
				delete child[i];
	}
	void insert(char* key) {
		if (*key == '\0')
			finish += 1;
		else {
			int next = *key - ' ';
			if (!child[next])
				child[next] = new Trie;
			child[next]->insert(key + 1);
		}
	}
	void order(char* str, int depth) {
		if (finish)
			printf("%s %.4lf\n", str, (double)finish / (double)num * 100);
		for (int i = 0; i < ptr_num; i++) {
			if (child[i]) {
				str[depth] = i + ' ';
				str[depth + 1] = '\0';
				child[i]->order(str, depth + 1);
			}
		}
	}
};

int main() {
	char arr[31];
	Trie* root = new Trie;
	while (scanf("%[^\n]", arr) != EOF) {
		getchar();
		num++;
		root->insert(arr);
	}
	root->order(arr, 0);
	delete root;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1 << 18;
int a[MAXN];
int N, M;

struct Node{
	int leftIndex, rightIndex;
	int value;
	bool useOr;
	
	struct Node *left, *right;
	
	void insert(int index, int value){
		if (leftIndex == index && rightIndex == index){
			this->value = value;
		}
		else {
			int mid = (leftIndex + rightIndex) / 2;
			
			if (index <= mid) left->insert(index, value);
			else right->insert(index, value);
			
			if (useOr) this->value = left->value | right->value;
			else this->value = left->value ^ right->value;
		}
	}
};

struct Node* build(int left, int right, bool useOr){
	struct Node* cur = (Node*) malloc(sizeof(Node));
	cur->useOr = useOr;
	cur->leftIndex = left;
	cur->rightIndex = right;
	
	if (left == right){
		cur->value = a[left];
		cur->left = NULL;
		cur->right = NULL;
	}
	else {
		int mid = (left + right) / 2;	
		cur->left = build(left, mid, !useOr);
		cur->right = build(mid + 1, right, !useOr);
		if (useOr) cur->value = cur->left->value | cur->right->value;
		else cur->value = cur->left->value ^ cur->right->value;
	}
	
	return cur;
}

int main(){
	cin >> N >> M;
	
	for (int i = 0; i < (1 << N); i++) cin >> a[i];
	
	struct Node* top = build(0, (1 << N) - 1, N % 2);
	for (int i = 0, p, b; i < M; i++){
		cin >> p >> b;
		top->insert(p - 1, b);
		cout << top->value << endl;
	}
}
//
// Created by Sandeep on 4/1/2019.
//
#include "bits/stdc++.h"
using namespace std;
class node {
public:
	int row;
	int col;
	int k_left;
	char v;
	node(int row, int col, int k_left, char v) {
		this->row = row;
		this->col = col;
		this->k_left = k_left;
		this->v = v;
	}
};
bool check(int row, int col, int n) {
	if (row < n && col < n)
		return true;
	return false;
}
vector< vector<node*> > vec(2007, vector<node*>(2007));
char inp[2007][2007];
queue<node*> q;

void processNode(node* top, int row, int col) {

	if (top->k_left > 0 && inp[row][col] != 'a') {
		if (vec[row][col]->k_left < top->k_left - 1) {
			vec[row][col]->row = top->row;
			vec[row][col]->col = top->col;
			vec[row][col]->k_left = top->k_left - 1;
			vec[row][col]->v = 'a';
			q.push(new node(row, col, top->k_left - 1, 'a'));
		}
		else if (vec[row][col]->k_left == (top->k_left - 1) && ((int)vec[row][col]->v >= (int)top->v)) {
			vec[row][col]->row = top->row;
			vec[row][col]->col = top->col;
			vec[row][col]->k_left = top->k_left;
			vec[row][col]->v = top->v;
			q.push(new node(row, col, top->k_left, top->v));
		}
	}
}

int main() {
	int n, k;
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) vec[i][j] = new node(-1, -1, -1, 'z');
	}
	cin >> n;
	cin >> k;


	for (int i = 0; i < n; i++) {
		cin >> inp[i];
	}
	if (k > 0 && inp[0][0] != 'a') {
		q.push(new node(0, 0, k - 1, 'a'));
	}
	else {
		q.push(new node(0, 0, k, inp[0][0]));
	}
	while (!q.empty()) {
		node* top = q.front();
		int row = top->row;
		int col = top->col + 1;
		if (check(row, col, n)) {
			processNode(top, row, col);
		}
		row = top->row + 1;
		col = top->col;
		if (check(row, col, n)) {
			processNode(top, row, col);
		}
	}
	cout << " the bottom down corner the k left is " << vec[n - 1][n - 1]->k_left << endl;


	return 0;
}




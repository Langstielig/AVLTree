#pragma once

struct Tree {
	int data;
	int high;
	Tree* left;
	Tree* right;
};

typedef Tree* TTree;

void init(TTree& root) {
	root = nullptr;
}

void init(TTree& root, int elem) {
	root = new Tree;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}

void init(TTree& root, TTree leftTree, TTree rightTree, int elem) {
	root = new Tree;
	root->data = elem;
	root->left = leftTree;
	root->right = rightTree;
}

int height(TTree pNode) {
	return pNode ? pNode->high : 0;
}

int balanceFactor(TTree pNode) {
	return height(pNode->left) - height(pNode->right);
}

void fixHeight(TTree pNode) {
	int hLeft = height(pNode->left);
	int hRight = height(pNode->right);
	pNode->high = (hLeft > hRight ? hLeft : hRight) + 1;
}

void insert(TTree root)
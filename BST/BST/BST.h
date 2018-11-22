#ifndef BST_H
#define BST_H
#include "TreeNode.h"

class BST {

public:
	// public functions
	void addItem(int item);
	TreeNode* deleteItem(TreeNode *root, int item);
	void searchList(int item);
	void traversePre();
	void traverseIn();
	void traversePost();
	TreeNode* findMin(TreeNode* root);
	TreeNode* getRoot();

private:
	// private datatypes
	TreeNode *root = nullptr;
	// private functions
	void addFunc(TreeNode *cur, int item);
	bool searchFunc(TreeNode *cur, int item);
	void traversePreFunc(TreeNode *cur);
	void traverseInFunc(TreeNode *cur);
	void traversePostFunc(TreeNode *cur);
};

#endif
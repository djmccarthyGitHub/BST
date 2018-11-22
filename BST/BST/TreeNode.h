#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

class TreeNode {
	friend class BST;

public:
	//default constructor
	TreeNode() {
		Lchild = Rchild = nullptr;
	}

	//explicit value constructor
	TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0) : item(i), Lchild(L), Rchild(R) {

	}

	// accessor function
	int getItem() const {
		return item;
	}

private:
	int item;
	TreeNode *Lchild;
	TreeNode *Rchild;
};

#endif
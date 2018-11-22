#include "BST.h"
# include <iostream>

/*
This function takes in an int parameter and decides
how it will be added to the tree
*/
void BST::addItem(int item) {
	if (root) {
		addFunc(root, item);
	}
	else {
		root = new TreeNode(item);
	}
}

/*
This function takes in a TreeNode root and an int and
deletes the TreeNode with the corresponding int. If no
int is found it returns the root it was given
*/
TreeNode* BST::deleteItem(TreeNode *root, int item) {
	if (root == NULL) {
		cout << "Item not found" << endl;
		return root;
	}
	else if (item < root->item) root->Lchild = deleteItem(root->Lchild, item);
	else if (item > root->getItem()) root->Rchild = deleteItem(root->Rchild, item);
	else {
		if (root->Lchild == NULL && root->Rchild == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->Lchild == NULL) {
			TreeNode *temp = root;
			root = root->Rchild;
			delete temp;
		}
		else if (root->Rchild == NULL) {
			TreeNode *temp = root;
			root = root->Lchild;
			delete temp;
		}
		else {
			TreeNode *temp = findMin(root->Rchild);
			root->item = temp->item;
			root->Rchild = deleteItem(root->Rchild, temp->item);
		}
		cout << "Item " << item << " was deleted from the list" << endl;
	}
	return root;
}

/*
This function searchs the BST for the int inside of
its parameter and outputs a line stating if the value
was found in the tree
*/
void BST::searchList(int item) {
	if (root) {
		if (searchFunc(root, item)) {
			cout << "Item " << item << " was found in the Tree" << endl;
		}
		else {
			cout << "Item " << item << " was not found in the Tree" << endl;
		}
	}
	else {
		cout << "List is empty" << endl;
	}
}

/*
This function decides if the BST can be traversed
 in preorder
*/
void BST::traversePre() {
	if (root) {
		traversePreFunc(root);
		cout << endl;
	}
	else {
		cout << "List is empty" << endl;
	}
}

/*
This function decides if the BST can be traversed
 inorder
*/
void BST::traverseIn() {
	if (root) {
		traverseInFunc(root);
		cout << endl;
	}
	else {
		cout << "List is empty" << endl;
	}
}

/*
This function decides if the BST can be traversed
 in postorder
*/
void BST::traversePost() {
	if (root) {
		traversePostFunc(root);
		cout << endl;
	}
	else {
		cout << "List is empty" << endl;
	}
}

/*
This algorithm adds uses the root of the BST and an
int in its parameter to create a new Node at the
correct position in the tree
*/
void BST::addFunc(TreeNode *cur, int item) {
	if (item < cur->getItem()) {
		if (cur->Lchild) {
			addFunc(cur->Lchild, item);
		}
		else {
			cur->Lchild = new TreeNode(item);
		}
	}
	else {
		if (cur->Rchild) {
			addFunc(cur->Rchild, item);
		}
		else {
			cur->Rchild = new TreeNode(item);
		}
	}
}

/*
This algorithm takes the root tree node and searches
through the BST for the item in its parameter.
Estimated search time is nlog(n)
*/
bool BST::searchFunc(TreeNode *cur, int item) {
	if (cur) {
		if (cur->getItem() == item) {
			return true;
		}
		if (cur->getItem() > item) {
			searchFunc(cur->Lchild, item);
		}
		else {
			searchFunc(cur->Rchild, item);
		}
	}
	else {
		return false;
	}
}

/*
This algortihm helps to traverse the list in preorder
*/
void BST::traversePreFunc(TreeNode *cur) {
	if (!cur) {
		return;
	}
	cout << cur->getItem() << " ";
	traversePreFunc(cur->Lchild);
	traversePreFunc(cur->Rchild);
}

/*
This algortihm helps to traverse the list inorder
*/
void BST::traverseInFunc(TreeNode *cur) {
	if (!cur) {
		return;
	}
	traverseInFunc(cur->Lchild);
	cout << cur->getItem() << " ";
	traverseInFunc(cur->Rchild);
}

/*
This algortihm helps to traverse the list in postorder
*/
void BST::traversePostFunc(TreeNode *cur) {
	if (!cur) {
		return;
	}
	traversePostFunc(cur->Lchild);
	traversePostFunc(cur->Rchild);
	cout << cur->getItem() << " ";
}

/*
This function takes in the root of the BST and returns
the minimum value
*/
TreeNode* BST::findMin(TreeNode* root) {
	while (root->Lchild != NULL) root = root->Lchild;
	return root;
}

// return root
TreeNode* BST::getRoot() {
	return root;
}
#include "pch.h"
#include "BST.h"
#include "TreeNode.h"
#include <iostream>
#include <string>

void printMenu();
bool isNumber(string& input);

int main()
{
	// create Binary Search Tree
	BST tree;
	string input;

	// run program
	while (true) {
		printMenu();
		getline(cin, input);
		cout << endl;
		if (isNumber(input)) {
			if (stoi(input) <= 6 && stoi(input) >= 0) {
				switch (stoi(input)) {
				case 0:
					cout << "Enter the value to add to the Tree: " << endl;
					getline(cin, input);
					cout << endl;
					if (isNumber(input)) {
						tree.addItem(stoi(input));
					}
					else {
						cout << "Invalid input" << endl;
					}
					break;
				case 1:
					cout << "Search the Tree for: " << endl;
					getline(cin, input);
					cout << endl;
					if (isNumber(input)) {
						tree.searchList(stoi(input));
					}
					else {
						cout << "Invalid input" << endl;
					}
					break;
				case 2:
					cout << "Enter the value to delete from the Tree: " << endl;
					getline(cin, input);
					cout << endl;
					if (isNumber(input) && tree.getRoot()) {
						tree.deleteItem(tree.getRoot(), stoi(input));
					}
					else {
						cout << "Invalid input" << endl;
					}
					break;
				case 3:
					tree.traversePre();
					break;
				case 4:
					tree.traverseIn();
					break;
				case 5:
					tree.traversePost();
					break;
				case 6:
					return 0;
				default:
					break;
				}
			}
			else {
				cout << "Error in input";
			}
			cout << endl << endl;
		}
	}
}

// function that prints menu
void printMenu() {
	cout << " ---------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| 0: Add Node   1: Search Node   2: Delete Node   3: Print in Preorder   4: Print Inorder   5: Print in Postorder   6: Quit |" << endl;
	cout << " ---------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

/*
This function thats in a string as a parameter and
iterates through it. The function will return true
only if the entire string is a number
*/
bool isNumber(string& input) {
	string::const_iterator it = input.begin();
	while (it != input.end() && isdigit(*it)) ++it;
	return !input.empty() && it == input.end();
}
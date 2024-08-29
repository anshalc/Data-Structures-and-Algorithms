#include<iostream>
#include<queue>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;
	int see;
};

class AVLTree {
	
public:
	node* first;
	AVLTree():first(NULL){}                      //constructor
	void find(node*,node*, int,bool&);
	int calculateHeight(node*);                  //calculate the height of the tree
	int balanceFactor(node*);
	int size();                                   //number of nodes in the tree
	bool empty();                                 //check if tree is empty
	node* getEnd(node*);                          // get the special end node
	node* rightleftRotation(node*);
	node* rightrightRotation(node*);              // for balancing the tree after												
	node* leftrightRotation(node*);		          // insertion and deletion
	node* leftleftRotation(node*);
	node* insertNode(node*, int);
	void leveling1(node*);
	void leveling();                             //for displaying nodes
	node* deleteNode(node*, int);
	node* pre(node*);
	node* succ(node*);
	//~AVLTree();
};
bool AVLTree::empty() {
	if (first == NULL)
		return true;
	else
		return false;
}
int AVLTree::size() {
	int count = -1;
	if (this->first == NULL) {
		cout << endl;
		
		count = 0;
		return count;
	}
	else {
		queue<node*>q1;
		node* l = first;
		node* current;
		q1.push(l);
		q1.push(NULL);

		while (!q1.empty()) {
			current = q1.front();
			q1.pop();
			if (current == NULL && q1.size() != 0) {
				cout << endl;
				q1.push(NULL);
				continue;
			}

			if (current != NULL) {
				count++;
				
				if (current->left != NULL) {
					q1.push(current->left);
				}
				if (current->right != NULL) {
					q1.push(current->right);
				}
			}
		}
		return count+1;
	}
}
void AVLTree::find(node* root,node* temp,int item, bool& found) {
	
	if (root == NULL) {
		found = false;
	}
	else {

		queue<node*>q1;
		node* l = first;
		node* current;
		q1.push(l);
		q1.push(NULL);

		while (!q1.empty()) {
			current = q1.front();
			q1.pop();
			if (current == NULL && q1.size() != 0) {
				cout << endl;
				q1.push(NULL);
				continue;
			}

			if (current != NULL) {
				if (current->val == item) {
					found = true;
					break;
				}

				if (current->left != NULL) {
					q1.push(current->left);
				}
				if (current->right != NULL) {
					q1.push(current->right);
				}
			}
		}
		
	}
}

node* getEnd(node* root) {
	if (root == NULL || (root->right == NULL && root->left==NULL)) {
		return root;
	}
	else {
		getEnd(root->right);
	}
}

node* AVLTree::succ(node* l) {
	while (l->left != NULL) {
		l = l->left;
	}
	return l;
}
node* AVLTree::pre(node* l) {
	while (l->right != NULL) {
		l = l->right;
	}
	return l;
}

node* AVLTree::deleteNode(node* l, int val) {
	if (l->left == NULL && l->right == NULL) {
		if (l == this->first) {
			this->first = NULL;
		}
		delete l;
		return NULL;
	}

	node* x, * y;
	if (l->val < val) {
		l->right = deleteNode(l->right, val);
	}
	else if (l->val > val) {
		l->left = deleteNode(l->left, val);
	}
	else {
		if (l->left != NULL) {
			y = pre(l->left);
			l->val = y->val;
			l->left = deleteNode(l->left, y->val);
		}
		else {
			y = succ(l->right);
			l->val = y->val;
			l->right = deleteNode(l->right, y->val);
		}
	}

	if (balanceFactor(l) == 2 && balanceFactor(l->left) == 1) {
		l = leftleftRotation(l);
	}
	else if (balanceFactor(l) == 2 && balanceFactor(l->left) == -1) {
		l = leftrightRotation(l);
	}
	else if (balanceFactor(l) == 2 && balanceFactor(l->left) == 0) {
		l = leftleftRotation(l);
	}
	else if (balanceFactor(l) == -2 && balanceFactor(l->right) == -1) {
		l = rightrightRotation(l);
	}
	else if (balanceFactor(l) == -2 && balanceFactor(l->right) == 1) {
		l = rightleftRotation(l);
	}
	else if (balanceFactor(l) == -2 && balanceFactor(l->right) == 0) {
		l = leftleftRotation(l);
	}
	return l;
}
void AVLTree::leveling1(node* l) {
	queue<node*>q1;
	node* current;
	q1.push(l);
	q1.push(NULL);

	while (!q1.empty()) {
		current = q1.front();
		q1.pop();
		if (current == NULL && q1.size() != 0) {
			cout << endl;
			q1.push(NULL);
			continue;
		}

		if (current != NULL) {
			cout << " " << current->val;
			if (current->left != NULL) {
				q1.push(current->left);
			}
			if (current->right != NULL) {
				q1.push(current->right);
			}
		}
	}
}
void AVLTree::leveling() {
	if (this->first == NULL) {
		cout << endl;
		cout << "Empty tree" << endl;
		return;
	}
	leveling1(this->first);
}
node* AVLTree::insertNode(node* l, int val) {
	if (l == NULL) {
		node* newnode = new node;
		newnode->val = val;
		l = newnode;
		l->left = l->right = NULL;
		l->see = 1;
		return l;
	}
	else {
		if (val < l->val)
			l->left = insertNode(l->left, val);
		else
			l->right = insertNode(l->right, val);
	}
	l->see = calculateHeight(l);

	if (balanceFactor(l) == 2 && balanceFactor(l->left) == 1) {
		l = leftleftRotation(l);
	}
	else if (balanceFactor(l) == -2 && balanceFactor(l->right) == -1) {
		l = rightrightRotation(l);
	}
	else if (balanceFactor(l) == -2 && balanceFactor(l->right) == 1) {
		l = rightleftRotation(l);
	}
	else if (balanceFactor(l) == 2 && balanceFactor(l->left) == -1) {
		l = leftrightRotation(l);
	}
	return l;
}

node* AVLTree::leftrightRotation(node* x) {
	node* l, * temp, * temp1;
	l = x;
	temp = l->left;
	temp1 = l->left->right;

	l->left = temp1->right;
	temp->right = temp1->left;
	temp1->right = l;
	temp1->left = temp;

	return temp1;
}
node* AVLTree::rightleftRotation(node* x) {
	node* l, * temp, * temp1;
	l = x;
	temp = l->right;
	temp1 = l->right->left;

	l -> right = temp1->left;
	temp->left = temp1->right;
	temp1->left = l;
	temp1->right = temp;

	return temp1;
}
node* AVLTree::rightrightRotation(node* x) {
	node* l, * temp;
	l = x;
	temp = l->right;

	l -> right = temp->left;
	temp->left = l;
	return temp;
}
node* AVLTree::leftleftRotation(node* x) {
	node* l, * temp;
	l = x;
	temp = l->left;
	l->left = temp->right;
	temp->right = l;
	return temp;
}


int AVLTree::balanceFactor(node* l) {
	if (l->left && l->right) {
		return l->left->see - l->right->see;
	}
	else if (l->left && l->right == NULL) {
		return l->left->see;
	}
	else if (l->left == NULL && l->right) {
		return -l->right->see;
	}
	return -1;
}

int AVLTree::calculateHeight(node* l) {
	if (l->left && l->right) {
		if (l->left->see < l->right->see)
			return l->right->see + 1;
		else
			return l->left->see + 1;
	}
	else if (l->left && l->right == NULL) {
		return l->left->see + 1;
	}
	else if (l->left == NULL && l->right) {
		return l->right->see + 1;
	}
	else {
		return -1;
	}
	
}

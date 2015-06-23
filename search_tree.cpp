#include <iostream>

class Node{

public:
	Node * left;
	Node * right;
	int value;

	Node(int value):left(NULL), right(NULL), value(value){}

};

class BinaryTree{

public:

	BinaryTree():root(NULL){}
	Node * root;

	void insertNode(int to_put){
		if(root == NULL)
			root = new Node(to_put);
		else if(root->left == NULL && root->value >= to_put){
			root->left = new Node(to_put);
		}
		else if(root->right == NULL && root->value < to_put){
			root->right = new Node(to_put);
		}
		else if(root->left != NULL && root->value >= to_put)
			insertNode_(root->left, to_put);
		else
			insertNode_(root->right, to_put);
	}

	void inOrderVisit(){
		inOrderVisit_(root->left);
		std::cout << root->value << std::endl;
		inOrderVisit_(root->right);
	}

	void preOrderVisit(){
		std::cout << root->value << std::endl;
		preOrderVisit_(root->left);
		preOrderVisit_(root->right);
	}

	void postOrderVisit(){
		postOrderVisit_(root->left);
		postOrderVisit_(root->right);
		std::cout << root->value << std::endl;
	}

	bool find(int to_find){
		if(root->value == to_find)
			return true;
		if(root->left != NULL && root->value >= to_find)
			return find_(root->left, to_find);
		else if(root->right != NULL && root->value < to_find)
			return find_(root->right, to_find);
		else
			return false;
	}


private:

	void insertNode_(Node * n, int to_put){
		if(n->left == NULL && n->value >= to_put){
			n->left = new Node(to_put);
		}
		else if(n->right == NULL && n->value < to_put){
			n->right = new Node(to_put);
		}
		else if(n->left != NULL && n->value >= to_put)
			insertNode_(n->left, to_put);
		else
			insertNode_(n->right, to_put);
	}

	void inOrderVisit_(Node * n){
		if(n == NULL)
			return;
		inOrderVisit_(n->left);
		std::cout << n->value << std::endl;
		inOrderVisit_(n->right);
	}

	void preOrderVisit_(Node * n){
		if(n == NULL)
			return;
		std::cout << n->value << std::endl;
		preOrderVisit_(n->left);
		preOrderVisit_(n->right);
	}

	void postOrderVisit_(Node * n){
		if(n == NULL)
			return;
		postOrderVisit_(n->left);
		postOrderVisit_(n->right);
		std::cout << n->value << std::endl;
	}

	bool find_(Node * n, int to_find){
		if(n->value == to_find)
			return true;
		if(n->left != NULL && n->value >= to_find)
			return find_(n->left, to_find);
		else if(n->right != NULL && n->value < to_find)
			return find_(n->right, to_find);
		else
			return false;
	}


};



int main(int argc, char * argv[]){
	
	BinaryTree b;
	b.insertNode(7);
	b.insertNode(12);
	b.insertNode(4);
	b.insertNode(3);
	b.insertNode(64);

	std::cout << "inorder" << std::endl;
	b.inOrderVisit();

	std::cout << "preorder" << std::endl;
	b.preOrderVisit();

	std::cout << "postorder" << std::endl;
	b.postOrderVisit();

	int to_find = 7;
	if(b.find(to_find))
		std::cout << "found " << to_find<< std::endl;
	else
		std::cout << "not found " << to_find << std::endl;

	to_find = 24;
	if(b.find(to_find))
		std::cout << "found " << to_find<< std::endl;
	else
		std::cout << "not found " << to_find << std::endl;



}
#include <iostream>
#include <queue>
struct Node
{
	int data;
	Node* left, *right;
	Node(int data):data(data), left(nullptr), right(nullptr) { }
};
class Tree
{
	Node * root = nullptr;
private:
	Node* findMin(Node* root)
	{
		while(root->left != nullptr) root = root->left;
		return root;
	}
	Node* insert(Node* root, int data)
	{
		if(root == nullptr)
			root = new Node(data);
		else if (data <= root->data) root->left = insert(root->left, data);
		else if (data >= root->data) root->right = insert(root->right, data);
		return root;
	}
	bool search(Node* root, int data)
	{
		if(root == nullptr) return false;
		else if(data == root->data) return true;
		else if(data < root->data) return search(root->left, data);
		else return search(root->right, data);
	}
	Node* deleteNode(Node* root, int data)
	{
		if(root == nullptr) return root;
		else if(data < root->data) root->left = deleteNode(root->left, data);
		else if(data > root->data) root->right = deleteNode(root->right, data);
		else
		{
			//No Node
			if(root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
			}
			//One child at left
			else if(root->right == nullptr)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			//One child at right
			else if(root->left == nullptr)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			//2 child
			else
			{
				Node* temp = findMin(root->right);
				root->data = temp->data; 
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}
	void levelOrderPrint(Node* root)
	{
		if(root == nullptr) return;
		std::queue<Node*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			Node* current = Q.front();
			std::cout << current->data << ", ";
			if(current->left != nullptr) Q.push(current->left);
			if(current->right != nullptr) Q.push(current->right);
			Q.pop();
		}
	}
void preOrderPrint(Node* root)
{
	if(root == NULL)	return;
	std::cout << root->data << ", ";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}
void inOrderPrint(Node* root)
{
	if(root== NULL) return;
	inOrderPrint(root->left);
	std::cout << root->data << ", ";
	inOrderPrint(root->right);
}
void postOrderPrint(Node *root)
{
	if(root == NULL) return;
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	std::cout << root->data << ", ";
}
int numberOfNodes(Node* root)
{
	int count = 1;
	if(root->left != NULL)
		count += numberOfNodes(root->left);
	if(root->right != NULL)
		count += numberOfNodes(root->right);
	return count;
}
int height(Node* root)
{
	if(root == NULL) return -1;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return ((leftHeight > rightHeight ? leftHeight: rightHeight) + 1);
}
	
public:
	void Insert(int data)
	{
		root = insert(root, data);
	}
	bool Search(int data)
	{
		return search(root, data);
	}
	void Delete(int data)
	{
		deleteNode(root, data);
	}
	void LevelOrderPrint()
	{
		levelOrderPrint(root);
	}
	void PreOrderPrint()
	{
		preOrderPrint(root);
	}
	void InOrderPrint()
	{
		inOrderPrint(root);
	}
	void PostOrderPrint()
	{
		postOrderPrint(root);
	}
	int NumberOfNodes()
	{
		return numberOfNodes(root);
	}
	int Height()
	{
		return height(root);
	}
};

int main()
{
	Tree t1;
	for(int i = 0; i < 10; i++)
	{
		t1.Insert(i * 3);
	}
	if(t1.Search(6))
		std::cout << "Found" << std::endl;
	else	
		std::cout << "Not Found" << std::endl;
	t1.Delete(6);
	if(t1.Search(6))
		std::cout << "Found" << std::endl;
	else	
		std::cout << "Not Found" << std::endl;
	t1.PreOrderPrint();
}

#ifndef _TREE_H
#define _TREE_H


#include <vector>
///TODO:É¾³ý²Ù×÷¡£

template<class T>
struct TreeNode {
	TreeNode<T>* parent;
	T value;
	TreeNode<T>* left_child;
	TreeNode<T>* right_child;
	TreeNode() {
		parent = NULL;
		left_child = NULL;
		right_child = NULL;
	}
	TreeNode(T value, TreeNode<T>* parent, TreeNode<T>* left_child, TreeNode<T>* right_child) 
	: value(value), parent(parent), left_child(left_child), right_child(right_child) {}
};

template <class T>
class NodeManager {
public:
	NodeManager();
	~NodeManager();

	TreeNode<T>* CreateNode(T value, TreeNode<T>* parent, TreeNode<T>* left_child, TreeNode<T>* right_child);
	void DeleteNode(TreeNode<T>* node);

private:
	std::vector<TreeNode<T>*> vector_node;

};

template <class T> 
class BinSearchTree {
public:
	BinSearchTree();
	~BinSearchTree();

	///////½¨Ê÷////////
	void Insert(T value);
	void Insert(T* value);

	void Delete(TreeNode<T>* node);

	void InOrderTreeWalk();
	void InOrderTreeWalk(TreeNode<T>* node);
	TreeNode<T>* TreeSearch(T value);
	const TreeNode<T>* Maximum();
	const TreeNode<T>* Minimum();
	TreeNode<T>* Successor(TreeNode<T>* node);
	TreeNode<T>* Predecessor(TreeNode<T>* node);



private:
	void Insert_(TreeNode<T>* node, T value);
	TreeNode<T>*  TreeSearch_(TreeNode<T>* node, T value);
	void Transplant_(TreeNode<T>* src, TreeNode<T>* dest);
	TreeNode<T>* Maximum_(TreeNode<T>* node);
	TreeNode<T>* Minimum_(TreeNode<T>* node);



private:
	TreeNode<T>* root;
	NodeManager<T>* node_manager;

};


#endif // !_TREE_H

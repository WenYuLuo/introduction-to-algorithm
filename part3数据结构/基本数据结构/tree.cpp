#include "tree.h"
#include <iostream>
#include <assert.h>

template<class T>
BinSearchTree<T>::BinSearchTree() {
	root = NULL;
	node_manager = new NodeManager<T>();
}

template<class T>
BinSearchTree<T>::~BinSearchTree() {
// 	if (root != NULL) {
// 		delete root;
// 	}
	if (node_manager != NULL) {
		delete node_manager;
	}
}

template<class T>
void BinSearchTree<T>::Insert(T value) {
//	TreeNode<T>* new_node = new TreeNode<T>();
	if (root != NULL) {
		Insert_(root, value);
	} else {
		root = node_manager->CreateNode(value, NULL,NULL,NULL);
	}
}

template<class T>
void BinSearchTree<T>::Insert(T * value) {}

template<class T>
void BinSearchTree<T>::Delete(TreeNode<T>* node) {
	if (node->left_child == NULL) {
		Transplant_(node->right_child, node);
		node_manager->DeleteNode(node);
	} else if (node->right_child == NULL) {
		Transplant_(node->left_child, node);
		node_manager->DeleteNode(node);
	} else {
		TreeNode<T>* processor = Minimum_(node->right_child);
		if (processor->parent != node) {
			Transplant_(processor->right_child, processor);
			processor->right_child = node->right_child;
			processor->right_child->parent = processor;
		}
		Transplant_(processor, node);
		processor->left_child = node->left_child;
		processor->left_child->parent = processor;
		node_manager->DeleteNode(node);
	}
}

template<class T>
void BinSearchTree<T>::InOrderTreeWalk() {
	if (root != NULL)
		InOrderTreeWalk(root);
}

template<class T>
void BinSearchTree<T>::InOrderTreeWalk(TreeNode<T>* node) {
	if (node != NULL) {
		InOrderTreeWalk(node->left_child);
		std::cout << node->value << " | ";
		InOrderTreeWalk(node->right_child);
	}
}

template<class T>
TreeNode<T>* BinSearchTree<T>::TreeSearch(T value) {
	if (root != NULL) {
		return TreeSearch_(root, value);
	} else {
		return NULL;
	}
}

template<class T>
const TreeNode<T>* BinSearchTree<T>::Maximum() {
// 	if (root != NULL) {
// 		TreeNode<T>* maximum = root;
// 		while (maximum->right_child != NULL) {
// 			maximum = maximum->right_child;
// 		}
// 		return maximum;
// 	}
// 	return NULL;
	return Maximum_(root);
}

template<class T>
const TreeNode<T>* BinSearchTree<T>::Minimum() {
// 	if (root != NULL) {
// 		TreeNode<T>* minimum = root;
// 		while (minimum->right_child != NULL) {
// 			minimum = minimum->right_child;
// 		}
// 		return minimum;
// 	}
// 	return NULL;
	return Minimum_(root);
}

template<class T>
TreeNode<T>* BinSearchTree<T>::Successor(TreeNode<T>* node) {
	if (node->right_child != NULL) {
		return Minimum_(node->right_child);
	} else {
		//TODO: ºó¼Ì
		TreeNode<T>* current = node->parent;
		while (current != NULL&&node == current->right_child) {
			node = current;
			current = current->parent;
		}
		return current;
	}
}

template<class T>
TreeNode<T>* BinSearchTree<T>::Predecessor(TreeNode<T>* node) {
	if (node->left_child != NULL) {
		return Maximum_(node->left_child);
	} else {
		TreeNode<T>* current = node->parent;
		while (current != NULL&&node == current->left_child) {
			node = current;
			current = current->parent;
		}
		return current;
	}
}


template<class T>
void BinSearchTree<T>::Insert_(TreeNode<T>* node, T value) {
	assert(node != NULL);
	if (value >= node->value) {
		if(node->right_child!=NULL)
		   Insert_(node->right_child, value);
		else {
			TreeNode<T>* new_node = node_manager->CreateNode(value, node, NULL, NULL);
			node->right_child = new_node;
			return;
		}
	} else {
		if(node->left_child != NULL )
		   Insert_(node->left_child, value);
		else {
			TreeNode<T>* new_node = node_manager->CreateNode(value, node, NULL, NULL);
			node->left_child = new_node;
			return;
		}
	}
}

template<class T>
TreeNode<T>* BinSearchTree<T>::TreeSearch_(TreeNode<T>* node, T value) {
	//assert(node != NULL);
	if (node == NULL) {
		return NULL;
	}
	if (node->value == value) {
		return node;
	} else if(value < node->value) {
		return TreeSearch_(node->left_child, value);
	} else {
		return TreeSearch_(node->right_child, value);
	}
}

template<class T>
void BinSearchTree<T>::Transplant_(TreeNode<T>* src, TreeNode<T>* dest) {
	
// 		if (src == src->parent->left_child)
// 			src->parent->left_child == NULL;
// 		else if (src == src->parent->right_child)
// 			src->parent->right_child == NULL;
	if (src != NULL) {
		src->parent = dest->parent;
	}
	if (dest->parent == NULL) {
		root = src;
	} else if (dest == dest->parent->left_child)
		dest->parent->left_child = src;
	else if (dest == dest->parent->right_child)
		dest->parent->right_child = src;
		
}

template<class T>
TreeNode<T>* BinSearchTree<T>::Maximum_(TreeNode<T>* node) {
	if (node != NULL) {
		TreeNode<T>* maximum = node;
		while (maximum->right_child != NULL) {
			maximum = maximum->right_child;
		}
		return maximum;
	}
	return NULL;
}

template<class T>
TreeNode<T>* BinSearchTree<T>::Minimum_(TreeNode<T>* node) {
	if (node != NULL) {
		TreeNode<T>* minimum = node;
		while (minimum->left_child != NULL) {
			minimum = minimum->left_child;
		}
		return minimum;
	}
	return NULL;
}



//************************************
// class:    NodeManager 
//************************************
template<class T>
NodeManager<T>::NodeManager() {}

template<class T>
NodeManager<T>::~NodeManager() {
	if (!vector_node.empty()) {
		for (size_t i = 0; i < vector_node.size(); i++) {
			delete vector_node[i];
		}
		vector_node.clear();
	}
}

template<class T>
TreeNode<T>* NodeManager<T>::CreateNode(T value, TreeNode<T>* parent, TreeNode<T>* left_child, TreeNode<T>* right_child) {
	TreeNode<T>* new_node = new TreeNode<T>(value, parent, left_child, right_child);
	vector_node.push_back(new_node);
	return new_node;
}

template<class T>
void NodeManager<T>::DeleteNode(TreeNode<T>* node) {
	auto iter = find(vector_node.begin(), vector_node.end(), node);
	if (iter != vector_node.end()) {
		vector_node.erase(iter);
		delete node;
	}
}

#pragma once
#include <vector>

//template <typename T>
struct Node
{
	Node* root;
	Node* parent;
	int value; // вместо атомарного элемента формулы
	std::vector<Node> childs;
};

class Tree
{
	Node root;
public:
	Tree();
	~Tree();


};
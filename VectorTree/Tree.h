#pragma once
#include <vector>

//template <typename T>
struct Node
{
	Node* root;
	Node* parent;
	int value; // ������ ���������� �������� �������
	std::vector<Node> childs;
};

class Tree
{
	Node root;
public:
	Tree();
	~Tree();


};
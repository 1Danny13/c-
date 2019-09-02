// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
#include<iostream>

//插入num数组的前len个元素
Tree::Tree(int num[], int len)
{
	root = new Node(num[0]);
	//把数组中的其他数组插入到二叉排序树中
	for (int i = 1; i < len; i++)
		insertNode1(num[i]);
	//insertNode(num[i]);
}
void Tree::insertNode(int data)
{
	Node *p, *par;
	Node* newNode = new Node(data);

	p = par = root;
	while (p != NULL)
	{
		par = p;   //保存节点
		if (data > p->data)
			p = p->right;
		else if (data < p->data)
			p = p->left;
		else if (data == p->data)
		{
			delete newNode;
			return;
		}
	}
	newNode->parent = par;
	if (par->data > newNode->data)
		par->left = newNode;
	else
		par->right = newNode;
}

//递归实现插入
void Tree::insertNode(int data)
{
	if (root != NULL)
		insertNode(root, data);
}
void Tree::insertNode(Node* current, int data)
{
	if (data < current->data) {
		if (current->left == NULL)
		{
			current->left = new Node(data);
			current->left->parent = current;
		}
		else
			insertNode(current->left, data);
	}
	else if(data > current->data){
		if (current->right == NULL)
		{
			current->right = new Node(data);
			current->right->parent = current;
		}
		else
			insertNode(current->right, data);
	}
	return;
}

//递归查找
Node* Tree::searchNode(Node* current, int data) {
	if (data < current->data)
	{
		if (current->left == NULL)
			return NULL;
		return searchNode(current->left, data);
	}
	else if(data > current->data){
		if (current->right == NULL)
			return NULL;
		return searchNode(current->right, data);
	}
	return current;
}

//删除数据为data的节点及子树

void Tree::deleteNode(int data)
{
	Node* current = NULL;

	current = searchNode(data);
	if (current != NULL)
		deleteNode(current);
}
void Tree::deleteNode(Node* current)
{
	if (current->left != NULL)
		deleteNode(current->left);
	if (current->right != NULL)
		deleteNode(current->right);
	if (current->parent == NULL)
	{
		delete current;
		root = NULL;
		return;
	}
	//将current父亲节点的相应指针置空
	if (current->parent->data > current->data)  //current为父节点
		current->parent->left = NULL;
	else
		current->parent->right = NULL;

	delete current;
}
//中序遍历递归
void Tree::InOrderTree()
{
	if (root == NULL)
		return;
	InOrderTree(root);
}
void Tree::InOrderTree(Node* current)
{
	if (current != NULL)
	{
		InOrderTree(current->left);
		std::cout << current->data << std::endl;
		InOrderTree(current->right);
	}
}
//先序遍历递归
void Tree::InOrderTree()
{
	if (root == NULL)
		return;
	InOrderTree(root);
}
void Tree::InOrderTree(Node* current)
{
	if (current != NULL)
	{
		std::cout << current->data << std::endl;
		InOrderTree(current->left);
		InOrderTree(current->right);
	}
}
//后序遍历递归
void Tree::InOrderTree()
{
	if (root == NULL)
		return;
	InOrderTree(root);
}
void Tree::InOrderTree(Node* current)
{
	if (current != NULL)
	{
		InOrderTree(current->left);
		InOrderTree(current->right);
		std::cout << current->data << std::endl;
	}
}

//先序遍历非递归

//中序遍历非递归

//后序遍历非递归
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。

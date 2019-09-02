// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H
#include <iostream>
class Node
{
public:int data;
	   Node *parent;
	   Node *left;
	   Node *right;
public:
	Node() :data(-1), parent(NULL), left(NULL), right(NULL) {};
	Node(int num) :data(num), parent(NULL), left(NULL), right(NULL) {};
	//~Node() {};
};
//二叉树类定义
class Tree
{
private:  //递归方法
	void insertNode(Node* current, int data);
	Node* searchNode(Node* current, int data);
	void deleteNode(Node* current);
private:
	Node* root;
public:
	Tree(int num[], int len);
	void insertNode(int data);   //非递归
	void insertNode1(int data);
	Node *searchNode(int data);
	void deleteNode(int data);

	//遍历算法
	void InOrderTree();
	void InOrderTree(Node* current);
	void InOrderTreeUnrecursion();

	void PreOrderTree();
	void PreOrderTree(Node* current);
	void PreOrderTreeUnrecursion();

	void PostOrderTree();
	void PostOrderTree(Node* current);
	void PostOrderTreeUnrecursion();
};
// TODO: 添加要在此处预编译的标头

#endif //PCH_H

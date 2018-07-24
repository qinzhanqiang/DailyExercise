#pragma once
enum RBTColor {RED,BLACK};
template<class T>
class RBTNode {
public:
	RBTColor color;
	T key;
	RBTNode *left;
	RBTNode *right;
	RBTNode *parent;

	RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r) :key(value), color(c), parent(p), left(l), right(r) {};
};


template<class T>
class RBTree
{
private:
	RBTNode<T> *mRoot;

public:
	RBTree();
	~RBTree();

	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);

	void rightRotate(RBTNode<T>*& root, RBTNode<T>* x);

	void insert(RBTNode<T>*& root, RBTNode<T>* node);

	void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node);

	void insert(T key);

};


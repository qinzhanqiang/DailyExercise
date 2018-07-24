#include "RBTree.h"

template<typename T>
RBTree<T>::RBTree()
{

}

template<typename T>
RBTree<T>::~RBTree()
{

}

template<typename T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
	//设置x的右孩子为y
	RBTNode<T> *y = x->left;

	//将y的左孩子设置成x的右孩子；如果y的左孩子不为空，将y的左孩子的父节点设置成x
	x->right = y->left;
	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	//将x的父节点设置成y的父节点；如果该节点为空，则设置y为根节点
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		//处理x的父节点的左右子节点的问题
		if (x->parent->left == x)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
	}

	//将x的父节点设置y，将y的左孩子设置成x
	x->parent = y;
	y->left = x;
}

template<typename T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
	RBTNode<T>* x = y->left;


	//1、处理x的右孩子节点：
	y->left = x->right;		//将x的右孩子设置成y的左孩子
	if (x->right != NULL)	//如果x的右孩子不为空，则设置它的父节点为y
	{
		x->right->parent = y;
	}
	

	//2、处理y节点的父节点
	x->parent = y->parent;
	if (y->parent == NULL)
	{
		root = x;
	}
	else
	{
		if (y->parent->left == y)
		{
			y->parent->left = x;
		}
		else
		{
			y->parent->right = x;
		}
	}

	//3、处理x与y节点的关系
	x->right = y;
	y->parent = x;
}

template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T>* x = root;
	RBTNode<T>* y = NULL;

	//使用二分搜索树的方式插入节点
	while (x != NULL)
	{
		y = x;	//保存当前节点
		if (node->key < x->key )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	//找到叶子节点，将插入的节点的父节点设置成该节点
	node->parent = y;
	//判断该节点是父节点的左孩子还是右孩子
	if (y != NULL)
	{
		if (node->key > y->key)
		{
			y->right = node;
		}
		else
		{
			y->left = node;
		}
	}

	//设置该节点的颜色为红色
	node->color = RED;

	//将插入后的树修正成一颗二叉查找树
	insertFixUp(root, node);

}
template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent, *uncle;

	//如果父节点存在并且父节点为红色
	while ((parent = node->parent) != NULL && parent->color == RED)
	{
		//如果祖父节点存在且父节点是祖父节点的左子树
		if ((gparent = parent->parent) != NULL && parent = gparent->left)
		{
			uncle = gparent->right;
			//如果叔叔节点是红色
			if (uncle != NULL && uncle->color == RED)
			{
				parent->color = BLACK;
				uncle->color = BLACK;
				gparent->color = RED;

				node = gparent;

			}
			else
			{
				//如果是父节点的右子树
				if (node == parent->right)		
				{
					leftRotate(root, parent);	//对父节点进行左旋转 旋转会导致node和原来的父节点交换
					node->color = BLACK;
					gparent->color = RED;
					rightRotate(root, gparent);


				}
				//如果是父节点的左子树
				else
				{
					parent->color = BLACK;
					gparent->color = RED;
					rightRotate(root, gparent);
				}
			}
		}
		//如果祖父节点存在且父节点是祖父节点的右子树
		else
		{
			uncle = gparent->left;

			//如果是父节点的右子树
			if (node == parent->right)
			{
				leftRotate(root, parent);	//对父节点进行左旋转 旋转会导致node和原来的父节点交换
				node->color = BLACK;
				gparent->color = RED;
				rightRotate(root, gparent);


			}
			//如果是父节点的左子树
			else
			{
				parent->color = BLACK;
				gparent->color = RED;
				rightRotate(root, gparent);
			}
		}
	}

	//如果父节点是黑色则无需修改

	root->color = BLACK;
}

template <typename T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z = NULL;
	
	if (z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL) == NULL)
		return;
	insert(mRoot, z);
}
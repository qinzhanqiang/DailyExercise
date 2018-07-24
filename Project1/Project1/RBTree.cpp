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
	//����x���Һ���Ϊy
	RBTNode<T> *y = x->left;

	//��y���������ó�x���Һ��ӣ����y�����Ӳ�Ϊ�գ���y�����ӵĸ��ڵ����ó�x
	x->right = y->left;
	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	//��x�ĸ��ڵ����ó�y�ĸ��ڵ㣻����ýڵ�Ϊ�գ�������yΪ���ڵ�
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		//����x�ĸ��ڵ�������ӽڵ������
		if (x->parent->left == x)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
	}

	//��x�ĸ��ڵ�����y����y���������ó�x
	x->parent = y;
	y->left = x;
}

template<typename T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
	RBTNode<T>* x = y->left;


	//1������x���Һ��ӽڵ㣺
	y->left = x->right;		//��x���Һ������ó�y������
	if (x->right != NULL)	//���x���Һ��Ӳ�Ϊ�գ����������ĸ��ڵ�Ϊy
	{
		x->right->parent = y;
	}
	

	//2������y�ڵ�ĸ��ڵ�
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

	//3������x��y�ڵ�Ĺ�ϵ
	x->right = y;
	y->parent = x;
}

template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T>* x = root;
	RBTNode<T>* y = NULL;

	//ʹ�ö����������ķ�ʽ����ڵ�
	while (x != NULL)
	{
		y = x;	//���浱ǰ�ڵ�
		if (node->key < x->key )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	//�ҵ�Ҷ�ӽڵ㣬������Ľڵ�ĸ��ڵ����óɸýڵ�
	node->parent = y;
	//�жϸýڵ��Ǹ��ڵ�����ӻ����Һ���
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

	//���øýڵ����ɫΪ��ɫ
	node->color = RED;

	//����������������һ�Ŷ��������
	insertFixUp(root, node);

}
template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent, *uncle;

	//������ڵ���ڲ��Ҹ��ڵ�Ϊ��ɫ
	while ((parent = node->parent) != NULL && parent->color == RED)
	{
		//����游�ڵ�����Ҹ��ڵ����游�ڵ��������
		if ((gparent = parent->parent) != NULL && parent = gparent->left)
		{
			uncle = gparent->right;
			//�������ڵ��Ǻ�ɫ
			if (uncle != NULL && uncle->color == RED)
			{
				parent->color = BLACK;
				uncle->color = BLACK;
				gparent->color = RED;

				node = gparent;

			}
			else
			{
				//����Ǹ��ڵ��������
				if (node == parent->right)		
				{
					leftRotate(root, parent);	//�Ը��ڵ��������ת ��ת�ᵼ��node��ԭ���ĸ��ڵ㽻��
					node->color = BLACK;
					gparent->color = RED;
					rightRotate(root, gparent);


				}
				//����Ǹ��ڵ��������
				else
				{
					parent->color = BLACK;
					gparent->color = RED;
					rightRotate(root, gparent);
				}
			}
		}
		//����游�ڵ�����Ҹ��ڵ����游�ڵ��������
		else
		{
			uncle = gparent->left;

			//����Ǹ��ڵ��������
			if (node == parent->right)
			{
				leftRotate(root, parent);	//�Ը��ڵ��������ת ��ת�ᵼ��node��ԭ���ĸ��ڵ㽻��
				node->color = BLACK;
				gparent->color = RED;
				rightRotate(root, gparent);


			}
			//����Ǹ��ڵ��������
			else
			{
				parent->color = BLACK;
				gparent->color = RED;
				rightRotate(root, gparent);
			}
		}
	}

	//������ڵ��Ǻ�ɫ�������޸�

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
#pragma once
#include<iostream>
#include<cassert>

using namespace std;


template<class K, class V>
class AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf; // balance factor  影响因子
	
	AVLTreeNode(const pair<K,V>& kv)
		:_leftr(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
		,_kv(kv)
	{}
};


template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)const
	{
		// 第一个节点
		if (_root == nullptr)
		{
			Node* tmp = new Node(kv);
			_root = tmp;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) // 找到要插入的位置
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				cur = parent;
				cur = cur->_right;
			}
			else 
				return false;
		}

		// 插入
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		cur->_parent = parent;



		// 调整平衡因子
		while (parent)
		{
			if (cur == parent->_right)
				parent->_bf++;
			else if (cur == parent->_left)
				parent->_bf--;
			
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0) 
				break;
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转

				break;
			}
			else
			{
				assert(false);
			}
		}


		return true;
	}

private:
	Node* _root;
};
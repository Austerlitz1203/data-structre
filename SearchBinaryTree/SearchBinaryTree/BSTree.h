#pragma once
#include<algorithm>
#include<iostream>

using std::cout;
using std::endl;

template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
	K _key;
	V _value;

	BSTreeNode(const K& key,const V& val)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		,_value(val)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;
public:

	bool Insert(const K& key,const V& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}

		if (parent->_key < key)
			parent->_right = new Node(key,val);
		else
			parent->_left = new Node(key,val);

		return true;
	}

	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
				return cur;
		}
		return nullptr;
	}


	// 删除
	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else // 相等，删除
			{
				// 左为空
				if (cur->_left == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}// 右为空
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}
				else // 左右都不为空
				{
					Node* pminRight = nullptr;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						pminRight = minRight;
						minRight = minRight->_left;
					}

					cur->_key = minRight->_key;
					// 删除节点的右边就是最小值
					if (minRight == cur->_right)
					{
						cur->_right = minRight->_right;
					}
					else
					{
						pminRight->_left = minRight->_right;
					}

					delete minRight;
				}
				return true;
			}

		}
		return false;
	}

	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr) return nullptr;

		if (root->_key > key) return _FindR(root->_left, key);
		else if (root->_key < key) return _FindR(root->_right, key);
		else return root;
	}

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool _InsertR(Node*& root, const K& key,const V& val)
	{
		if (root == nullptr)
		{
			root = new Node(key,val);
			return true;
		}
		if (root->_key < key)
			_InsertR(root->_right, key,val);
		else if (root->_key > key)
			_InsertR(root->_left, key,val);
		else 
			return false;
	}

	bool InsertR(const K& key,const V& val)
	{
		return _InsertR(_root, key,val);
	}

	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr) return false;
		if (root->_key > key)
		{
			_EraseR(root->_left, key);
		}
		else if (root->_key < key)
		{
			_EraseR(root->_right, key);
		}
		else
		{
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else // 左右都不为空
			{
				Node* maxleft = root->_left;
				while (maxleft->_right)
				{
					maxleft = maxleft->_right;
				}
				swap(root->_key, maxleft->_key);
				_EraseR(root->_left, key);
			}
			return true;
		}

		return false;
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

	void Inorder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr) return;

		_InOrder(root->_left);
		cout << root->_key << ":" << root->_value << endl;
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};

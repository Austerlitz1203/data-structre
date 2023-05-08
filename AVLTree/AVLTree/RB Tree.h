#pragma once
#include<iostream>
#include<cassert>

using namespace std;

namespace simulate
{
	enum Colour
	{
		RED,
		BLACK,
	};

	template<class K, class V>
	struct RBTreeNode
	{
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		Colour _col;

		RBTreeNode(const pair<K, V>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _col(RED)
		{}
	};


	template<class K, class V>
	class RBTree
	{
		typedef struct RBTreeNode<K, V> Node;

	public:

		~RBTree()
		{
			Delete(_root);
			_root = nullptr;
		}

		Node* find(pair<K, V> kv)
		{
			Node* cur = _root;
			while (cur)
			{
				if (kv.first > cur->_kv.first)
				{
					cur = cur->_right;
				}
				else if (kv.first < cur->_kv.first)
				{
					cur = cur->_left;
				}
				else
					return cur;
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
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
					parent = cur;
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


			// 调整颜色
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					if (uncle && uncle->_col == RED) // uncle 为红色
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续调整
						cur = grandfather;
						parent = cur->_parent;
					}
					else // uncle不存在 or 存在且为黑
					{
						if (cur == parent->_left)
						{
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
							//cur->_col = RED;
						}
						else if (cur == parent->_right)
						{
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
							parent->_col = RED;
						}

						break;
					}
				}
				else // if (parent == grandfather->_right)
				{
					Node* uncle = grandfather->_left;
					if (uncle && uncle->_col == RED) // uncle 为红色
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续调整
						cur = grandfather;
						parent = cur->_parent;
					}
					else // uncle不存在 or 存在且为黑
					{
						if (cur == parent->_right)
						{
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
							//cur->_col = RED;
						}
						else // cur == parent->_left
						{
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							parent->_col = RED;
							grandfather->_col = RED;
						}

						break;
					}
				}
			}

			_root->_col = BLACK;
			return true;
		}

		int Height()
		{
			return _Height(_root);
		}

		bool isBalance()
		{
			if (_root->_col == RED)
			{
				cout << "根节点的颜色是红色" << endl;
				return false;
			}

			int benchmark = 0;
			Node* tmp = _root;
			while (tmp)
			{
				if (tmp->_col == BLACK)
					benchmark++;
				tmp = tmp->_left;
			}

			return _isBalance(_root, 0, benchmark);
		}

		void Inorder()
		{
			_Inorder(_root);
		}

	private:

		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;

			_Inorder(root->_left);
			cout << root->_kv.first<<" ";
			_Inorder(root->_right);
		}

		bool _isBalance(Node* root, int blackNum, int benchmark)
		{
			if (root == nullptr)
			{
				if (blackNum == benchmark)
					return true;
				else
				{
					cout << "某条链路黑色节点数目错误！" << endl;
					return false;
				}
			}

			if (root->_col == BLACK)
				++blackNum;
			else
			{
				if (root->_parent && root->_parent->_col == RED)
				{
					cout << "存在两个连续的红色节点" << endl;
					return false;
				}
			}

			return _isBalance(root->_left, blackNum, benchmark)
				&& _isBalance(root->_right, blackNum, benchmark);
		}

		int _Height(Node* root)
		{
			if (root == nullptr) return 0;

			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);

			return leftH > rightH ? leftH + 1 : rightH + 1;
		}



		void Delete(Node* root)
		{
			if (root == nullptr)
				return;

			Delete(root->_left);
			Delete(root->_right);
			free(root);
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			Node* pparent = parent->_parent;
			subR->_left = parent;
			parent->_parent = subR;

			if (pparent == nullptr)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				if (parent == pparent->_left)
				{
					pparent->_left = subR;
				}
				else
				{
					pparent->_right = subR;
				}
				subR->_parent = pparent;
			}


		}



		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			Node* pparent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;


			if (pparent == nullptr)
			{
				subL->_parent = nullptr;
				_root = subL;
			}
			else
			{
				if (parent == pparent->_left)
				{
					pparent->_left = subL;
				}
				else
				{
					pparent->_right = subL;
				}

				subL->_parent = pparent;
			}

		}

	private:
		Node* _root;
	};

}
#pragma once
#include<iostream>
#include<cassert>

using namespace std;

namespace simulate
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		int _bf; // balance factor  影响因子

		AVLTreeNode(const pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
			, _kv(kv)
		{}
	};


	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;

	public:
		bool Insert(const pair<K, V>& kv)
		{
			// 第一个节点
			if (_root == nullptr)
			{
				_root = new Node(kv);
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
					parent=cur;
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
					if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(parent);
					}
					else
						assert(false);

					break;
				}
				else
				{
					assert(false);
				}
			}


			return true;
		}

		void Inorder()
		{
			_Inorder(_root);
		}

		bool IsBalance()
		{
			return _isBalance(_root);
		}

		int Height()
		{
			return _Height(_root);
		}

	private:

		bool _isBalance(Node* root)
		{
			if (root == nullptr)
				return true;
			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);

			if (root->_bf != rightH - leftH)
			{
				cout << root->_kv.first << "号平衡因子错误" << endl;
				root->_bf = rightH - leftH;
			}

			return abs(rightH - leftH) < 2
				&& _isBalance(root->_left)
				&& _isBalance(root->_right);
		}

		int _Height(Node* root)
		{
			if (root == nullptr) 
				return 0;

			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);

			return leftH > rightH ? leftH + 1 : rightH + 1;
		}

		void _Inorder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Inorder(root->_left);
			cout << root->_kv.first << " ";
			_Inorder(root->_right);
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if(subRL)
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
			parent->_bf = 0;
			subR->_bf = 0;

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

			parent->_bf = 0;
			subL->_bf = 0;
		}

		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			RotateL(parent->_left);
			RotateR(parent);

			if (bf == 1)
			{
				subL->_bf = -1;
				subLR->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else if (bf == 0)
			{
				parent->_bf = 0;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}


		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(parent->_right);
			RotateL(parent);

			if (bf == 1)
			{
				parent->_bf = -1;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subR->_bf = 1;
				subRL->_bf = 0;
			}
			else if (bf == 0)
			{
				parent->_bf = 0;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
			else
				assert(false);

		}


	private:
		Node* _root=nullptr;
	};
}
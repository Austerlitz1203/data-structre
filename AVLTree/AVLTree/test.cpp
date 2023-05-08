#include"AVL Tree.h"
#include"RB Tree.h"

void Test_AVLTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	simulate::AVLTree<int, int> t1;
	for (auto e : a)
	{
			if (e == 14)
			{
			int x = 0;
			}

		t1.Insert(make_pair(e, e));
		cout << e << "²åÈë£º" << t1.IsBalance() << endl;
	}

	t1.Inorder();
	cout << t1.IsBalance() << endl;
}


void Test_AVLTree2()
{
	srand(time(0));
	const size_t N = 5000000;
	simulate::AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.IsBalance() << endl;
	cout << t.Height() << endl;
}



void Test_RBTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	simulate::RBTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
		cout << e << "²åÈë£º" << t1.isBalance() << endl;
	}

	t1.Inorder();
	//cout << t1.isBalance() << endl;
}


void Test_RBTree2()
{
	srand(time(0));
	const size_t N = 5000000;
	simulate::RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.isBalance() << endl;
	cout << t.Height() << endl;
}

int main()
{
	//Test_AVLTree1();
	//Test_AVLTree2();

	//Test_RBTree1();
	Test_RBTree2();

	return 0;
}
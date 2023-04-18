#include"BSTree.h"

using namespace std;

void TestBSTree1()
{
	BSTree<string, string> dict;
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("left", "×ó±ß");
	dict.Insert("right", "ÓÒ±ß");
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("insert", "²åÈë");
	dict.Insert("erase", "É¾³ý");

	string str;
	while (cin >> str)
	{
		auto ret = dict.FindR(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "ÎÞ´Ëµ¥´Ê" << endl;
		}
	}
}



void TestBSTree2()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶", "Àæ" };

	BSTree<string, int> countTree;
	for (auto str : arr)
	{
		//key_value::BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.FindR(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.Inorder();
}

int main()
{
	//TestBSTree1();
	TestBSTree2();
	return 0;
}
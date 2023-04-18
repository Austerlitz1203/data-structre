#include"BSTree.h"

using namespace std;

void TestBSTree1()
{
	BSTree<string, string> dict;
	dict.Insert("sort", "����");
	dict.Insert("left", "���");
	dict.Insert("right", "�ұ�");
	dict.Insert("string", "�ַ���");
	dict.Insert("insert", "����");
	dict.Insert("erase", "ɾ��");

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
			cout << "�޴˵���" << endl;
		}
	}
}



void TestBSTree2()
{
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶", "��" };

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
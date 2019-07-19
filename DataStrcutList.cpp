// DataStrcutList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;








//节点类
class IntSLLNode
{
public:
	int info;           //数据域
	IntSLLNode *next;   //指针域
	IntSLLNode()
	{
		next = 0;
	}
	IntSLLNode(int i, IntSLLNode *in = 0)
	{
		info = i;
		next = in;
	}
};

//链表类

class IntSLList
{
public:
	IntSLList(){ head = tail = 0;}
	~IntSLList();
	bool isEmpty()
	{
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); //delete the head and return its info;
	int deleteFromTail();  //delete the tail and return its info
	void deleteNode(int);
	bool isInList(int) const;
	void Travering(); //遍历链表
private:
	IntSLLNode *head, *tail;
};

IntSLList::~IntSLList()
{
	for (IntSLLNode *p; !isEmpty();)
	{
		p= head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el, head);
	if (tail==0)
	{
		tail = head;
	}
}

void  IntSLList::addToTail(int el)
{
	if (tail!=0)
	{
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else
	{
		head = tail = new IntSLLNode(el);
	}
}

int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode *tmp = head;
	if (head==tail)
	{
		head = tail = 0;
	}
	else
	{
		head = head->next;
	}
	delete tmp;
	return el;
}

int IntSLList::deleteFromTail()
{
	int el = tail->info;
	if (head==tail)
	{
		delete head;
		head = tail = 0;
	}
	else
	{
		IntSLLNode *tmp;
		for (tmp = head; tmp->next != tail;tmp=tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
	}
	return el;
}

void IntSLList::deleteNode(int el)
{
	if (head!=0)
	{
		if (head==tail&&head->info)
		{
			delete head;
			head = tail = 0;
		}
		else if (el==head->info)
		{
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			IntSLLNode *pred, *tmp;
			for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el);
				pred = pred->next, tmp = tmp->next);
			if (tmp!=0)
			{
				pred->next = tmp->next;
				if (tmp==tail)
				{
					tail = pred;
				}
				delete tmp;
			}
		}

	}
}

bool IntSLList::isInList(int el) const
{
	IntSLLNode *tmp;
	for (tmp = head; tmp !=0 &&!(tmp->info == el);tmp=tmp->next);
	return tmp != 0;
}

void IntSLList::Travering()
{
	IntSLLNode *tmp;
	for (tmp = head; tmp != tail;tmp=tmp->next)
	{
		cout << tmp->info << endl;
	}
	cout << tmp->info << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	IntSLList testL;
	testL.addToHead(1);
	testL.addToTail(2);
	testL.addToTail(3);
	testL.addToTail(4);
	testL.addToTail(5);
	testL.Travering();

	int tmp;
	tmp = testL.deleteFromHead();
	cout << "DeleteHead=" << tmp<<endl;
	testL.Travering();

	cout << "************" << endl;

	tmp = testL.deleteFromTail();
	cout << "DeleteTail=" << tmp<<endl;
	testL.Travering();

	cout << "************" << endl;

	testL.deleteNode(4);
	testL.Travering();
	cout << "************" << endl;



	IntSLList *test2 = new IntSLList();
	test2->addToHead(6);
	test2->addToTail(7);
	test2->addToTail(8);
	test2->addToTail(9);
	test2->addToTail(10);
	test2->Travering();
	system("pause");
	return 0;
}




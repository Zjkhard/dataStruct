// stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;


//栈的容器实现  栈先进后出 
template<class T, int capacity = 30> class Stack{
public:
	Stack(){
		pool.reserve(capacity);  //reserve是容器预留空间 在此处为30
	}
	void clear()      //清空栈
	{
		pool.clear();
	}
	bool isEmpty() const{  //const的作用是用来修改隐式this指针的类型，把他变成常指针常量 使得可以访问常量数据成员
		return pool.empty();
	}
	T &topEL(){     //获取栈顶元素
		return pool.back();
	}
	T pop(){       //出栈
		T el = pool.back();
		pool.pop_back();
		return el;
	}

	void push(const T& el){   //压栈
		pool.push_back(el);
	}
private:
	vector<T> pool;   //创建容器 保存数据
};




//栈得链表实现
template<class T> class LLStack{
public:
	LLStack(){}           //构造器
	void clear()        //清空栈 即 链表清空
	{
		lst.clear();
	}
	bool isEmpty() const{  //判断栈是否为空
		return lst.empty();
	}
	T& topEL(){           //获取栈顶元素
		return lst.back();
	}
	T pop(){              //出栈
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(const T& el){  //压栈
		lst.push_back(el);
	}
private:
	list<T> lst;
};




int _tmain(int argc, _TCHAR* argv[])
{

	//Stack<int> s;
	LLStack<int> s;
	s.push(20);
	cout << s.isEmpty() << endl;

	s.push(18);
	cout << s.topEL() << endl;

	s.pop();
	cout << s.topEL() << endl;

	s.clear();
	cout << s.isEmpty() << endl;



	system("pause");
	return 0;
}


// thread_program_c11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<thread>
#include<iostream>
using namespace std;

void fun()
{
	for (int i = 0; i < 10; i++)cout << "myfirst" << endl;

}
int _tmain(int argc, _TCHAR* argv[])
{
	//用函数对象启动线程
	//直接用lambda函数
		thread my_first([]{ for (int i = 0; i < 10; i++)cout << "myfirst" << endl; });
	//使用函数自动生成的对象
		thread myfirst((fun));
		thread myfirst{ fun };
	//向线程函数传递参数
	 for (int i = 0; i < 10; i++)cout << "mymain" << endl;


	


	myfirst.join();
	return 0;
}


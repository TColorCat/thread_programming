// thread_program_c11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<thread>
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	thread my_first([]{ for (int i = 0; i < 10; i++)cout << "myfirst" << endl; });

	 for (int i = 0; i < 10; i++)cout << "mymain" << endl;


	


	my_first.join();
	return 0;
}


// thread_program_c11.cpp : �������̨Ӧ�ó������ڵ㡣
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


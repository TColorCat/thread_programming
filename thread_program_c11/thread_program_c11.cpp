// thread_program_c11.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//�ú������������߳�
	//ֱ����lambda����
		thread my_first([]{ for (int i = 0; i < 10; i++)cout << "myfirst" << endl; });
	//ʹ�ú����Զ����ɵĶ���
		thread myfirst((fun));
		thread myfirst{ fun };
	//���̺߳������ݲ���
	 for (int i = 0; i < 10; i++)cout << "mymain" << endl;


	


	myfirst.join();
	return 0;
}


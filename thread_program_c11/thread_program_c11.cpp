// thread_program_c11.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<thread>
#include<iostream>
using namespace std;


void fun(int since)
{
	for (int i = 0; i < since; i++)cout << "since" << endl;

}
void fun()
{
	for (int i = 0; i < 10; i++)cout << "myfirst" << endl;

}
class X
{
public:
	void since(){ cout << "sin" << endl; }
};
int _tmain(int argc, _TCHAR* argv[])
{
	/*void(*it)(void) = fun;
	//�ú������������߳�
	//ֱ����lambda����
		thread my_first([]{ for (int i = 0; i < 10; i++)cout << "myfirst" << endl; });
	//ʹ�ú����Զ����ɵĶ���
		thread myfirst((it));
		thread myfirst{ it };
	//��functionҲһ�� ����ע�����غ����ǲ���ֱ�ӵ����function�ġ�Ҫô�ú���ָ�룬Ҫô��lambda��һ����˵ʹ�ú���ָ�������static_cast
		
		function<void(void)> thread_function = it;
		thread myfirst(thread_function);

		
	//function<void(int)> thread_function (fun);
	//thread myfirst((fun),5);

	//���̺߳������ݲ���



	X my;
	thread myfirst(&X::since, &my);
	
	for (int i = 0; i < 10; i++)cout << "mymain" << endl;


	


	myfirst.join();
	*/

	cout << thread::hardware_concurrency() << endl;
	return 0;
}


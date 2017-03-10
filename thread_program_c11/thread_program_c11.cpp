// thread_program_c11.cpp : 定义控制台应用程序的入口点。
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
	//用函数对象启动线程
	//直接用lambda函数
		thread my_first([]{ for (int i = 0; i < 10; i++)cout << "myfirst" << endl; });
	//使用函数自动生成的对象
		thread myfirst((it));
		thread myfirst{ it };
	//用function也一样 其中注意重载函数是不能直接导入的function的。要么用函数指针，要么用lambda，一般来说使用函数指针或者用static_cast
		
		function<void(void)> thread_function = it;
		thread myfirst(thread_function);

		
	//function<void(int)> thread_function (fun);
	//thread myfirst((fun),5);

	//向线程函数传递参数



	X my;
	thread myfirst(&X::since, &my);
	
	for (int i = 0; i < 10; i++)cout << "mymain" << endl;


	


	myfirst.join();
	*/

	cout << thread::hardware_concurrency() << endl;
	return 0;
}


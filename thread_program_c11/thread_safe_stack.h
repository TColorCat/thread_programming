#ifndef thread_safe_stack_h_
#define thread_safe_stack_h_

namespace thread_safe_stack
{
 
	
#include <exception>
#include <memory> // For std::shared_ptr<>
#include <mutex>
#include <stack>

	struct empty_stack : std::exception
	{
		const char* what() const throw() {
			return "empty stack!";
		};
	};

	template<typename T>
	class threadsafe_stack
	{
	private:
		std::stack<T> data;
		mutable std::mutex m;

	public:
		threadsafe_stack()
			: data(std::stack<T>()){}

		threadsafe_stack(const threadsafe_stack& other)
		{
			std::lock_guard<std::mutex> lock(other.m);
			data = other.data; // 1 �ڹ��캯�����е�ִ�п���
		}
		/*��ջ���Կ��������������캯���Ի������������ٿ�����ջ��
		���캯�����ТٵĿ���ʹ�û�������ȷ�����ƽ������ȷ�ԣ������ķ�ʽ�ȳ�Ա��ʼ���б�á�
		*/

		threadsafe_stack& operator=(const threadsafe_stack&) = delete;

		void push(T new_value)
		{
			std::lock_guard<std::mutex> lock(m);
			data.push(new_value);
		}

		std::shared_ptr<T> pop()
		{
			std::lock_guard<std::mutex> lock(m);
			if (data.empty()) throw empty_stack(); // �ڵ���popǰ�����ջ�Ƿ�Ϊ��

			std::shared_ptr<T> const res(std::make_shared<T>(data.top())); // ���޸Ķ�ջǰ�����������ֵ ,����ʹ��ָ��ָ�򷵻�ֵ�ķ���
			data.pop();
			return res;
		}

		void pop(T& value)
		{
			std::lock_guard<std::mutex> lock(m);
			if (data.empty()) throw empty_stack();

			value = data.top();
			data.pop();
		}

		bool empty() const
		{
			std::lock_guard<std::mutex> lock(m);
			return data.empty();
		}
	};
}
#endif
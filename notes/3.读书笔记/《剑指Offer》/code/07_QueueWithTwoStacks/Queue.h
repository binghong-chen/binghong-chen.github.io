#include<iostream>
#include<stack>

using namespace std;

template<typename T> class CQueue
{
    public:
        CQueue(void);
        ~CQueue(void);

        void appendTail(const T& node);
        T deleteHead();

    private:
        stack<T> stack1;
        stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        while(stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    /*
    Error no matching function for call to 'std::exception::exception(const char [15])'

    Error 'logic_error' was not declared in this scope

    错误原因
    C++在使用VS 编译时抛出异常可以用下列语句：

    throw std::exception("XXX");
    但使用Dev-C++ (GCC) 编译时，会报以下错误：

    Error no matching function for call to 'std::exception::exception(const char [15])'
    解决方法：
    #include <stdexcept>
    throw std::logic_error("XXX");
    如果不  #include <stdexcept>  则会报错：

    Error 'logic_error' was not declared in this scope
    */
    if(stack2.size() == 0)
        throw "queue is empty";
        // throw new exception("queue is empty");

    T head = stack2.top();
    stack2.pop();

    return head;
}
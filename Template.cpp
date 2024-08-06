#include <iostream>
#include <vector>

using namespace std;

/*
template <typename type> ret-type func-name(parameter list)
{
   // 函数的主体
}
*/
template <typename T>
T add(T number1, T number2) {
    return number1 + number2;
}

/*
template <class type> class class-name {
   // 类的主体
}
*/
template <class T>
class Stack {
   private:
    vector<T> elems;  // 元素

   public:
    void push(T const &);  // 入栈
    void pop();            // 出栈
    T top() const;         // 返回栈顶元素
    bool empty() const {   // 如果为空则返回真
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const &elem) {
    // 追加传入元素的副本
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

int main(int argc, char const *argv[]) {
    cout << add(1, 2) << "\n";
    cout << add(1.1, 2.2) << "\n";

    Stack<int> intStack;
    intStack.push(7);
    cout << "top(): " << intStack.top() << "\n";
    intStack.pop();
    cout << "top(): " << intStack.top() << "\n";
    cout << "empty(): " << intStack.empty();

    return 0;
}

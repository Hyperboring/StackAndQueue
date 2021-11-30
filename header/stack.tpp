#include "windows.h"

template<typename T>
Stack<T>::Stack() {
    arr = new T[size];
    for (int i = 0; i < size; i++)
        arr[i] = T();
}

template<typename T>
Stack<T>::Stack(int len) {
    this->size = len;
    arr = new T[len];
    for (int i = 0; i < len; i++)
        arr[i] = T(); // zero initialization
}

// возвращает индекс, куда записан элемент или -1, если стек забит
template<typename T>
int Stack<T>::push(T b) {
    if (top == size - 1)
        return -1;
    arr[++top] = b;
    return top;
}

// возвращает структуру книги или пустую структуру, если стек пуст
template<typename T>
T Stack<T>::pop() {
    if (isEmpty())
        return arr[0];
    T b = arr[top];
    arr[top] = T();
    top--;
    return b;
}

template<typename T>
bool Stack<T>::isEmpty()
const {
    return top == -1;
}

template<typename T>
int Stack<T>::getSize()
const {
    return top + 1;
}

template<typename T>
int Stack<T>::clear() {
    if (isEmpty())
        return 0;
    int cl = top;
    top = -1;
    for (int i = 0; i < cl; i++)
        arr[i] = T();
    return cl + 1;
}

template<typename T>
T Stack<T>::getTop() {
    if (isEmpty())
        return arr[0];
    return arr[top];
}

template<typename T>
void Stack<T>::close() {
    delete[] arr;
}
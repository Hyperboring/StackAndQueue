#include <iostream>
#include <stack>

using namespace std;

#define STACK_SIZE 6

struct Stack {

    int size;
    int *arr;
    int top = -1;

    Stack() {
        size = STACK_SIZE;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    // запретит создание объекта с помощью Stack stack = 6;
    explicit Stack(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    // returns 0xFFF if stack is full
    // returns 1 if int was pushed into stack
    int push(int i) {
        if (top == size - 1)
            return -0xFFF;
        arr[++top] = i;
        return 1;
    }

    // returns 0xFFF if stack is empty
    // returns top int if stack is not empty
    int pop() {
        if (isEmpty())
            return -0xFFF;
        int a = arr[top];
        arr[top--] = 0;
        return a;
    }

    bool isEmpty()
    const {
        return top == -1;
    }

    int getSize()
    const {
        return this->size;
    }

    // returns 0xFFF if stack is empty
    int getTop()
    const {
        if (isEmpty()) return -0xFFF;
        return arr[top];
    }

    // returns a number of cleared elements
    int clear() {
        for (int i = top; i >= 0; i--)
            arr[i] = 0;
        int cl = top + 1;
        top = -1;
        return cl; // FIXME 13:19
    }

};

int main() {
    Stack stack(6);
    Stack *ptr = &stack;
    ptr->push(11);
    ptr->push(22);
    ptr->push(44);
    printf("%d\n", ptr->pop()); // 44
    printf("%d\n", ptr->clear()); // 2
    printf("%d %d\n", ptr->getTop(), ptr->top); // -4095 -1
    return 0;
}

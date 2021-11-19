#include <iostream>
#include <stack>

using namespace std;

#define STACK_SIZE 6
#define QUEUE_SIZE 6

struct Stack {

    unsigned int size;
    int *arr;
    int top = -1;

    Stack() {
        size = STACK_SIZE;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    // explicit keyw запретит создание объекта с помощью Stack stack = 6;
    explicit Stack(unsigned int size) {
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
        return top + 1;
    }

    // returns 0xFFF if stack is empty
    int getTop()
    const {
        if (isEmpty())
            return -0xFFF;
        return arr[top];
    }

    // returns a number of cleared elements
    int clear() {
        for (int i = top; i >= 0; i--)
            arr[i] = 0;
        int cl = top + 1;
        top = -1;
        return cl;
    }

    // commit suicide
    void close() {
        delete[] arr;
        delete this;
    }

};

struct Queue {

    int head = 0;
    int tail = 0;
    int *arr;
    unsigned int size;

    Queue() {
        size = QUEUE_SIZE;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    explicit Queue(unsigned int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    int push(int i) {
        if (getSize() == size)
            return -0xFFF;
        arr[tail] = i;
        tail = (tail + 1) % (int) size;
        return i;
    }

    int pop() {
        if (isEmpty())
            return -0xFFF;
        int i = arr[head];
        head = (head + 1) % (int) size;
        return i;
    }

    int getFront()
    const {
        return arr[head];
    }

    int clear() {
        int i = head > tail ? head : tail;
        int j = i == head ? tail : head;
        for (int k = i; k >= j; k--)
            arr[k] = 0;
        int cl = i - j + 1;
        tail = 0;
        head = 0;
        return cl;
    }

    bool isEmpty()
    const {
        return head == tail;
    }

    int getSize()
    const {
        if (head > tail)
            return (int) size - head + tail + 1;
        else
            return tail - head + 1;
    }

};

int main() {
    Stack stack(6);
    Stack *ptr = &stack;
    ptr->push(11);
    ptr->push(22);
    ptr->push(44);
    printf("%d\n", ptr->pop()); // 44
    printf("%d %d\n", ptr->getSize(), ptr->top + 1); // 2 2
    printf("%d\n", ptr->clear()); // 2
    printf("%d %d\n", ptr->getTop(), ptr->top); // -4095 -1

    Queue queue(6);
    printf("%d\n", queue.pop()); // -4095
    queue.push(11);
    queue.push(44);
    queue.push(22);
    queue.push(66);
    queue.push(88);
    queue.push(100);
    queue.push(111); // ignored with -4095
    printf("%d\n", queue.pop()); // 11
    printf("%d\n", queue.pop()); // 44
    printf("%d\n", queue.getSize()); // 4
    printf("%d %d %d\n", queue.getFront(), queue.tail, queue.head); // 22 5 2
    printf("%d\n", queue.clear()); // 4
    return 0;
}

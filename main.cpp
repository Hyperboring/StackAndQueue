#include <iostream>
#include <ctime>

using namespace std;

#define STACK_SIZE 6
#define QUEUE_SIZE 6

struct Book {
    char *name;
    int pages;
    int price;
};

struct Stack {

    unsigned int size;
    Book *(*arr);
    int top = -1;

    Stack() {
        size = STACK_SIZE;
        arr = (Book **) (malloc(size * sizeof(Book *)));
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    // explicit keyw запретит создание объекта с помощью Stack stack = 6;
    explicit Stack(unsigned int size) {
        this->size = size;
        arr = (Book **) (malloc(size * sizeof(Book *)));
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    // returns -0xFFF if stack is full
    // returns 1 if book was pushed into stack
    int push(Book book) {
        if (top == size - 1)
            return -0xFFF;
        arr[++top] = &book;
        return 1;
    }

    // returns nullptr if stack is empty
    // returns top book if stack is not empty
    Book* pop() {
        if (isEmpty())
            return nullptr;
        Book *b = arr[top];
        arr[top--] = nullptr;
        return b;
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
    Book* getTop()
    const {
        if (isEmpty())
            return nullptr;
        return arr[top];
    }

    // returns a number of cleared elements
    int clear() {
        for (int i = top; i >= 0; i--)
            arr[i] = nullptr;
        int cl = top + 1;
        top = -1;
        return cl;
    }

    // commit suicide
    void close() {
//        delete[] arr;
        free(arr);
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

int getRandPages() {
    return rand() % 2000 + 50;
}

int main() {
    srand(time(nullptr));
    Stack books(6);
    auto *ptr = &books;
    /*
     TODO 20.11
    book_1book_2book_3book_4book_5book_5
    x¤a
     */
    for (int i = 0; i < 5; i++) {
        char name[32];
        sprintf(name, "book_%d", i + 1);
        printf("%s", name);
        ptr->push({name, getRandPages(), 20*i});
    }
    printf("%s\n", ptr->pop()->name);
    printf("%s\n", ptr->pop()->name);
    for (int i = 5; i < 9; i++) {
        char name[32];
        sprintf(name, "book_%d", i + 1);
        printf("%d\n", ptr->push({name, getRandPages(), 20*i}));
    }
    ptr->pop()->pages -= 10;
    for (int i = 0; i < 8; i++) {
        Book *b = ptr->pop();
        printf("%d\n", b == nullptr ? -0xFFF : b->price);
    }
}

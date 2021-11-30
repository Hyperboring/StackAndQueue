#pragma once

#define STACK_SIZE 6
#define QUEUE_SIZE 4

struct Book {
    char name[64];
    int pages;
    double price;

    bool isNull() const;
};

struct Song {
    char name[64];
    long length;
    int likes;

    bool isNull() const;
};

namespace general {

    template<typename T>
    struct Stack {

        static const int size = STACK_SIZE;
        T *arr;
        int top = -1;

        Stack();
        explicit Stack(int len);

        // возвращает индекс, куда записан элемент или -1, если стек забит
        int push(T b);

        // возвращает структуру книги или пустую структуру, если стек пуст
        T pop();
        bool isEmpty() const;
        int getSize() const;
        int clear();
        T getTop();
        void close();
    };

    struct Queue {
        static const int size = QUEUE_SIZE + 1;
        Song arr[size]{};
        int head = 0;
        int tail = 0;

        int push(Song b);
        Song pop();
        bool isEmpty() const;
        int getSize() const;
        int clear();
        Song getFront();
    };

    void printBook(Stack<Book> *stack);
    void printQueue(Queue *queue);
}

namespace extra {

    char getInverseBrace(char brace);
}

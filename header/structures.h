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

    struct Stack {

        static const int size = STACK_SIZE;
        Book arr[size]{};
        int top = -1;

        Stack();

        // возвращает индекс, куда записан элемент или -1, если стек забит
        int push(Book b);

        // возвращает структуру книги или пустую структуру, если стек пуст
        Book pop();
        bool isEmpty() const;
        int getSize() const;
        int clear();
        Book getTop();
        void print();
    };

    struct Queue {
        static const int size = QUEUE_SIZE + 1;
        Song arr[size]{};
        int head = 0;
        int tail = 0;

        Queue();

        int push(Song b);
        Song pop();
        bool isEmpty() const;
        int getSize() const;
        int clear();
        Song getFront();
        void print();
    };
}

namespace extra {

    char getInverseBrace(char brace);

    struct Stack {

        char *arr{};
        int size;
        int top = -1;

        explicit Stack(int size);

        int push(char b);
        char pop();
        bool isEmpty() const;
        int getSize() const;
        int clear();
        char getTop() const;
        void print();
        void close() const;
    };
}

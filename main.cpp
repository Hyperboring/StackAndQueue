#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

#define STACK_SIZE 6
#define QUEUE_SIZE 4

struct Book {
    char *name;
    int pages;
    int price;

    bool isNull()
    const {
        return strcmp(name, "null") == 0 && pages == -1 && price == -1;
    }

};

static constexpr Book NULL_BOOK = { (char*) "null", -1, -1};

struct Stack {

    static const int size = STACK_SIZE;
    Book arr[size]{};
    int top = -1;

    Stack() {
        for (Book &b : arr)
            b = NULL_BOOK;
    }

    // возвращает индекс, куда записан элемент или -1, если стек забит
    int push(Book b) {
        if (top == size - 1)
            return -1;
        arr[++top] = b;
        return top;
    }

    // возвращает структуру книги или пустую структуру, если стек пуст
    Book pop() {
        if (isEmpty())
            return NULL_BOOK;
        Book b = arr[top];
        arr[top] = NULL_BOOK;
        top--;
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

    int clear() {
        if (isEmpty())
            return 0;
        int cl = top;
        top = -1;
        for (int i = 0; i < cl; i++)
            arr[i] = NULL_BOOK;
        return cl;
    }

    Book getTop() {
        if (isEmpty())
            return NULL_BOOK;
        return arr[top];
    }

    void print() {
        for (Book &b : arr)
            printf("Book: %s Pages: %d, Price: %d\n", b.name, b.pages, b.price);
    }

};

struct Song {
    char *name;
    long length;
    int likes;
};

static constexpr Song NULL_SONG = {(char*) "null", -1, -1};

struct Queue {

    static const int size = QUEUE_SIZE;
    Song arr[size]{};
    int head = 0;
    int tail = 0;

    Queue() {
        for (Song &s : arr)
            s = NULL_SONG;
    }

    // возвращает индекс, куда записан элемент или -1, если очередь забита
    int push(Song s) {
        if (head + tail == size - 1)
            return -1;
        int i = head;
        arr[i] = s;
        head = (head + 1) % size;
        return i;
    }

    Song pop() {
        if (isEmpty())
            return NULL_SONG;
        Song s = arr[tail];
        arr[tail] = NULL_SONG;
        tail = (tail + 1) % size;
        return s;
    }

    bool isEmpty()
    const {
        return head == tail;
    }

    int getSize()
    const {
        return head > tail ? head - tail : tail - head;
    }

    int clear() {
        if (isEmpty())
            return 0;
        int left = head > tail ? tail : head;
        int right = head > tail ? head : tail;
        for (int i = left; i < right; i++) {
            arr[i] = NULL_SONG;
        }
        return right - left;
    }

    Song getFront() {
        return head == 0 ? arr[size - 1] : arr[head - 1];
    }

    void print() {
        for (Song &s : arr)
            printf("Song: %s Length: %d, Likes: %d\n", s.name, s.length, s.likes);
    }

};

int main() {
    srand(time(nullptr));
    SetConsoleOutputCP(CP_UTF8);
    Stack books;
    books.push({(char*) "book_1", 300, 100});
    books.push({(char*) "book_2", 344, 80});
    books.push({(char*) "book_3", 290, 57});
    books.push({(char*) "book_4", 122, 90});
    books.push({(char*) "book_5", 60, 89});
    cout << "\ncheck 1\n\n";
    books.print();
    books.pop();
    books.pop();
    cout << "\ncheck 2\n\n";
    books.print();
    books.push({(char*) "book_6", 300, 100});
    books.push({(char*) "book_7", 344, 80});
    books.push({(char*) "book_8", 290, 57});
    books.push({(char*) "book_9", 122, 90});
    cout << "\ncheck 3\n\n";
    books.print();
    Book b = books.pop();
    b.pages -= 10;
    books.push(b);
    cout << "\ncheck 4\n\n";
    books.print();
}

#include "../header/structures.h"
#include "windows.h"
#include "iostream"

static constexpr Song NULL_SONG = {"null", -1, -1};

bool Book::isNull() const {
    return strcmp(name, "null") == 0 && pages == -1 && price == -1;
}

bool Song::isNull() const {
    return strcmp(name, "null") == 0 && length == -1 && likes == -1;
}

/*
 * STACK
 */




// TODO переписать отдельной функцией вне стека (очереди)
void printBook(Stack<Book> *stack) {
    Book parr[Stack<Book>::size];
    for (Book &b : parr)
        b = stack->pop();
    for (int i = Stack<Book>::size - 1; i >= 0; i--) { // Clang-Tidy: Static member accessed through instance when stack->size
        Book b = parr[i];
        if (!b.isNull())
            printf("Book: %s, Pages: %d, Price: %.3f.\n",
                   b.name,
                   b.pages,
                   b.price);
        stack->push(b);
    }
}

/*
 * QUEUE
 */


// возвращает индекс, куда записан элемент или -1, если очередь забита
int Queue::push(Song s) {
    if (getSize() == size - 1)
        return -1;
    int i = tail;
    tail = (tail + 1) % size;
    arr[i] = s;
    return i;
}

Song Queue::pop() {
    if (isEmpty())
        return NULL_SONG;
    Song s = arr[head];
    arr[head] = NULL_SONG;
    head = (head + 1) % size;
    return s;
}

bool Queue::isEmpty()
const {
    return head == tail;
}

int Queue::getSize()
const {
    return head > tail ?
           size - head + tail :
           tail - head;
}

int Queue::clear() {
    if (isEmpty()) {
        head = 0;
        tail = 0;
        return 0;
    }
    int cl;
    if (head < tail) {
        cl = tail - head;
        for (int i = head; i < tail; i++)
            arr[i] = NULL_SONG;
    } else {
        cl = size - head + tail;
        for (int i = 0; i <= tail; i++)
            arr[i] = NULL_SONG;
        for (int i = head; i < size; i++)
            arr[i] = NULL_SONG;
    }
    head = 0;
    tail = 0;
    return cl;
}

Song Queue::getFront() {
    if (isEmpty())
        return NULL_SONG;
    return arr[head];
}

//void Queue::print() {
//    Song parr[size];
//    for (Song &s : parr)
//        s = pop();
//    for (Song s : parr) {
//        if (!s.isNull())
//            printf("Song: %s, Length: %d, Likes: %d.\n",
//                   s.name,
//                   s.length,
//                   s.likes);
//        push(s);
//    }
//}

/*
 * EXTRA
 */



char extra::getInverseBrace(char brace) {
    switch (brace) {
        case '{':
            return '}';
        case '(':
            return ')';
        case '[':
            return ']';
        default:
            return '?';
    }
}
//
//extra::Stack::Stack(int size) {
//    this->size = size;
//    arr = new char[size];
//    for (int i = 0; i < size; i++)
//        arr[i] = '?';
//}
//
//// возвращает индекс, куда записан элемент или -1, если стек забит
//int extra::Stack::push(char b) {
//    if (top == size - 1)
//        return -1;
//    arr[++top] = b;
//    return top;
//}
//
//// возвращает структуру книги или пустую структуру, если стек пуст
//char extra::Stack::pop() {
//    if (isEmpty())
//        return '?';
//    char b = arr[top];
//    arr[top] = '?';
//    top--;
//    return b;
//}
//
//bool extra::Stack::isEmpty()
//const {
//    return top == -1;
//}
//
//int extra::Stack::getSize()
//const {
//    return top + 1;
//}
//
//int extra::Stack::clear() {
//    if (isEmpty())
//        return 0;
//    int cl = top;
//    top = -1;
//    for (int i = 0; i < cl; i++)
//        arr[i] = '?';
//    return cl + 1;
//}
//
//char extra::Stack::getTop()
//const {
//    if (isEmpty())
//        return '?';
//    return arr[top];
//}
//
//void extra::Stack::print() {
//    char parr[size];
//    for (char &c : parr)
//        c = pop();
//    for (int i = size - 1; i >= 0; i--) {
//        char b = parr[i];
//        printf("%c ", b);
//        push(b);
//    }
//}
//
//void extra::Stack::close() const {
//    delete[] arr;
////    delete this;
//}
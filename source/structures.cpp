#include "../header/structures.h"
#include "windows.h"
#include "iostream"

static constexpr Song NULL_SONG = {"", 0, 0};

bool Book::isNull() const {
    return strcmp(name, "") == 0 && pages == 0 && price == 0;
}


bool Song::isNull() const {
    return strcmp(name, "") == 0 && length == 0 && likes == 0;
}

/*
 * STACK
 */



void printBook(Stack<Book> *stack) {
    Stack<Book> s = *stack;
    Book parr[stack->size];
    for (Book &b : parr)
        b = stack->pop();
    for (int i = stack->size - 1; i >= 0; i--) { // Clang-Tidy: Static member accessed through instance when stack->size
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

void printQueue(Queue *queue) {
    Song parr[Queue::size];
    for (Song &s : parr)
        s = queue->pop();
    for (Song s : parr) {
        if (!s.isNull())
            printf("Song: %s, Length: %d, Likes: %d.\n",
                   s.name,
                   s.length,
                   s.likes);
        queue->push(s);
    }
}

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
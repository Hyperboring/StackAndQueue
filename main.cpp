#include <iostream>
#include <ctime>

using namespace std;

/*
 TODO: LAST LOG
 queue
1
1
1
1
1
1
check 1
song_5 600 88 at arr[0]
song_6 500 110 at arr[1]
song_3 800 44 at arr[2]
song_4 700 66 at arr[3]
size: 2
check 2
1
nullptr at arr[0]
nullptr at arr[1]
song_5 600 88 at arr[2]
song_4 700 66 at arr[3]
1
check 3
nullptr at arr[0]
nullptr at arr[1]
nullptr at arr[2]
song_6 500 110 at arr[3]
1
110
188
-4095
-4095
-4095
check 4
nullptr at arr[0]
nullptr at arr[1]
nullptr at arr[2]
nullptr at arr[3]
 */

/*
 нужна ли функция суицида структуре?
 как решить проблему с выводом данных структуры
 */

#define STACK_SIZE 6
#define QUEUE_SIZE 4

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
        arr = new Book*[size];
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    void printArr() const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == nullptr) continue;
            printf("%s %d %d\n", arr[i]->name, arr[i]->price, arr[i]->pages);
        }
    }

    // explicit keyw запретит создание объекта с помощью Stack stack = 6;
    explicit Stack(unsigned int size) {
        this->size = size;
        arr = new Book*[size];
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    // returns -0xFFF if stack is full
    // returns 1 if book was pushed into stack
    int push(Book *book) {
        if (top == size - 1)
            return -0xFFF;
        arr[++top] = book;
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
        delete[] arr;
//        free(arr);
        delete this;
    }
};

struct Song {
    char *name;
    long length;
    int likes;
};

struct Queue {

    int head = 0;
    int tail = 0;
    Song *(*arr);
    unsigned int size;

    Queue() {
        size = QUEUE_SIZE;
        arr = new Song*[size];
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    explicit Queue(unsigned int size) {
        this->size = size;
        arr = new Song*[size];
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    void printArr() const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == nullptr) {
                printf("nullptr at arr[%d]\n", i);
                continue;
            }
            printf("%s %d %d at arr[%d]\n", arr[i]->name, arr[i]->length, arr[i]->likes, i);
        }
    }

    // TODO 20.11
    int push(Song *song) {
        if (getSize() == size)
            return -0xFFF;
        arr[tail] = song;
        tail = (tail + 1) % (int) size;
        return 1;
    }

    // TODO 20.11
    // returns nullptr if queue is empty
    Song* pop() {
        if (isEmpty())
            return nullptr;
        Song *s = arr[head];
        arr[head] = nullptr;
        head = (head + 1) % (int) size;
        return s;
    }

    Song* getFront()
    const {
        return arr[head];
    }

    int clear() {
        int i = head > tail ? head : tail;
        int j = i == head ? tail : head;
        for (int k = i; k >= j; k--)
            arr[k] = nullptr;
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
            return head - tail;
        else
            return tail - head;
    }

};

int getRandPages() {
    return rand() % 2000 + 50;
}

int main() {
    srand(time(nullptr));
//    Stack books(6);
//    auto *ptr = &books;
//    char* name;
//    for (int i = 0; i < 5; i++) {
//        name = new char[32];
//        sprintf(name, "book_%d", i + 1);
//        ptr->push(new Book{name, getRandPages(), 20*i});
//    }
//    ptr->printArr();
//    printf("%s\n", ptr->pop()->name);
//    printf("%s\n", ptr->pop()->name);
//    for (int i = 5; i < 9; i++) {
//        name = new char[32];
//        sprintf(name, "book_%d", i + 1);
//        ptr->push(new Book{name, getRandPages(), 20*i});
//    }
//    ptr->printArr();
//    delete[] name;
//    Book book = *(ptr->pop());
//    book.pages -= 10;
//    ptr->push(&book);
//    for (int i = 0; i < 8; i++) {
//        Book *b = ptr->pop();
//        printf("%d\n", b == nullptr ? -0xFFF : b->price);
//    }

    printf("queue\n");
    Queue queue(4);
    auto *ptr_2 = &queue;
    char *song_name;
    for (int i = 0; i < 6; i++) { // 1
        song_name = new char[32];
        sprintf(song_name, "song_%d", i + 1);
        printf("%d\n", ptr_2->push(new Song{song_name, 1000 - (100 * i), 22 * i}));
    }
    cout << "check 1\n";
    ptr_2->printArr();
    cout << "size: " << ptr_2->getSize() << endl;
    Song song1 = *(ptr_2->pop()); // 2
    Song song2 = *(ptr_2->pop());
    cout << "check 2\n";
    printf("%d\n", ptr_2->push(&song1)); // 3
    ptr_2->printArr();
    printf("%d\n", ptr_2->push(&song2));
    Song s = *(ptr_2->pop());
    s.likes += 100;
    cout << "check 3\n";
    ptr_2->printArr();
    printf("%d\n", ptr_2->push(&s)); // 4
    for (int i = 0; i < 5; i++) {
        Song *obj = ptr_2->pop();
        printf("%d\n", obj == nullptr ? -0xFFF : obj->likes);
    }
    cout << "check 4\n";
    ptr_2->printArr();
}

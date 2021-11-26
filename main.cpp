#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

#define STACK_SIZE 6
#define QUEUE_SIZE 4

struct Book {
    char name[64];
    int pages;
    double price;

    bool isNull()
    const {
        return strcmp(name, "null") == 0 && pages == -1 && price == -1;
    }

};

static constexpr Book NULL_BOOK = {"null", -1, -1};

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
        return cl + 1;
    }

    Book getTop() {
        if (isEmpty())
            return NULL_BOOK;
        return arr[top];
    }

    void print() {
        Book parr[size];
        for (Book &b : parr)
            b = pop();
        for (int i = size - 1; i >= 0; i--) {
            Book b = parr[i];
            if (!b.isNull())
                printf("Book: %s, Pages: %d, Price: %.3f.\n",
                       b.name,
                       b.pages,
                       b.price);
            push(b);
        }
    }

};

struct Song {
    char name[64];
    long length;
    int likes;

    bool isNull()
    const {
        return strcmp(name, "null") == 0 && length == -1 && likes == -1;
    }
};

static constexpr Song NULL_SONG = {"null", -1, -1};

struct Queue {

    static const int size = QUEUE_SIZE + 1;
    Song arr[size]{};
    int head = 0;
    int tail = 0;

    Queue() {
        for (Song &s : arr)
            s = NULL_SONG;
    }

    // возвращает индекс, куда записан элемент или -1, если очередь забита
    int push(Song s) {
        if (getSize() == size - 1)
            return -1;
        int i = tail;
        tail = (tail + 1) % size;
        arr[i] = s;
        return i;
    }

    Song pop() {
        if (isEmpty())
            return NULL_SONG;
        Song s = arr[head];
        arr[head] = NULL_SONG;
        head = (head + 1) % size;
        return s;
    }

    bool isEmpty()
    const {
        return head == tail;
    }

    int getSize()
    const {
        return head > tail ?
        size - head + tail :
        tail - head;
    }

    int clear() {
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

    Song getFront() {
        if (isEmpty())
            return NULL_SONG;
        return arr[head];
    }

    void print() {
        Song parr[size];
        for (Song &s : parr)
            s = pop();
        for (Song s : parr) {
            if (!s.isNull())
                printf("Song: %s, Length: %d, Likes: %d.\n",
                       s.name,
                       s.length,
                       s.likes);
            push(s);
        }
    }

};

void bookStack() {
    Book storage[9]{
            {"Da Vinci Code", 680, 79.99},
            {"Harry Potter and the Deathly Hallows", 340, 29.99},
            {"Fifty Shades of Grey", 705, 109.99},
            {"Angels and Demons", 250, 29.99},
            {"Twilight", 904, 19.79},
            {"New Moon", 588, 18.99},
            {"Short History of Nearly Everything", 1390, 99.99},
            {"Very Hungry Caterpillar", 80, 15.99},
            {"Gruffalo", 129, 9.99}
    };
    Stack books;
    for (int i = 0; i < 5; i++)
        books.push(storage[i]);
    books.pop();
    books.pop();
    for (int i = 5; i < 9; i++) {
        books.push(storage[i]);
    }
    Book b = books.pop();
    b.pages -= 10;
    books.push(b);
    books.print();
    for (int i = 0; i < 8; i++) {
        books.pop();
    }
}

void playlist() {
    Song music[6]{
            {"Melancholy", 315, 2312676},
            {"Gravesinger", 238, 2058061},
            {"Underneath a Sullen Moon", 279, 1401652},
            {"Flamewall", 410, 411499},
            {"Empress of Light", 169, 80431},
            {"The Endless Void", 230, 15490}
    };
    Queue playlist;
    for (const Song &s : music)
        playlist.push(s);
    Song s1 = playlist.pop();
    Song s2 = playlist.pop();
    playlist.push(s2);
    playlist.push(s1);

    s1 = playlist.pop();
    s1.likes += 100;
    playlist.push(s1);

    playlist.print();
    for (int i = 0; i < 5; i++)
        playlist.pop();
}

char getInverseBrace(char brace) {
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

bool braces(char braces[], int len) {
    if (len % 2 != 0)
        return false;

    struct bStack {
        char *arr{};
        int size;
        int top = -1;

        explicit bStack(int size) {
            this->size = size;
            arr = new char[size];
            for (int i = 0; i < size; i++)
                arr[i] = '?';
        }

        // возвращает индекс, куда записан элемент или -1, если стек забит
        int push(char b) {
            if (top == size - 1)
                return -1;
            arr[++top] = b;
            return top;
        }

        // возвращает структуру книги или пустую структуру, если стек пуст
        char pop() {
            if (isEmpty())
                return '?';
            char b = arr[top];
            arr[top] = '?';
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
                arr[i] = '?';
            return cl + 1;
        }

        char getTop()
        const {
            if (isEmpty())
                return '?';
            return arr[top];
        }

        void print() {
            char parr[size];
            for (char &c : parr)
                c = pop();
            for (int i = size - 1; i >= 0; i--) {
                char b = parr[i];
                printf("%c ", b);
                push(b);
            }
        }

        void close() {
            delete[] arr;
            delete this;
        }
    };
    bStack s(len);
    bool b = false;
    for (int i = len - 1; i >= 0; i--) {
        if (s.getTop() != '?' && s.getTop() == getInverseBrace(braces[i])) {
            b = true;
            s.pop();
        } else {
            s.push(braces[i]);
            b = false;
        }
    }
    return b;
}

int main() {
    srand(time(nullptr));
    SetConsoleOutputCP(CP_UTF8);

    bookStack();
    cout << endl;
    playlist();
    cout << endl;
    const int size = 6;
    char arr[size]{'{', '[', '(', ')', ')', '}'};
    printf("%d\n", braces(arr, size));

    // TODO доп задание
}

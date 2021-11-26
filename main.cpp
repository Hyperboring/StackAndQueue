#include <iostream>
#include <ctime>
#include <windows.h>
#include "header/structures.h"

using namespace std;

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
    general::Stack books;
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
    general::Queue playlist;
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



bool braces(char braces[], int len) {
    if (len % 2 != 0)
        return false;

    extra::Stack s(len);
    bool b = false;
    for (int i = len - 1; i >= 0; i--) {
        if (s.getTop() != '?' && s.getTop() == extra::getInverseBrace(braces[i])) {
            b = true;
            s.pop();
        } else {
            s.push(braces[i]);
            b = false;
        }
    }
    s.clear();
    s.close();
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
    char arr[size]{'{', '[', '(', ')', ']', '}'};
    printf("%d\n", braces(arr, size));
}

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
    Stack<Book> books;
    for (int i = 0; i < 5; i++) {
        books.push(storage[i]);
    }
    books.pop();
    books.pop();
    printBook(&books);
    for (int i = 5; i < 9; i++) {
        books.push(storage[i]);
    }
    Book b = books.pop();
    b.pages -= 10;
    books.push(b);
    for (int i = 0; i < 8; i++) {
        books.pop();
    }
    books.close();
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

    printQueue(&playlist);
    for (int i = 0; i < 5; i++)
        playlist.pop();
}

string braces(char braces[], unsigned int len) {
    if (len % 2 != 0)
        return "no";

    Stack<char> s((int) len);
    for (int i = (int) len - 1; i >= 0; i--) {
        if (s.getTop() == extra::getInverseBrace(braces[i]))
            s.pop();
        else
            s.push(braces[i]);
    }
    bool b = s.isEmpty();
    s.clear();
    s.close();
    return b ? "yes" : "no";
}

int main() {
    srand(time(nullptr));
    SetConsoleOutputCP(CP_UTF8);

    bookStack();
    cout << endl;
    playlist();
    cout << endl;
//    const int size = 6;
//    char arr[size]{'{', '[', '(', ')', ']', '}'};
    string s;
    cin >> s;
    unsigned int len = s.length();
    char *c_str = &s[0];
    cout << braces(c_str, len) << endl;
}

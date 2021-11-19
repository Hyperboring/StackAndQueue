#include <iostream>
#include "header/structures.h"

using namespace std;

int main() {
    Stack stack(6);
    Stack *ptr = &stack;
    ptr->push(11);
    ptr->push(22);
    ptr->push(44);
    printf("%d\n", ptr->pop()); // 44
    printf("%d %d\n", ptr->getSize(), ptr->top + 1); // 2 2
    printf("%d\n", ptr->clear()); // 2
    printf("%d %d\n", ptr->getTop(), ptr->top); // -4095 -1
//
//    Queue queue(6);
//    printf("%d\n", queue.pop()); // -4095
//    queue.push(11);
//    queue.push(44);
//    queue.push(22);
//    queue.push(66);
//    queue.push(88);
//    queue.push(100);
//    queue.push(111); // ignored with -4095
//    printf("%d\n", queue.pop()); // 11
//    printf("%d\n", queue.pop()); // 44
//    printf("%d\n", queue.getSize()); // 4
//    printf("%d %d %d\n", queue.getFront(), queue.tail, queue.head); // 22 5 2
//    printf("%d\n", queue.clear()); // 4
//    return 0;
}

#include <forward_list> // Single Linked List
#include <iostream>
#include <list> // Doubly Linked List
#include "BrowserHistory.h"
using std::cout;
using std::cin;
using std::forward_list;
using std::list;
int main () {
    BrowserHistory* obj = new BrowserHistory("www.google.com");
    obj->visit("www.youtube.com");
    string param_2 = obj->back(5);
    string param_3 = obj->forward(5);
    return 0;
}
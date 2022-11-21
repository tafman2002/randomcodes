#include<iostream>
#include <algorithm>  // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>
using namespace std;
/*
Rearranges the elements in the range [first,last) in such a way that they form a heap.

A heap is a way to organize the elements of a range that allows for fast retrieval of the element with the highest value at any moment 
(with pop_heap), even repeatedly, while allowing for fast insertion of new elements (with push_heap).
The element with the highest value is always pointed by first
*/
void practice_heap();


int main() {
    practice_heap();
    return 0;
}

void practice_heap() {
    vector<int> mylist {5,2,7,12,13,1,5,4,20};
    std::make_heap(mylist.begin(),mylist.end());
    cout << "After making heap:" << endl;
    for (auto x : mylist) {
        cout << x << " ";
    }
    cout << endl;
    std::pop_heap(mylist.begin(),mylist.end());
    cout << "After popping from heap, front is " << mylist.front() << endl;
}
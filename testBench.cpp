#include <iostream>
#include "Node.hpp"
#include "SingleLinked.hpp"

using namespace std;

int main(){
    // This  is a testbench and demonstration of Linked-Lists
    SingleLinked list = SingleLinked();
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    cout << "Append: " << list;
}

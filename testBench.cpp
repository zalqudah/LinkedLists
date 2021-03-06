#include <iostream>
#include <fstream>
#include "Node.hpp"
#include "SingleLinked.hpp"

using namespace std;

int main(){
    fstream out("OUTPUT.dat");
    // This  is a testbench and demonstration of Linked-Lists
    SingleLinked list = SingleLinked();
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    out << "Append: " << list;

    list.push(-1);
    list.push(-2);
    out << "Pushed: " << list;
    //OUTPUT should be  Pushed: -2 -1 0 1 2 3 4
    out.close();
}

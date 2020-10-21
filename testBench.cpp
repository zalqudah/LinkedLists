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

    list.insert(0, 888);
    list.insert(2, 777);
    list.insert(1, 333);
    out << "Insert: " << list;

    list.remove(1);
    out << "Remove: " << list;
    list.remove(0);
    out << "Remove: " << list;
    out << "LENGTH: " << list.size();
    out.close();
}

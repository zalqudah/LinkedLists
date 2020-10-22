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
    list.remove(0);
    out << "Remove: " << list;
    out << "LENGTH: " << list.size() << endl;

    SingleLinked listPop(list.pop());
    out << "Popped: " << list;
    out << "Popped out: " << listPop;
    
    list.reverse();
    out << "Reversed: " << list;

    out << "At 1: " << list.at(1) << endl;
    out << "At 5: " << list.at(5) << endl;
    //past list length
    out << "Past List @ 7: " << list.at(7) << endl;
    SingleLinked l = list;
    list.sublist(1,5);
    out << "Sub list 1-5: " << list;
    out << list;
    out << l;
    /*out << "Sub list 0-3: " << SingleLinked(list.sublist(0,3));
    out << list;
    out << "Sub list 0-end: " << SingleLinked(list.sublist(0,list.size()));*/
    out.close();
}
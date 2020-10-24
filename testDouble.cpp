#include <iostream>
#include "Node.hpp"
#include "DoubleLinked.hpp"

using namespace std;

int main(){
    DoubleLinked dl;
    dl.push(0);
    dl.push(0);
    dl.push(0);
    dl.push(0);
    dl.replace(0,-1);
    dl.replace(1,1);
    dl.append(5);
    dl.insert(0,3);
    dl.insert(7,7);
    dl.stitch(); //Converts to circular list
    dl.append(35);
    dl.push(36);
    dl.push(36);
    dl.push(36);
    dl.rip(3); //Converts to non-circular list
    dl.shift(1);
    DoubleLinked F = dl;
    //dl = dl + 1;
    cout << dl;
    cout << dl.isCircular() << endl;
}
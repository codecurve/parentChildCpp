//
//  main.cpp
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

/**
 * Demonstrates one-to-many relationship with parent ownership semantics,
 * and bi-directional navigability.
 * Memory management using std::shared_ptr and related utilities.
 *
 * Objects of type B are created through A, so that they are never orphans.
 * Also, the collection of children of an A object cannot have members added or removed.
 *
 * So far this has only been tested on XCode 5.1.1
 */

#include "ClassA.h"

#include <iostream>
#include <memory>

using namespace std;


int main(int argc, const char * argv[])
{

    // Demonstrate creating a parent, and creating children through the parent.
    // The parent is mutable.
    // Recommendation: all handle's are shared_ptr.
    shared_ptr<A> a(new A(L"The first A object"));
    a->createB(5);
    a->createB(55);
    a->createB(5555);
    a->createB(-345);
    a->createB(2316724);
    a->createB(0);
    bCollectionT bs = a->getBs();
    //bs.push_back(make_shared<B>(42)); // Compile error <= const (otherwise new children could be "smuggled in").
    for(auto b : bs) {
        b->setCount(b->getCount()*10000); // Demonstrate that each child is mutable.
        auto aName = b->getA().lock()->getName();
        wcout << b->getCount() << " - " << aName  << endl;
    }

    cout << "**********************" << endl;

    // Repeat the above output (this demonstrates that we really modified the underlying children, not just copies of them.
    for(auto b : a->getBs()) {
        wcout << b->getCount() << " - " << b->getA().lock()->getName() << endl;
    }

    cout << "**********************" << endl;

    // If we start out with a const parent (i.e. instance of A), we can't even add children!
    const shared_ptr<const A> ac = const_pointer_cast<const A>(make_shared<A>(L"The second A object"));
//    ac->createB(5); // Compile error <= const.
//    bCollectionT bsc = ac->getBs(); // Compile error <= const.
    bCollectionConstT bsc = ac->getBsReadOnly();
//    bsc[1]->setCount(444); // Compile error <= const.
//    bsc.push_back(1); // Compile error <= const.
    for(auto b : bsc) {
        wcout << b->getCount() << " - " << b->getA().lock()->getName() << endl;
    }

    cout << "**********************" << endl;
    
    // If we have a const child, then the handle we get to its parent is also const.
    const shared_ptr<B const> b1(a->createB(21112));
    auto ac2 = b1->getA().lock();
    auto bsc2 = ac2->getBsReadOnly();

    for(auto b : bsc2) {
        wcout << b->getCount() << " - " << b->getA().lock()->getName() << endl;
    }

//    ac2->createB(5); // Compile error <= const.
//    bCollectionT bsc22 = ac2->getBs(); // Compile error <= const.
//    bsc2[1]->setCount(444); // Compile error <= const.
//    bsc2.push_back(1); // Compile error <= const.
    
    
    return 0;
}

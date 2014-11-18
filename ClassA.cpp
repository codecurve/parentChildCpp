//
//  ClassA.cpp
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#include "ClassA.h"

#include <algorithm>
#include <memory>

using namespace std;

template<typename parent, typename child>
Parent<parent, child>::Parent() {}


template<typename parent, typename child>
childCollectionConstT<parent, child> Parent<parent, child>::getChildrenReadOnly() const {
    childCollectionConstT<parent, child> childrenConst(children.begin(), children.end()); // Have to copy to get const version.
    return childrenConst;
}


template<typename parent, typename child>
childCollectionT<parent, child> Parent<parent, child>::getChildren() {
    return children;
}


template<typename parent, typename child>
const shared_ptr<const Child<parent, child>> Parent<parent, child>::createChild() {
    shared_ptr<Child<parent, child>> childp(Child<parent, child>::create(Parent<A, B>::shared_from_this()));
    children.push_back(childp);
    return children.back();
}

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
childCollectionConstT<parent, child> Parent<parent, child>::getChildrenReadOnly() const {
    childCollectionConstT<parent, child> childrenConst(children.begin(), children.end()); // Have to copy to get const version.
    return childrenConst;
}


template<typename parent, typename child>
childCollectionT<parent, child> Parent<parent, child>::getChildren() {
    return children;
}


template<typename parent, typename child>
shared_ptr<child> Parent<parent, child>::createChild() {
    shared_ptr<child> childp(Child<parent, child>::create(parent::shared_from_this()));
    children.push_back(childp);
    return children.back();
}


A::A(std::wstring name) : name_(name) {}

std::shared_ptr<B> A::createB(int value) {
  auto b = createChild();
  b->count_ = value;
  return b;
}

//
//  ClassB.cpp
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#include "ClassA.h"
#include "ClassB.h"

using namespace std;

B::B(const int count, weak_ptr<A> a, const this_is_private &):
  mCount(count),
  mObjectA(a)
{}


int B::getCount() const {
    return mCount;
}

void B::setCount(const int count) {
    mCount = count;
}

const weak_ptr<const A> B::getA() const {
    return mObjectA;
}

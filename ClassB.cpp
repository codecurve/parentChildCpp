//
//  ClassB.cpp
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#include "ClassB.h"
#include "ClassA.h"

using namespace std;

B::B(const int count, weak_ptr<A> a):
  mCount(count),
  mObjectA(a)
{}


const int B::getCount() const {
    return mCount;
}

void B::setCount(const int count) {
    mCount = count;
}

const weak_ptr<const A> B::getA() const {
    return mObjectA;
}

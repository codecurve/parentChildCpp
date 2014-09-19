//
//  ClassA.cpp
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#include "ClassA.h"
#include <memory>
#include <algorithm>

using namespace std;

A::A(wstring name) :
  mName(name)
{}


const wstring A::getName() const {
    return mName;
}


bCollectionConstT A::getBsReadOnly() const {
    bCollectionConstT bsc(bs.begin(), bs.end()); // Have to copy to get const version.
    return bsc;
}


bCollectionT A::getBs() {
    return bs;
}


const shared_ptr<const B> A::createB(int count) {
    shared_ptr<B> bsp(new B(count, shared_from_this())); // Have to use "shared_from_this"
    bs.push_back(bsp);
    return bs.back();
}

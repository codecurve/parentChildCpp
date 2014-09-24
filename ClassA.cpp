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

A::A(wstring name) :
mName(std::move(name))
{}


wstring A::getName() const {
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
    shared_ptr<B> bsp(B::create(count, shared_from_this()));
    bs.push_back(bsp);
    return bs.back();
}

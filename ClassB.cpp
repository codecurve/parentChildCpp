//
//  ClassB.cpp
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#include "ClassA.h"
#include "ClassB.h"

using namespace std;

template<typename parent, typename child>
Child<parent, child>::Child(weak_ptr<parent> p, const this_is_private &):
  mObjectParent(p)
{}


template<typename parent, typename child>
const weak_ptr<const parent> Child<parent, child>::getParent() const {
    return mObjectParent;
}

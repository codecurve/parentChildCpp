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



A::A(std::wstring name) : name_(name) {}

std::shared_ptr<B> A::createB(int value) {
  auto b = createChild();
  b->count_ = value;
  return b;
}

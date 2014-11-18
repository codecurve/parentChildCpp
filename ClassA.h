//
//  ClassA.h
//
//  Created by Randall Britten on 19/11/14.
//  Copyright (c) 2014 University of Auckland.
//

#ifndef ClassA_h
#define ClassA_h

#include "Parent.h"

class B;

class A: public Parent<A, B> {
  std::wstring name_;

public:
  A(std::wstring name);
  std::shared_ptr<B> createB(int value);
  std::wstring getName() const {return name_;}
};



#endif

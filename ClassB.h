//
//  ClassB.h
//
//  Created by Randall Britten on 19/11/14.
//  Copyright (c) 2014 University of Auckland.
//

#ifndef ClassB_h
#define ClassB_h

#include "Child.h"

class A;

class B : public Child<A,B> {
  int count_;

public:
  B(std::weak_ptr<A> p, const this_is_private &t);
  
  //! Getter for arbitrary data member.
  int getCount() const {return count_;}
  
  //! Setter for arbitrary data member.
  void setCount(const int count) {count_ = count;}
  
  
};


#endif

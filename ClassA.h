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

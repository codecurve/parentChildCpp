#include "ClassA.h"
#include "ClassB.h"

#include <algorithm>
#include <memory>

using namespace std;



A::A(std::wstring name) : name_(name) {}

std::shared_ptr<B> A::createB(int value) {
  auto b = createChild();
  b->setCount(value);
  return b;
}

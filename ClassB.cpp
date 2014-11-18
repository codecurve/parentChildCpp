#include <memory>

#include "ClassA.h"
#include "ClassB.h"


using namespace std;

B::B(weak_ptr<A> p, const this_is_private &t) : Child<A,B>(p, t){}

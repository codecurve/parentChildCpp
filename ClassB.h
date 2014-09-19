//
//  ClassB.h
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#ifndef ClassB_h
#define ClassB_h

#include <memory>

class A;

//! The class for child objects.
class B {
    friend class A;
    
    //! Constructor kept private so that only A (which is a friend) can construct. \see A::createB
    B(const int count, std::weak_ptr<A> a);
    
    //! Some arbitrary data member
    int mCount;
    
    //! Reference from child back to parent.
    //! This needs to be a weak_ptr to avoid circular ref counting issue.
    std::weak_ptr<A> mObjectA;

public:
    //! Getter for arbitrary data member.
    const int getCount() const;
    
    //! Setter for arbitrary data member.
    void setCount(const int);
    
    //! Get a weak reference to parent.
    const std::weak_ptr<const A> getA() const;
};


#endif

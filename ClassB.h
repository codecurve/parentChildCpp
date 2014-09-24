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

    /** make_shared workaround: Hidden class, effectively makes public constructor private.
     
        This is take from http://stackoverflow.com/a/8147326
     */
    struct this_is_private {};
    
    //! make_shared workaround: create only accessible to friend. \see A::createB
    static std::shared_ptr<B> create(const int count, std::weak_ptr<A> a) {
      return std::make_shared<B>(count, a, this_is_private{});
    }

    //! Some arbitrary data member
    int mCount;

    //! Reference from child back to parent.
    //! This needs to be a weak_ptr to avoid circular ref counting issue.
    std::weak_ptr<A> mObjectA;

public:
    /**! make_shared workaround: public constructor, but effectively private, only possible to make instance of this_is_private from privileged members.
     
        \see A::createB
     */
    explicit B(const int count, std::weak_ptr<A> a, const this_is_private &);

    //! Getter for arbitrary data member.
    int getCount() const;
    
    //! Setter for arbitrary data member.
    void setCount(const int);
    
    //! Get a weak reference to parent.
    const std::weak_ptr<const A> getA() const;
};


#endif

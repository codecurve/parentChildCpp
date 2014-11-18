//
//  ClassB.h
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#ifndef ClassB_h
#define ClassB_h

#include <memory>
template<typename parent, typename child>
class Parent;

//! The class for child objects.
template<typename parent, typename child>
class Child {
    friend class Parent<parent, child>;

    /** make_shared workaround: Hidden class, effectively makes public constructor private.
     
        This is take from http://stackoverflow.com/a/8147326
     */
    struct this_is_private {};
    
    //! make_shared workaround: create only accessible to friend. \see A::createB
    static std::shared_ptr<Child<parent, child>> create(std::weak_ptr<Parent<parent, child>> p) {
      return std::make_shared<Child<parent, child>>(p, this_is_private{});
    }

    //! Reference from child back to parent.
    //! This needs to be a weak_ptr to avoid circular ref counting issue.
    std::weak_ptr<Parent<parent, child>> mObjectParent;

public:
    /**! make_shared workaround: public constructor, but effectively private, only possible to make instance of this_is_private from privileged members.
     
        \see Parent::createChild
     */
    explicit Child<parent, child>(std::weak_ptr<Parent<parent, child>> p, const this_is_private &);

    //! Get a weak reference to parent.
    const std::weak_ptr<const Parent<parent, child>> getParent() const;
};

class A;

class B : public Child<A,B> {
public:
  int count_;

  //! Getter for arbitrary data member.
  int getCount() const {return count_;}
  
  //! Setter for arbitrary data member.
  void setCount(const int count) {count_ = count;}
  

};


#endif

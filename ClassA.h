//
//  ClassA.h
//
//  Created by Randall Britten on 16/09/14.
//  Copyright (c) 2014 University of Auckland.
//

#ifndef ClassA_h
#define ClassA_h

#include "ClassB.h"

#include <string>
#include <vector>


//! For collection of const children (i.e. each element immutable).
//! Overall collection is also not mutable
template<typename parent, typename child>
using childCollectionConstT = std::vector<std::shared_ptr<const Child<parent, child>>> const;

//! Overall collection is not mutable, but each element is mutable
template<typename parent, typename child>
using childCollectionT = std::vector<std::shared_ptr<Child<parent, child>>> const;

//! The class for a parent object
template<typename parent, typename child>
class Parent :
  public std::enable_shared_from_this<Parent<parent, child>> // Needed so that a reference to the A parent object creating the B child object can be stored by the B child object.
{
    //! Children
    std::vector<std::shared_ptr<Child<parent, child>>> children;
    
public:
    //! Construct passing in value for arbitrary data member.
    //! \param name will be stored as the arbitrary data member.
    Parent<parent, child>();
  
    /** Get read-only collection of children
     *
     * Each child element is immutable.
     * \return The collection of children, read-only.
     */
    childCollectionConstT<parent, child> getChildrenReadOnly() const;

    /** Get collection of mutable children
     *
     * Each child element is mutable.
     * Overall membership of collection is still fixed.
     * \return The collection of mutable children.
     */
    childCollectionT<parent, child> getChildren();
    
    /**
     * Create a child B object, of which this object is the parent
     * \return a pointer the newly created child object.
     */
    const std::shared_ptr<const Child<parent, child>> createChild();
};

class B;

class A: public Parent<A, B> {
public:
  std::wstring name_;
  A(std::wstring name) : name_(name) {}
  const std::shared_ptr<B> createB(int value) {
    auto bg = createChild();
    auto b = std::static_pointer_cast<B>(bg);
    b->count_ = value;
    return b;
  }
  std::wstring getName() {return name_;}
};


#endif

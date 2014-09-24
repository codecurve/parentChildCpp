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
using bCollectionConstT = std::vector<std::shared_ptr<const B>> const;

//! Overall collection is not mutable, but each element is mutable
using bCollectionT = std::vector<std::shared_ptr<B>> const;

//! The class for a parent object
class A :
  public std::enable_shared_from_this<A> // Needed so that a reference to the A parent object creating the B child object can be stored by the B child object.
{
    //! Children
    std::vector<std::shared_ptr<B>> bs;
    
    //! Arbitrary data member
    std::wstring mName;

public:
    //! Construct passing in value for arbitrary data member.
    //! \param name will be stored as the arbitrary data member.
    A(std::wstring name);
    
    //! Getter for arbitrary data member
    //! \return the value of the arbitrary data member
    std::wstring getName() const;
    
    /** Get read-only collection of children
     *
     * Each child element is immutable.
     * \return The collection of children, read-only.
     */
    bCollectionConstT getBsReadOnly() const;

    /** Get collection of mutable children
     *
     * Each child element is mutable.
     * Overall membership of collection is still fixed.
     * \return The collection of mutable children.
     */
    bCollectionT getBs();
    
    /**
     * Create a child B object, of which this object is the parent
     * \return a pointer the newly created child object.
     */
    const std::shared_ptr<const B> createB(int);
};

#endif

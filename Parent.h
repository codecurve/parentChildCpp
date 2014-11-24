#ifndef Parent_h
#define Parent_h

#include "Child.h"

#include <string>
#include <vector>


//! For collection of const children (i.e. each element immutable).
//! Overall collection is also not mutable
template<typename parent, typename child>
using childCollectionConstT = std::vector<std::shared_ptr<const child>> const;

//! Overall collection is not mutable, but each element is mutable
template<typename parent, typename child>
using childCollectionT = std::vector<std::shared_ptr<child>> const&;

//! The class for a parent object
template<typename parent, typename child>
class Parent :
  public std::enable_shared_from_this<parent> // Needed so that a reference to the parent object creating the child object can be stored by the child object.
{
    //! Children
    std::vector<std::shared_ptr<child>> children;
    
public:
    /** Get read-only collection of children
     *
     * Each child element is immutable.
     * \return The collection of children, read-only.
     */
    childCollectionConstT<parent, child> getChildrenReadOnly() const {
      childCollectionConstT<parent, child> childrenConst(children.begin(), children.end()); // Have to copy to get const version.
      return childrenConst;
    }

    /** Get collection of mutable children
     *
     * Each child element is mutable.
     * Overall membership of collection is still fixed.
     * \return The collection of mutable children.
     */
    childCollectionT<parent, child> getChildren() {
      return children;
    }
  
    /**
     * Create a child object, of which this object is the parent
     * \return a pointer the newly created child object.
     */
    std::shared_ptr<child> createChild() {
      std::shared_ptr<child> childp(Child<parent, child>::create(Parent<parent, child>::shared_from_this()));
      children.push_back(childp);
      return children.back();
    }

};


#endif

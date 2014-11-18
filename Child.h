#ifndef Child_h
#define Child_h

#include <memory>
template<typename parent, typename child>
class Parent;

//! The class for child objects.
template<typename parent, typename child>
class Child {
    friend class Parent<parent, child>;

    //! make_shared workaround: create only accessible to friend. \see A::createB
    static std::shared_ptr<child> create(std::weak_ptr<parent> p) {
      return std::make_shared<child>(p, this_is_private{});
    }

    //! Reference from child back to parent.
    //! This needs to be a weak_ptr to avoid circular ref counting issue.
    std::weak_ptr<parent> mObjectParent;

protected:
  /** make_shared workaround: Hidden class, effectively makes public constructor private.
   
   This is take from http://stackoverflow.com/a/8147326
   */
  struct this_is_private {};

  
public:
    /**! make_shared workaround: public constructor, but effectively private, only possible to make instance of this_is_private from privileged members.
     
        \see Parent::createChild
     */
    explicit Child<parent, child>(std::weak_ptr<parent> p, const this_is_private &): mObjectParent(p) {}

    //! Get a weak reference to parent.
    const std::weak_ptr<const parent> getParent() const {
      return mObjectParent;
    }
};


#endif

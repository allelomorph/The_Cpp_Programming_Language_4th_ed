#ifndef X14_5_VECTOR_HH
#define X14_5_VECTOR_HH


#include <algorithm>  // swap, copy
#include <memory>     // allocator, uninitialized_fill, uninitialized_copy,
                      //   addressof
#include <utility>    // move


namespace X14_5 {


// vector_base and vector taken from examples found in section 13.6.X, with
//   modifications noted in comments


template <typename T, typename A = std::allocator<T>>
struct vector_base {  // memory structure for vector
    A alloc;   // allocator
    T *elem;   // start of allocation
    T *space;  // end of element sequence, start of space allocated for possible expansion
    T *last;   // end of allocated space

    vector_base(const A &a, typename A::size_type n, typename A::size_type m = 0)
        : alloc {a},
          elem {alloc.allocate(n + m)},
          space {elem + n},
          last {elem + n + m} {}
    vector_base() { alloc.deallocate(elem, last - elem); }

    vector_base(const vector_base &) = delete;  // no copy operations
    vector_base &operator=(const vector_base &) = delete;

    vector_base(vector_base &&);  // move operations
    vector_base &operator=(vector_base &&);

    // Unsuccessful attempt at mimicing STL vector begin() and end()
    //
    // std::iterator<std::random_access_iterator_tag, T> begin() {
    //     return std::iterator<std::random_access_iterator_tag, T> {elem};
    // }
    // std::iterator<std::random_access_iterator_tag, T> end() {
    //     return std::iterator<std::random_access_iterator_tag, T> {space};
    // }
};


template <typename T, typename A>
vector_base<T, A>::vector_base(vector_base &&a)
    : alloc {a.alloc},
      elem {a.elem},
      space {a.space},
      last {a.last} {
          a.elem = a.space = a.last = nullptr;  // no longer owns any memory
      }


template <typename T, typename A>
vector_base<T, A> &vector_base<T, A>::operator=(vector_base &&a) {
    std::swap(alloc, a.alloc);
    std::swap(elem, a.elem);
    std::swap(space, a.space);
    std::swap(last, a.last);
    return *this;
}


template <typename T, typename A = std::allocator<T>>
class vector {
    vector_base<T, A> vb;
    void destroy_elements();

public:
    using size_type = typename A::size_type;

//    explicit vector(size_type n, const T &val = T{}, const A &a = A{});
    explicit vector(size_type n = 0, const T &val = T{}, const A &a = A{});

    vector(const vector &a);                 // copy constructor
    vector &operator=(const vector &a);      // copy assignment

    vector(vector &&a);                      // move constructor
    vector &operator=(vector &&a);           // move assignment

    ~vector() { destroy_elements(); }

    size_type size() const { return vb.space - vb.elem; }
    size_type capacity() const { return vb.last - vb.elem; }

    void reserve(size_type);                 // increase capacity

    void resize(size_type, const T & = {});  // change number of elements
    void clear() { resize(0); }              // empty vector
    void push_back(const T &);               // add element to end

    // Added operator[] for test main
    T &operator[](size_type n) {
        return *(this->vb.elem + n);
    }

    // Unsuccessful attempt at mimicing STL vector begin() and end():
    //
    // std::iterator<std::random_access_iterator_tag, T>
    // begin() { return vb.begin(); }
    //
    // std::iterator<std::random_access_iterator_tag, T>
    // end() { return vb.end(); }

    // ...
};


template <typename T, typename A>
void vector<T, A>::destroy_elements() {
    for (T *p {vb.elem}; p != vb.space; ++p)
        p->~T();
    vb.space = vb.elem;
}


template <typename T, typename A>
vector<T, A>::vector(size_type n, const T &val, const A &a)
    : vb{a, n} {
    std::uninitialized_fill(vb.elem, vb.elem + n, val);  // make n copies of val
}


template <typename T, typename A>
vector<T, A>::vector(const vector<T, A> &a)
    : vb {a.vb.alloc, a.size()} {
//    std::uninitialized_copy(a.begin(), a.end(), vb.elem);
    std::uninitialized_copy(a.vb.elem, a.vb.space, vb.elem);
}


template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector<T, A> &a) {
    if (capacity() < a.size()) {  // allocate new vector representation:
        vector<T, A> temp {a};    // copy allocator
        std::swap(*this, temp);   // swap representations
        return *this;             // implicitly destroy the old value
    }

    if (this == &a) return *this;                // optimize self-assignment

    size_type sz {size()};
    size_type asz {a.size()};
    vb.alloc = a.vb.alloc;                       // copy the allocator
    if (asz <= sz) {
//        std::copy(a.begin(), a.begin() + asz, vb.elem);
        std::copy(a.vb.elem, a.vb.elem + asz, vb.elem);
        for (T *p {vb.elem + asz}; p != vb.space; ++p)
            p->~T();                             // destroy surplus elements
    } else {
//        std::copy(a.begin(), a.begin() + sz,  vb.elem);
        std::copy(a.vb.elem, a.vb.elem + sz,  vb.elem);
//        std::uninitialized_copy(
//            a.begin() + sz, a.end(), vb.space);  // construct extra elements
        std::uninitialized_copy(
            a.vb.elem + sz, a.vb.space, vb.space);  // construct extra elements
    }
    vb.space = vb.elem + asz;
    return *this;
}


template <typename T, typename A>
vector<T, A>::vector(vector &&a)
    : vb{std::move(a.vb)} {}


template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(vector &&a) {
    clear();              // destroy elements
    std::swap(vb, a.vb);  // transfer ownership
    return *this;
}


// std::uninitialized_move implemented in C++17 <memory>, modified here to take
//   pointers as in Stroustrup's reserve(), rather than iterators
template <typename In, typename Out>
Out *uninitialized_move(In *b, In *e, Out *o) {
    for (; b != e; ++b, ++o) {
        new (static_cast<void *>(&*o)) Out {std::move(*b)};  // move construct
        b->~In();                                            // destroy
    }
    return o;
}


template <typename T, typename A>
void vector<T, A>::reserve(size_type newalloc) {
    if (newalloc <= capacity()) return;                         // never decrease allocation
    vector_base<T, A> b {vb.alloc, size(), newalloc - size()};  // get new space
    X14_5::uninitialized_move(vb.elem, vb.elem + size(), b.elem);      // move elements
    std::swap(vb, b);                                           // install new base
}  // implicitly release old space


// std::destroy_at introduced in C++17 <memory>
template<class T>
void destroy_at(T *p) { p->~T(); }


// std::destroy implemented in C++17 <memory>, modified here to take pointers
//   as in Stroustrup's resize(), rather than iterators
template<class T>
void destroy(T *first, T *last) {
    for (; first != last; ++first)
        destroy_at(std::addressof(*first));
}


template <typename T, typename A>
void vector<T, A>::resize(size_type newsize, const T &val) {
    reserve(newsize);
    if (size() < newsize) {
        std::uninitialized_fill(
            vb.elem + size(), vb.elem + newsize, val);  // construct new elements
    } else {
        destroy(vb.elem + newsize, vb.elem + size());   // destroy surplus elements
    }
}


template <typename T, typename A>
void vector<T, A>::push_back(const T &val) {
    if (capacity() == size())                   // no more free space; relocate
        reserve(size() ? 2 * size() : 8);       // grow or start with 8
    vb.alloc.construct(&vb.elem[size()], val);  // add val at end
    ++vb.space;                                 // increment size
}


}  // namespace X14_5


#endif  // X14_5_VECTOR_HH

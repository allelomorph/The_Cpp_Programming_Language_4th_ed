# X.35 Memory and Resources

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2.5) Complete and test a pool allocator for objects of type `T`:
```C++
template<typename T>
class Pool_alloc {
    T* allocate(size_t n); // allocate space for n objects of type T; do not initialize
    void deallocate(T* p, size_t n); // deallocate space for n ojects of type T starting at p
// ...
};
```
Make sure that `Pool_alloc` provides all of the facilities of the standard library allocator (§34.4). Compare the performance of `std::allocator` and `Pool_alloc` to see if there is any reason to use a `Pool_alloc` on your system.\
\
File(s): [`_`](./)

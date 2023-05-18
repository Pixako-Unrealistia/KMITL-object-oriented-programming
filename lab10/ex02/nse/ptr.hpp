#ifndef NSE_PTR_HPP
#define NSE_PTR_HPP

#include <memory>

namespace nse {

template <class T>
class Ptr {
public:
    // new member to copy the object conditionally when needed
    void make_unique()
    {
        if (p.use_count() > 1) {
            p.reset( clone(p.get()) );
        }
    }

    Ptr() noexcept = default;
    explicit Ptr(T* t): p(t) {}

    Ptr(const Ptr& h) noexcept = default;
    Ptr& operator=(const Ptr&) noexcept = default;
    ~Ptr() = default;
    Ptr(Ptr&& h) noexcept = default;
    Ptr& operator=(Ptr&&) noexcept = default;

    operator bool() const noexcept { return p.operator bool(); }
    T& operator*() const noexcept { return *p; }
    T* operator->() const noexcept { return p.operator->(); }
private:
    std::shared_ptr<T> p;
};

template <class T>
T* clone(const T* tp)
{
    return tp->clone();
}

} // namespace nse

#endif /* NSE_PTR_HPP */

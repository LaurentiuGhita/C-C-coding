#include <iostream>


template <typename R>
class FunctorImpl<R, NullType>
{
public:
    virtual R operator()() = 0;
    virtual FunctorImpl* Clone() const = 0;
    virtual ~FunctorImpl() {}
};

template <typename R, typename P1>
class Functor
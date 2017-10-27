#ifndef SCHEDULED_H
#define SCHEDULED_H 

#include <memory>
#include "Macros.h"
#include "Node.h"

NS_JALB_BEGIN

#define CALLBACK_0(__FUNC__, __TARGET__) std::bind(&__FUNC__, __TARGET__)
#define CALLBACK_1(__FUNC__, __TARGET__) std::bind(&__FUNC__, __TARGET__, std::placeholders::_1)
#define CALLBACK_2(__FUNC__, __TARGET__) std::bind(&__FUNC__, __TARGET__, std::placeholders::_1, std::placeholders::_2)

using jFunc0 = std::function<void()>;

template<typename T>
using jFunc1 = std::function<void(T)>;

template<typename T1, typename T2>
using jFunc2 = std::function<void(T1, T2)>;

template<typename T>
struct Listener
{
    T _callback;
    std::shared_ptr<Node> _target;
    string _name;

    Listener(const T& callback, const std::shared_ptr<Node>& target, const string& name) :
        _callback(callback),
        _target(target),
        _name(name)
    {

    }
};

NS_JALB_END

#endif /* SCHEDULED_H */

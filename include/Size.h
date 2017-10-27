#ifndef SIZE_H
#define SIZE_H 

#include <cstddef>
#include <functional>
#include "Macros.h"

using namespace std;

NS_JALB_BEGIN

class Pos;

class Size
{
    public:
    	Size(const Size& s);
        Size(const int& w, const int& h);
        Size(const int& s);
        Size();

        Size(const Pos& p);

        ~Size();

        bool operator==(const Size& p) const;
        bool operator!=(const Size& p) const;

        template<class T> Size& operator+=(const T& t);
        template<class T> Size& operator-=(const T& t);
        template<class T> Size& operator*=(const T& t);
        template<class T> Size& operator/=(const T& t);
        template<class T> Size  operator+(const T& rt);
        template<class T> Size  operator-(const T& rt);
        template<class T> Size  operator*(const T& rt);
        template<class T> Size  operator/(const T& rt);

        Size& operator+=(const Size& p);
        Size& operator-=(const Size& p);
        Size& operator*=(const Size& p);
        Size& operator/=(const Size& p);

        int width;
        int height;

    protected:

    private:

};

template<class T> Size& Size::operator+=(const T& t)
{
    this->width += t;
    this->height += t;
    return *this;
}

template<class T> Size& Size::operator-=(const T& t)
{
    this->width -= t;
    this->height -= t;
    return *this;
}

template<class T> Size& Size::operator*=(const T& t)
{
    this->width *= t;
    this->height *= t;
    return *this;
}

template<class T> Size& Size::operator/=(const T& t)
{
    this->width /= t;
    this->height /= t;
    return *this;
}

template<class T> Size Size::operator+(const T& t)
{
    *this += t;
    return *this;
}

template<class T> Size Size::operator-(const T& t)
{
    *this -= t;
    return *this;
}

template<class T> Size Size::operator*(const T& t)
{
    *this *= t;
    return *this;
}

template<class T> Size Size::operator/(const T& t)
{
    *this /= t;
    return *this;
}

NS_JALB_END

namespace std
{
    template<>
    struct hash<jalb::Size>
    {
        std::size_t operator()(const jalb::Size& size) const
        {
            using std::size_t;
            using std::hash;
            
            return ((hash<int>()(size.width)) ^ (hash<int>()(size.height)));
        }
    };
}

#endif /* SIZE_H */

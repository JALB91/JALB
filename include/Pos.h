#ifndef POS_H
#define POS_H 

#include <cstddef>
#include <functional>
#include "Macros.h"

using namespace std;

NS_JALB_BEGIN

class Size;

class Pos
{
    public:
        Pos(const Pos& p);
        Pos(const int& x, const int& y);
        Pos();

        Pos(const Size& s);

        ~Pos();

        bool operator==(const Pos& p) const;
        bool operator!=(const Pos& p) const;

        template<class T> Pos& operator+=(const T& t);
        template<class T> Pos& operator-=(const T& t);
        template<class T> Pos& operator*=(const T& t);
        template<class T> Pos& operator/=(const T& t);
        template<class T> Pos  operator+(const T& rt);
        template<class T> Pos  operator-(const T& rt);
        template<class T> Pos  operator*(const T& rt);
        template<class T> Pos  operator/(const T& rt);

        Pos& operator+=(const Pos& p);
        Pos& operator-=(const Pos& p);
        Pos& operator*=(const Pos& p);
        Pos& operator/=(const Pos& p);

        int x;
        int y;

    protected:

    private:

};


template<class T> Pos& Pos::operator+=(const T& t)
{
    this->x += t;
    this->y += t;
    return *this;
}

template<class T> Pos& Pos::operator-=(const T& t)
{
    this->x -= t;
    this->y -= t;
    return *this;
}

template<class T> Pos& Pos::operator*=(const T& t)
{
    this->x *= t;
    this->y *= t;
    return *this;
}

template<class T> Pos& Pos::operator/=(const T& t)
{
    this->x /= t;
    this->y /= t;
    return *this;
}

template<class T> Pos Pos::operator+(const T& t)
{
    *this += t;
    return *this;
}

template<class T> Pos Pos::operator-(const T& t)
{
    *this -= t;
    return *this;
}

template<class T> Pos Pos::operator*(const T& t)
{
    *this *= t;
    return *this;
}

template<class T> Pos Pos::operator/(const T& t)
{
    *this /= t;
    return *this;
}

NS_JALB_END

namespace std
{
    template<>
    struct hash<jalb::Pos>
    {
        std::size_t operator()(const jalb::Pos& pos) const
        {
            using std::size_t;
            using std::hash;
            
            return ((hash<int>()(pos.x)) ^ (hash<int>()(pos.y)));
        }
    };
}


#endif /* POS_H */

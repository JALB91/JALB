#include "Pos.h"
#include "Size.h"

NS_JALB_BEGIN

Pos::Pos(const int& x, const int& y) : x(x), y(y)
{
    
}

Pos::Pos(const Pos &p) : Pos(p.x, p.y)
{

}

Pos::Pos() : Pos(0, 0)
{
    
}


Pos::Pos(const Size& s) : Pos(s.width, s.height)
{

}


Pos::~Pos()
{

}


bool Pos::operator==(const Pos& p) const
{
    return (this->x == p.x && this->y == p.y);
}

bool Pos::operator!=(const Pos& p) const
{
    return !(*this == p);
}

Pos& Pos::operator+=(const Pos& p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}

Pos& Pos::operator-=(const Pos& p)
{
    this->x -= p.x;
    this->y -= p.y;
    return *this;
}

Pos& Pos::operator*=(const Pos& p)
{
    this->x *= p.x;
    this->y *= p.y;
    return *this;
}

Pos& Pos::operator/=(const Pos& p)
{
    this->x /= p.x;
    this->y /= p.y;
    return *this;
}

NS_JALB_END

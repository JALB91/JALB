#include "Size.h"
#include "Pos.h"

NS_JALB_BEGIN

Size::Size(const int& w, const int& h) : width(w), height(h)
{

}

Size::Size(const Size& s) : Size(s.width, s.height)
{
	
}

Size::Size(const int& s) : Size(s, s)
{

}

Size::Size() : Size(0)
{

}


Size::Size(const Pos& p) : Size(p.x, p.y)
{

}


Size::~Size()
{

}


bool Size::operator==(const Size& p) const
{
    return (this->width == p.width && this->height == p.height);
}

bool Size::operator!=(const Size& p) const
{
    return !(*this == p);
}

Size& Size::operator+=(const Size& p)
{
    this->width += p.width;
    this->height += p.height;
    return *this;
}

Size& Size::operator-=(const Size& p)
{
    this->width -= p.width;
    this->height -= p.height;
    return *this;
}

Size& Size::operator*=(const Size& p)
{
    this->width *= p.width;
    this->height *= p.height;
    return *this;
}

Size& Size::operator/=(const Size& p)
{
    this->width /= p.width;
    this->height /= p.height;
    return *this;
}

NS_JALB_END

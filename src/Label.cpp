#include "Label.h"


NS_JALB_BEGIN


std::shared_ptr<Label> Label::createWithText(const std::string& text)
{
    std::shared_ptr<Label> label (new Label(text));

    if (label && label->init())
    {
        return label;
    }

    return nullptr;
}

std::shared_ptr<Label> Label::create()
{
    return createWithText("");
}


Label::Label(const string& text):
_text(text)
{

}

Label::~Label()
{

}


bool Label::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}


void Label::draw()
{
	Node::draw();
}

NS_JALB_END

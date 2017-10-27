#include "Label.h"


NS_JALB_BEGIN


std::shared_ptr<Label> Label::createWithText(const std::string& text)
{
    std::shared_ptr<Label> label (new Label(text));

    if (label && label->init(label))
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


bool Label::init(const std::shared_ptr<Node>& me)
{
    if (!Node::init(me))
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

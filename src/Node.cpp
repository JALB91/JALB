#include "Node.h"
#include "Director.h"
#include <algorithm>
#include <assert.h>

NS_JALB_BEGIN


std::shared_ptr<Node> Node::create()
{
    std::shared_ptr<Node> node (new Node);

    if (node && node->init())
    {
        return node;
    }
    
    return nullptr;
}


Node::Node()
{
    _name = "";

    _z_ord = 0;
    _tag = 0;

    _position = Pos(0, 0);
    _contentSize = Size(0, 0);

    _parent = nullptr;
}

Node::~Node()
{

}


bool Node::init()
{
    return true;
}

void Node::draw()
{
    sort(_children.begin(), _children.end(), [](const std::shared_ptr<Node> a, const std::shared_ptr<Node> b)
        {
            return a->_z_ord < b->_z_ord;
        }); 

   for (auto node: _children)
   {
       node->draw();
   }
}

void Node::preUpdate()
{

}

void Node::update(float delta)
{

}

void Node::postUpdate()
{

}


void Node::removeFromParent()
{
    assert(_parent == nullptr);
    _parent->removeChild(shared_from_this());
}


void Node::addChild(const std::shared_ptr<Node>& child)
{
    addChild(child, 0);
}

void Node::addChild(const std::shared_ptr<Node>& child, const int& z_ord)
{
    assert(child->_parent == nullptr);

    _children.push_back(child);
    child->_parent = shared_from_this();
    child->setZOrd(z_ord);
}

void Node::removeChild(const std::shared_ptr<Node>& child)
{
    assert(child->_parent != nullptr);

    for (auto it = _children.begin(); it != _children.end(); it++)
    {
        auto currChild = *it;

        if (child == currChild)
        {
            _children.erase(it);
            _children.shrink_to_fit();

            child->_parent = nullptr;

            return;
        }
    }
}

void Node::removeChildByName(const string& name)
{
    for (auto it = _children.begin(); it != _children.end(); it++)
    {
        auto child = *it;

        if (child->_name == name)
        {
            _children.erase(it);
            _children.shrink_to_fit();

            child->_parent = nullptr;

            return;
        }
    }
}

void Node::removeChildByTag(const int& tag)
{
    for (auto it = _children.begin(); it != _children.end(); it++)
    {
        auto child = *it;

        if (child->_tag == tag)
        {
            _children.erase(it);
            _children.shrink_to_fit();

            child->_parent = nullptr;

            return;
        }
    }
}


void Node::schedulePreUpdate()
{
    Director::getInstance()->schedulePreUpdate(CALLBACK_0(Node::preUpdate, this), shared_from_this());
}

void Node::scheduleUpdate()
{
    Director::getInstance()->scheduleUpdate(CALLBACK_1(Node::update, this), shared_from_this(), "update");
}

void Node::schedulePostUpdate()
{
    Director::getInstance()->schedulePostUpdate(CALLBACK_0(Node::postUpdate, this), shared_from_this());
}

NS_JALB_END

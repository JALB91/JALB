#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <memory>
#include "Macros.h"
#include "Pos.h"
#include "Size.h"

using namespace std;

NS_JALB_BEGIN

class Node: public std::enable_shared_from_this<Node>
{
    public:
        static std::shared_ptr<Node> create();
        virtual ~Node();

        virtual void draw();

        virtual void preUpdate();
        virtual void update(float delta);
        virtual void postUpdate();

        inline const string getName() const { return _name; };
        inline void setName(const string& name) { this->_name = name; };

        inline const int getZOrd() const { return _z_ord; };
        inline void setZOrd(const int& z_ord) { this->_z_ord = z_ord; };

        inline const int getTag() const { return _tag; };
        inline void setTag(const int& tag) { this->_tag = tag; };

	    inline const Pos getPosition() const { return _position; };
	    inline const int getPositionX() const { return _position.x; };
	    inline const int getPositionY() const { return _position.y; };

	    virtual inline void setPosition(const Pos& p) { this->_position = p; };
        inline void setPosition(const int& x, const int& y) { setPosition(Pos(x, y)); };
	    inline void setPositionX(const int& x) { setPosition(x, _position.y); };
	    inline void setPositionY(const int& y) { setPosition(_position.x, y); };

        inline const Size getContentSize() const { return _contentSize; };

        virtual inline void setContentSize(const Size& s) { this->_contentSize = s; };
        inline void setContentSize(const int& w, const int& h) { setContentSize(Size(w, h)); };
        inline void setContentSize(const int& s) { setContentSize(Size(s)); };

        inline std::shared_ptr<Node> getParent() const { return _parent; };
        void removeFromParent();

        inline vector<std::shared_ptr<Node>> getChildren() const { return _children; };
        void addChild(const std::shared_ptr<Node>& child);
        void addChild(const std::shared_ptr<Node>& child, const int& z_ord);
        void removeChild(const std::shared_ptr<Node>& child);
        void removeChildByName(const string& name);
        void removeChildByTag(const int& tag);

    protected:
        Node();
        virtual bool init();

        void schedulePreUpdate();
        void scheduleUpdate();
        void schedulePostUpdate();

        string _name;

        int _z_ord, _tag;

	    Pos _position;
        Size _contentSize;

        std::shared_ptr<Node> _parent;
        vector<std::shared_ptr<Node>> _children;

    private:

};

NS_JALB_END

#endif

#ifndef LABEL_H
#define LABEL_H

#include "string.h"
#include "Node.h"

using namespace std;

NS_JALB_BEGIN

class Label : public Node
{
	public:
        static std::shared_ptr<Label> createWithText(const std::string& text);
        static std::shared_ptr<Label> create();
		virtual ~Label();

		virtual void draw() override;

		virtual inline void setText(const string& text) { this->_text = text; };
		virtual inline const string getText() const { return _text; };

	protected:
        Label(const std::string& text);
        virtual bool init(const std::shared_ptr<Node>& me) override;

	private:
		string _text = "";

};

NS_JALB_END

#endif

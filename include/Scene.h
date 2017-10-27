#ifndef SCENE_H
#define SCENE_H

#include <set>
#include <memory>
#include "Macros.h"
#include "Node.h"

NS_JALB_BEGIN

class Scene : public Node
{
    public:
        static std::shared_ptr<Scene> create();
		virtual ~Scene();

		void postUpdate() override;

	protected:
        Scene();
        virtual bool init() override;

	private:

};

NS_JALB_END

#endif

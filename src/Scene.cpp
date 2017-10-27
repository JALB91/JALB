#include "Scene.h"
#include "Director.h"


NS_JALB_BEGIN


std::shared_ptr<Scene> Scene::create()
{
    std::shared_ptr<Scene> scene (new Scene);

    if (scene && scene->init(scene))
    {
        return scene;
    }

    return nullptr;
}


Scene::Scene()
{

}

Scene::~Scene()
{

}


bool Scene::init(const std::shared_ptr<Node>& me)
{
    if (!Node::init(me))
    {
        return false;
    }

    schedulePostUpdate(me);

    return true;
}


void Scene::postUpdate()
{
	this->draw();
}


NS_JALB_END

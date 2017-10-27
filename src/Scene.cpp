#include "Scene.h"
#include "Director.h"


NS_JALB_BEGIN


std::shared_ptr<Scene> Scene::create()
{
    std::shared_ptr<Scene> scene (new Scene);

    if (scene && scene->init())
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


bool Scene::init()
{
    if (!Node::init())
    {
        return false;
    }

    schedulePostUpdate();

    return true;
}


void Scene::postUpdate()
{
	this->draw();
}


NS_JALB_END

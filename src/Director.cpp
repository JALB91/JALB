#include "Director.h"
#include <iostream>

NS_JALB_BEGIN

Director* Director::_instance = nullptr;

Director* Director::getInstance()
{
    if (!_instance)
    {
        _instance = new Director();
    }

    return _instance;
}

Director::Director()
{
    _time = 0.0;
    setFps(TICKRATE);
}

Director::~Director()
{

}


void Director::runWithScene(std::shared_ptr<Scene> scene)
{
    runningScene = scene;
    mainLoop();
}


void Director::setFps(float fps)
{
    _fps = fps;
}


void Director::schedulePreUpdate(const jFunc0& callback, std::shared_ptr<Node> target, const string& name /* "" */)
{
    schedule(_preUpdates, callback, target, name);
}


void Director::scheduleUpdate(const jFunc1<float>& callback, std::shared_ptr<Node> target, const string& name /* "" */)
{
    schedule(_updates, callback, target, name);
}


void Director::schedulePostUpdate(const jFunc0& callback, std::shared_ptr<Node> target, const string& name /* "" */)
{
    schedule(_postUpdates, callback, target, name);
}


void Director::addKeyListener(const jFunc1<int>& callback, std::shared_ptr<Node> target, const string& name /* "" */)
{
    schedule(_keyListeners, callback, target, name);
}


template<typename T>
void Director::schedule(std::vector<Listener<T>>& vec, const T& callback, std::shared_ptr<Node> target, const string& name)
{
    if (!callback || !target)
    {
        return;
    }

    for (auto listener: vec)
    {
        if (listener._target == target)
        {
            return;
        }
    }

    Listener<T> listener(callback, target, name);
    vec.push_back(listener);
}

template<typename T>
void Director::unschedule(std::vector<Listener<T>>& vec, std::shared_ptr<Node> target)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        Listener<T> listener = *it;

        if (listener._target == target)
        {
            vec.erase(it);
            vec.shrink_to_fit();
            return;
        }
    }
}

template<typename T>
void Director::unschedule(std::vector<Listener<T>>& vec, const string& name)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        Listener<T> listener = *it;

        if (listener._name == name)
        {
            vec.erase(it);
            vec.shrink_to_fit();
            return;
        }
    }
}


void Director::mainLoop()
{
    while (int ch = getchar())
    {
        if (ch == 'q')
        {
            break;
        }

        preUpdate();

        for (auto listener: _keyListeners)
        {
            listener._callback(ch);
        }

        std::cout << ch << std::endl;
        
        update();
        postUpdate();
    }
}

void Director::preUpdate()
{
    for (auto preUpdate: _preUpdates)
    {
        preUpdate._callback();
    }
}

void Director::update()
{
    _time += _fps * 0.001f;

    for (auto update: _updates)
    {
        update._callback(_fps * 0.001f);
    }
}

void Director::postUpdate()
{
    for (auto postUpdate: _postUpdates)
    {
        postUpdate._callback();
    }
}


NS_JALB_END

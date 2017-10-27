#ifndef DIRECTOR_H
#define DIRECTOR_H 

#include <set>
#include <memory>
#include "Macros.h"
#include "Node.h"
#include "Scene.h"
#include "Scheduled.h"

NS_JALB_BEGIN

class Director
{
    public:
        static Director* getInstance();
        virtual ~Director();

        void runWithScene(std::shared_ptr<Scene> scene);

        void setFps(float fps);

        inline float getFps() const { return _fps; };
        inline double getTime() const { return _time; };

        void schedulePreUpdate(const jFunc0& callback, std::shared_ptr<Node> target, const string& name = "");
        inline void unschedulePreUpdate(std::shared_ptr<Node> target) { unschedule(_preUpdates, target); };
        inline void unschedulePreUpdate(const string& name) { unschedule(_preUpdates, name); };

        void scheduleUpdate(const jFunc1<float>& callback, std::shared_ptr<Node> target, const string& name = "");
        inline void unscheduleUpdate(std::shared_ptr<Node> target) { unschedule(_updates, target); };
        inline void unscheduleUpdate(const string& name) { unschedule(_updates, name); };

        void schedulePostUpdate(const jFunc0& callback, std::shared_ptr<Node> target, const string& name = "");
        inline void unschedulePostUpdate(std::shared_ptr<Node> target) { unschedule(_postUpdates, target); };
        inline void unschedulePostUpdate(const string& name) { unschedule(_postUpdates, name); };

        void addKeyListener(const jFunc1<int>& callback, std::shared_ptr<Node> target, const string& name = "");
        inline void removeKeyListener(std::shared_ptr<Node> target) { unschedule(_keyListeners, target); };
        inline void removeKeyListener(const string& name) { unschedule(_keyListeners, name); };

    protected:
        Director();

        template<typename T>
        static void schedule(std::vector<Listener<T>>& vec, const T& callback, std::shared_ptr<Node> target, const string& name);

        template<typename T>
        static void unschedule(std::vector<Listener<T>>& vec, std::shared_ptr<Node> target);

        template<typename T>
        static void unschedule(std::vector<Listener<T>>& vec, const string& name);

        void mainLoop();

        void preUpdate();
        void update();
        void postUpdate();

    private:
        static Director* _instance;

        std::shared_ptr<Scene> runningScene;

        float _fps;
        double _time;

        std::vector<Listener<jFunc0>> _preUpdates;
        std::vector<Listener<jFunc1<float>>> _updates;
        std::vector<Listener<jFunc0>> _postUpdates;
        std::vector<Listener<jFunc1<int>>> _keyListeners;

};

NS_JALB_END

#endif /* DIRECTOR_H */

#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

#include "scene.h"

class View : public QGraphicsView
{
public:
    View(Scene* scene);

private:
    Scene* m_scene {nullptr};
};

#endif // VIEW_H

#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
public:
    explicit Scene(QObject *parent = nullptr);
};

#endif // SCENE_H

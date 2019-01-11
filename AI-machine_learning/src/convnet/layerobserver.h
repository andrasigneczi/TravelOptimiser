#ifndef __LAYEROBSERVER_H__
#define __LAYEROBSERVER_H__

#include "forward_backward_if.h"

class LayerSubject;

class LayerObserver {
public:
    LayerObserver(LayerSubject* subject);
    virtual void notify(int state) = 0;
private:
};

class LayerSubject
{
public:
    void addObserver(LayerObserver*);
    void checkPoint(int state, void* locVar = 0);
    void* getLocVar() {return mLocVar;}

private:
    void notifyAll();

    std::vector<LayerObserver*> mObservers;
    int mState;
    void* mLocVar;
};

#endif // __LAYEROBSERVER_H__

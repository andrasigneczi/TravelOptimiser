#include "layerobserver.h"

LayerObserver::LayerObserver(LayerSubject* subject) {
    subject->addObserver(this);
}





void LayerSubject::addObserver(LayerObserver* observer) {
    mObservers.push_back(observer);
}

void LayerSubject::checkPoint(int state, void* locVar) {
    mState = state;
    mLocVar = locVar;
    notifyAll();
}

void LayerSubject::notifyAll() {
    for(LayerObserver* observer : mObservers) {
        observer->notify(mState);
    }
}

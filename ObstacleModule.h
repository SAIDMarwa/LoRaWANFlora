#ifndef OBSTACLEMODULE_H_
#define OBSTACLEMODULE_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace LoRaWANNetwork {

class ObstacleModule : public cSimpleModule
{
public:
    virtual ~ObstacleModule() {}

protected:
    virtual void initialize() override;
};

}

#endif /* OBSTACLEMODULE_H_ */

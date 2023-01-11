#pragma once
#include "Entity.h"
class NeutralEntity :
    public Entity
{
private:

public:
    void Update(World& world) override final;
    void Movement(World& world) override final;
};


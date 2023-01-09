#pragma once
#include "Entity.h"
class NeutralEntity :
    public Entity
{
private:

public:
    void Update() override final;
    void Movement() override final;
};


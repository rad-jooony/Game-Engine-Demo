#pragma once
#include "Entity.h"
class TempEntity :
    public Entity
{
private:

public:
    void Update() override final;
    void Movement() override final;
};


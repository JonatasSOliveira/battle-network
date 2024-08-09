#pragma once
#include <list>
#include "../../../nodes/tile-based-attack/tile-based-attack.h"
#include "../../../../utils/global-adapters/global-adapters.h"
#include "../../../nodes/sprite/sprite.h"
#include "../../flame/flame.h"

namespace Game
{

    class FlamethrowerAttack : public TileBasedAttack
    {
    private:
        float increaseFlameTime = 0.75;
        float increaseFlameTimer = 0;
        std::list<Flame> flames;

        void handleFlameIncrease();
        void increaseFlame();

    protected:
        void onCollision(Element *other) override;

    public:
        FlamethrowerAttack(Vector initialTilePoition);

        void update() override;
        void render() override;
    };
}
#pragma once
#include "../../../nodes/tile-based-attack/tile-based-attack.h"

namespace Game
{
    class Stab : public TileBasedAttack
    {
    private:
        bool isColliding = false;

    protected:
        void onCollision(Element *other) override
        {
            this->isColliding = true;
        }

    public:
        Stab(const Vector swordTilePosition, const int damage);

        void makeAsDeleted()
        {
            this->deleted = true;
        }

        void update() override
        {
            if (this->isColliding)
            {
                this->damage = 0;
            }
        }

        void render() override {}
    };
}
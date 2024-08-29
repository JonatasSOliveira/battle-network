#pragma once
#include "../../enemy/enemy.h"
#include "../../attacks/flamethrower-attack/flamethrower-attack.h"
#include "../../../global/global-services/global-services.h"
#include "../../attacks/bomb-attack/bomb-attack.h"

namespace Game
{
    enum class Attacks
    {
        FLAMETHROWER,
        BOMB
    };

    class FiremanEnemy : public Enemy
    {
    private:
        class IdleAnimationHandler : public Observer<int>
        {
        private:
            FiremanEnemy &firemanEnemy;

        public:
            IdleAnimationHandler(FiremanEnemy &firemanEnemy) : firemanEnemy(firemanEnemy) {}

            void next(const int &value) override {
                this->firemanEnemy.queueAnimationChange(&firemanEnemy.idleSprite);
            }
        };

        const float spriteWidth = 264;
        const float spriteHeight = 248;
        const Vector spritePosition = Vector(
            -((this->spriteWidth - this->width) / 2) - 62,
            -((this->spriteHeight - this->height) / 2) - 92);
        AnimatedSprite idleSprite = AnimatedSprite({0.2f,
                                                    "assets/sprites/enemies/fireman/idle",
                                                    7,
                                                    this->spriteWidth,
                                                    this->spriteHeight,
                                                    false,
                                                    this->spritePosition});
        AnimatedSprite fireAttackAnimation = AnimatedSprite({0.2f,
                                                             "assets/sprites/enemies/fireman/fire-attack",
                                                             12,
                                                             this->spriteWidth,
                                                             this->spriteHeight,
                                                             false,
                                                             this->spritePosition});
        AnimatedSprite throwingAttackAnimation = AnimatedSprite({0.2f,
                                                                 "assets/sprites/enemies/fireman/throwing-attack",
                                                                 12,
                                                                 this->spriteWidth,
                                                                 this->spriteHeight,
                                                                 false,
                                                                 this->spritePosition});
        float attackDelayTime = 0;
        float attackDelayTimer = 0;
        void flamethrowerAttack();
        void bombAttack();

    protected:
        void attack() override;
        void onCollision(Element *other) override;

    public:
        FiremanEnemy();

        void update() override;
    };
}
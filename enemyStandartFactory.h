#ifndef ABSTRACTFACTORY_ENEMYSTANDARTFACTORY_H
#define ABSTRACTFACTORY_ENEMYSTANDARTFACTORY_H

#include <memory>
#include "enemy.h"

//class Soldier;
//class Monster;
//class SuperMonster;

class AbstractEnemyFactory
{
public:
    virtual std::unique_ptr<Soldier> makeSoldier() = 0;
    virtual std::unique_ptr<Monster> makeMonster() = 0;
    virtual std::unique_ptr<SuperMonster> makeSuperMonster() = 0;

    virtual ~AbstractEnemyFactory() = default;
};

class EasyLevelEnemyFactory : public AbstractEnemyFactory
{
public:
    std::unique_ptr<Soldier> makeSoldier() override
    {
        return std::make_unique<SillySoldier>();
    }

    std::unique_ptr<Monster> makeMonster() override
    {
        return std::make_unique<SillyMonster>();
    }

    std::unique_ptr<SuperMonster> makeSuperMonster() override
    {
        return std::make_unique<SillySuperMonster>();
    }
};

class DieHardLevelEnemyFactory : public AbstractEnemyFactory
{
public:
    std::unique_ptr<Soldier> makeSoldier() override
    {
        return std::make_unique<BadSoldier>();
    }

    std::unique_ptr<Monster> makeMonster() override
    {
        return std::make_unique<BadMonster>();
    }

    std::unique_ptr<SuperMonster> makeSuperMonster() override
    {
        return std::make_unique<BadSuperMonster>();
    }
};

#endif //ABSTRACTFACTORY_ENEMYSTANDARTFACTORY_H

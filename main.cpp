#include <iostream>
#include <memory>
#include "enemy.h"
#include "enemyHierarchyFactory.h"

int main()
{
    using AbstractEnemyFactory =
    AbstractFactory<AbstractFactoryUnit,
            Soldier,
            Monster,
            SuperMonster>;

    using EasyFactory =
    ConcreteFactory<AbstractEnemyFactory, ConcreteFactoryUnit,
            SillySoldier,
            SillyMonster,
            SillySuperMonster>;

    std::unique_ptr<AbstractEnemyFactory> pFactory{new EasyFactory};
    std::unique_ptr<Enemy> pEnemy = pFactory->Create<Monster>();
    pEnemy->info();

    pEnemy = pFactory->Create<Soldier>();
    pEnemy->info();

    using HardFactory =
    ConcreteFactory<AbstractEnemyFactory, ConcreteFactoryUnit,
            BadSoldier,
            BadMonster,
            BadSuperMonster>;

    pFactory.reset(new HardFactory);
    pEnemy = pFactory->Create<Monster>();
    pEnemy->info();

    pEnemy = pFactory->Create<Soldier>();
    pEnemy->info();
}
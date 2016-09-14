#ifndef ABSTRACTFACTORY_ENEMY_H
#define ABSTRACTFACTORY_ENEMY_H

#include <cstdio>

struct Enemy
{
    virtual void info() const = 0;
    virtual ~Enemy() = default;
};

struct Soldier : Enemy {};
struct Monster : Enemy {};
struct SuperMonster : Enemy {};

struct SillySoldier : Soldier
{
    void info() const override {puts(__PRETTY_FUNCTION__);}
};

struct BadSoldier : Soldier
{
    void info() const override {puts(__PRETTY_FUNCTION__);}
};

struct SillyMonster : Monster
{
    void info() const override {puts(__PRETTY_FUNCTION__);}
};

struct BadMonster : Monster
{
    void info() const override {puts(__PRETTY_FUNCTION__);}
};

struct SillySuperMonster : SuperMonster
{
    void info() const override {puts(__PRETTY_FUNCTION__);}
};

struct BadSuperMonster : SuperMonster
{
    void info() const override {puts(__PRETTY_FUNCTION__);}
};

#endif //ABSTRACTFACTORY_ENEMY_H

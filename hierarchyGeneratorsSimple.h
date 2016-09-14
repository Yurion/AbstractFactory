#ifndef ABSTRACTFACTORY_HIERARCHYGENERATORSSIMPLE_H
#define ABSTRACTFACTORY_HIERARCHYGENERATORSSIMPLE_H

//This header do not use for Abstract Factory project

#include <tuple>

template <template <typename> class Unit, typename ... Args>
class GenScatterHierarchy : public Unit<Args> ...
{
};

template <template <typename AtomicType, typename Base> class Unit,
        typename ... Types>
class GenLinearHierarchy;

template <template<typename AtomicType, typename Base> class Unit,
        typename T, typename ... Args>
class GenLinearHierarchy<Unit, T, Args...>
        : public Unit<T, GenLinearHierarchy<Unit, Args...>>
{
};

struct EmptyType {};

template <template <typename AtomicType, typename Base> class Unit,
        typename AtomicType>
class GenLinearHierarchy<Unit, AtomicType>
        : public Unit<AtomicType, EmptyType>
{
};

#endif //ABSTRACTFACTORY_HIERARCHYGENERATORSSIMPLE_H

#ifndef ABSTRACTFACTORY_ENEMYHIERARCHYFACTORY_H
#define ABSTRACTFACTORY_ENEMYHIERARCHYFACTORY_H

#include <memory>
#include <tuple>
#include "tuple_reverse.h"

template <typename T>
struct Type2Type
{
    using type = T;
};

template <typename T>
class AbstractFactoryUnit
{
public:
    virtual std::unique_ptr<T> DoCreate(Type2Type<T>) = 0;

    virtual ~AbstractFactoryUnit() = default;
};

template <template <typename> class Unit, typename ... AbstractProducts>
class AbstractFactory : public Unit<AbstractProducts>...
{
protected:
    using ProductList = std::tuple<AbstractProducts...>;
public:
    template <typename T>
    std::unique_ptr<T> Create()
    {
        Unit<T>& unit = *this;
        return unit.DoCreate(Type2Type<T>());
    }
};

template <typename ConcreteProduct, typename Base, std::size_t Index>
class ConcreteFactoryUnit : public Base
{
    using BaseProductList = typename Base::ProductList;
    using ReverseBaseProductList = tuple_reverse_t<BaseProductList>;
public:

    using AbstractProduct = std::tuple_element_t<Index, ReverseBaseProductList>;

    std::unique_ptr<AbstractProduct>
    DoCreate(Type2Type<AbstractProduct>) override
    {
        return std::make_unique<ConcreteProduct>();
    }
};

template <typename AbstractFact, template <typename, typename, std::size_t> class Unit,
        typename ... ConcreteProducts>
class ConcreteFactory;

template <typename AbstractFact, template <typename, typename, std::size_t> class Unit,
        typename T, typename ... ConcreteProducts>
class ConcreteFactory<AbstractFact, Unit, T, ConcreteProducts...>
        : public Unit<T, ConcreteFactory<AbstractFact, Unit, ConcreteProducts...>, sizeof...(ConcreteProducts)>
{
};

template <typename AbstractFact, template <typename, typename, std::size_t> class Unit,
        typename ConcreteProduct>
class ConcreteFactory<AbstractFact, Unit, ConcreteProduct>
        : public Unit<ConcreteProduct, AbstractFact, 0>
{

};

#endif //ABSTRACTFACTORY_ENEMYHIERARCHYFACTORY_H
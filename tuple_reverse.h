#ifndef ABSTRACTFACTORY_TUPLE_REVERSE_H
#define ABSTRACTFACTORY_TUPLE_REVERSE_H

#include <tuple>
#include <utility>

template <typename... Ts>
struct tuple_reverse;

template <>
struct tuple_reverse<std::tuple<>>
{
    using type = std::tuple<>;
};

template <typename T, typename... Ts>
struct tuple_reverse<std::tuple<T, Ts...>>
{
using Head = std::tuple<T>;
using Tail = typename tuple_reverse<std::tuple<Ts...>>::type;

using type = decltype(std::tuple_cat(std::declval<Tail>(), std::declval<Head>()));
};

template <typename Tuple>
using tuple_reverse_t = typename tuple_reverse<Tuple>::type;


#endif //ABSTRACTFACTORY_TUPLE_REVERSE_H

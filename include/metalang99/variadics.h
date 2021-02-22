/**
 * @file
 * Variadic macro utilities.
 *
 * Metalang99 does not provide a lot of stuff in this module; if a needed function is missed,
 * invoking #METALANG99_list and then manipulating with the resulting Cons-list might be helpful.
 */

#ifndef METALANG99_VARIADICS_H
#define METALANG99_VARIADICS_H

#include <metalang99/lang.h>
#include <metalang99/priv/variadics/count.h>
#include <metalang99/util.h>

// Desugaring {
/**
 * Computes a count of its arguments.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/variadics.h>
 *
 * // 3
 * M_variadicsCount(v(~, ~, ~))
 *
 * // 1
 * M_variadicsCount()
 * @endcode
 *
 * @note At most 63 arguments are acceptable.
 */
#define METALANG99_variadicsCount(...) METALANG99_call(METALANG99_variadicsCount, __VA_ARGS__)

/**
 * Extracts a head of its arguments.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/variadics.h>
 *
 * // 1
 * M_variadicsHead(v(1, 2, 3))
 *
 * // 1
 * M_variadicsHead(v(1))
 * @endcode
 */
#define METALANG99_variadicsHead(...) METALANG99_call(METALANG99_variadicsHead, __VA_ARGS__)

/**
 * Extracts a tail of its arguments.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/variadics.h>
 *
 * // 2, 3
 * M_variadicsTail(v(1, 2, 3))
 * @endcode
 *
 * @note At least two arguments must be specified.
 */
#define METALANG99_variadicsTail(...) METALANG99_call(METALANG99_variadicsTail, __VA_ARGS__)

/**
 * The same as #METALANG99_variadicsHead but accepts parenthesized variadics.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/variadics.h>
 *
 * // 1
 * M_parenthesizedVariadicsHead(v((1, 2, 3)))
 * @endcode
 */
#define METALANG99_parenthesizedVariadicsHead(x)                                                   \
    METALANG99_call(METALANG99_parenthesizedVariadicsHead, x)

/**
 * The same as #METALANG99_variadicsTail but accepts parenthesized variadics.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/variadics.h>
 *
 * // 2, 3
 * M_parenthesizedVariadicsTail(v((1, 2, 3)))
 * @endcode
 */
#define METALANG99_parenthesizedVariadicsTail(x)                                                   \
    METALANG99_call(METALANG99_parenthesizedVariadicsTail, x)

/**
 * The plain version of #METALANG99_variadicsCount.
 */
#define METALANG99_variadicsCountPlain(...) METALANG99_PRIV_VARIADICS_COUNT(__VA_ARGS__)

/**
 * The plain version of #METALANG99_variadicsHead.
 */
#define METALANG99_variadicsHeadPlain(...) METALANG99_PRIV_VARIADICS_HEAD(__VA_ARGS__)

/**
 * The plain version of #METALANG99_variadicsTail.
 */
#define METALANG99_variadicsTailPlain(...) METALANG99_PRIV_VARIADICS_TAIL(__VA_ARGS__)

/**
 * The plain version of #METALANG99_parenthesizedVariadicsHead.
 */
#define METALANG99_parenthesizedVariadicsHeadPlain(x)                                              \
    METALANG99_PRIV_VARIADICS_HEAD(METALANG99_unparenthesizePlain(x))

/**
 * The plain version of #METALANG99_parenthesizedVariadicsTail.
 */
#define METALANG99_parenthesizedVariadicsTailPlain(x)                                              \
    METALANG99_PRIV_VARIADICS_TAIL(METALANG99_unparenthesizePlain(x))
// }

#ifndef DOXYGEN_IGNORE

// Implementation {
#define METALANG99_variadicsCount_IMPL(...) v(METALANG99_variadicsCountPlain(__VA_ARGS__))
#define METALANG99_variadicsHead_IMPL(...)  v(METALANG99_variadicsHeadPlain(__VA_ARGS__))
#define METALANG99_variadicsTail_IMPL(...)  v(METALANG99_variadicsTailPlain(__VA_ARGS__))
#define METALANG99_parenthesizedVariadicsHead_IMPL(x)                                              \
    v(METALANG99_parenthesizedVariadicsHeadPlain(x))
#define METALANG99_parenthesizedVariadicsTail_IMPL(x)                                              \
    v(METALANG99_parenthesizedVariadicsTailPlain(x))

// } (Implementation)

// Arity specifiers {
#define METALANG99_variadicsCount_ARITY             1
#define METALANG99_variadicsHead_ARITY              1
#define METALANG99_variadicsTail_ARITY              1
#define METALANG99_parenthesizedVariadicsHead_ARITY 1
#define METALANG99_parenthesizedVariadicsTail_ARITY 1
// }

// Aliases {
#ifndef METALANG99_NO_SMALL_PREFIX

#define M_variadicsCount             METALANG99_variadicsCount
#define M_variadicsHead              METALANG99_variadicsHead
#define M_variadicsTail              METALANG99_variadicsTail
#define M_parenthesizedVariadicsHead METALANG99_parenthesizedVariadicsHead
#define M_parenthesizedVariadicsTail METALANG99_parenthesizedVariadicsTail

#define M_variadicsCountPlain             METALANG99_variadicsCountPlain
#define M_variadicsHeadPlain              METALANG99_variadicsHeadPlain
#define M_variadicsTailPlain              METALANG99_variadicsTailPlain
#define M_parenthesizedVariadicsHeadPlain METALANG99_parenthesizedVariadicsHeadPlain
#define M_parenthesizedVariadicsTailPlain METALANG99_parenthesizedVariadicsTailPlain

#endif // METALANG99_NO_SMALL_PREFIX
// }

#endif // DOXYGEN_IGNORE

#endif // METALANG99_VARIADICS_H

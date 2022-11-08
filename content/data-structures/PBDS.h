/**
 * Author: FireGhost
 * Date: 2022-11-08
 * License: CC0
 * Source: Codeforces
 * Description: find_by_order(int k): return an iterator
 * to the k-th smallest element, counting from 0.
 * order_of_key(int k): return the number of
 * items strictly smaller than k.
 * Time: O(\log N)
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename Key, typename T> using ordered_map =
tree<Key, T, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset =
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename Key, typename T> using ordered_multimap =
tree<Key, T, less_equal<Key>, rb_tree_tag, tree_order_statistics_node_update>;

/** PROBLEM
 * you're given N dominos (N <= 1000)
 * each domino has a weight <= 1e6
 * 
 * for a domino to collapse, all the dominos before it must collapse
 * and the sum of their weight should be greater or equal than its weight.
 * 
 * we want to remove the minimum amount of dominos from the input so that
 * collapsing the first domino causes all the dominos to collapse.
 * 
 * find the longest sequence of dominos after 0 or more removals to achieve this goal.
 * the ordering of the dominos cannot be changed. 
 */

/** THOUGHTS
 * 
 * greedy algorithm?
 * If you think about it, it makes no sense removing a domino if we can collapse it.
 * In other words, only if we can't collapse it should we remove it...
 * 
 * on 2nd thought, not quite.
 * 
 * example: 1 100 50 75
 * 
 * if we start with 1, we have to remove all the remaining dominos because we can't collapse them
 * which results in 1 domino.
 * 
 * but if we instead skip 1 and start with 100, we can collapse everything.
 * 
 * So it definitely isn't as simple as i first thought. 
 * 
 */

#include <iostream>

const int MAX_N_DOMINOS = 1e3;
const int MAX_DOMINO_WEIGHT = 1e6;

int n_dominos;
int domino_weights[MAX_N_DOMINOS];



int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n_dominos;
    for (int i = 0; i < n_dominos; i++)
        std::cin >> domino_weights[i];
    

}
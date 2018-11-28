#include <iostream>

#include "pawn.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

int main()
{
    std::cout << "Jij jaj\n";
    
    Knight q(4, 4, true);

    for(int i = 8; i >= 1; i--)
    {
        for(int j = 1; j <= 8; j++)
        {
            std::cout << ((q.canAttack(j, i)) ? '#' : '-') << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}


#include "bishop.h"
#include <cmath>

Bishop::Bishop(int x, int y, bool white)
: Piece(BISHOP, x, y, white)
{
    //ctor
}

bool Bishop::canMove(int x, int y)
{
    return canAttack(x,y);
}

bool Bishop::canAttack(int x, int y)
{
    return (std::abs(this->x - x) == std::abs(this->y - y))
        && (this->x != x);
}


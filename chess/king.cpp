#include "king.h"
#include <cmath>

King::King(int x, int y, bool white)
: Piece(KING, x, y, white)
{
    //ctor
}

bool King::canMove(int x, int y)
{
    return canAttack(x,y);
}

bool King::canAttack(int x, int y)
{
    return (std::abs(this->x - x) == 1) && (std::abs(this->y - y) == 1);
}


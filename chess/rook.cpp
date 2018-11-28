#include "rook.h"

Rook::Rook(int x, int y, bool white)
: Piece(ROOK, x, y, white)
{
    //ctor
}

bool Rook::canMove(int x, int y)
{
    return canAttack(x,y);
}

bool Rook::canAttack(int x, int y)
{
    return this->x == x ^ this->y == y;
}


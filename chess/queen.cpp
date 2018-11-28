#include "queen.h"

Queen::Queen(int x, int y, bool white)
: Piece(QUEEN, x, y, white), Rook(x, y, white), Bishop(x ,y, white)
{
    //ctor
}

bool Queen::canMove(int x, int y)
{
    return canAttack(x,y);
}

bool Queen::canAttack(int x, int y)
{
    return Rook::canAttack(x, y) || Bishop::canAttack(x, y);
}


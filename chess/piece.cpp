#include "piece.h"

Piece::Piece(Type type, int x, int y, bool white)
: type(type), x(x), y(y), white(white)
{
    //ctor
}

int Piece::getX()
{
    return x;
}

int Piece::getY()
{
    return y;
}


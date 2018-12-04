#include "piece.h"

Piece::Piece(Type type, int x, int y, bool white)
: type(type), white(white), x(x), y(y)
{
    //ctor
}

Piece::~Piece()
{
    //dtor
}

int Piece::getX()
{
    return x;
}

int Piece::getY()
{
    return y;
}


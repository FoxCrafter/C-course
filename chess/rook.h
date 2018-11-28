#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : virtual public Piece
{
    public:
        Rook(int x, int y, bool white);
        bool canMove(int x, int y);
        bool canAttack(int x, int y);

    protected:

    private:
};

#endif // ROOK_H


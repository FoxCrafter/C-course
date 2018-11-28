#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    public:
        Pawn(int x, int y, bool white);
        bool canMove(int x, int y);
        bool canAttack(int x, int y);

    protected:

    private:
};

#endif // PAWN_H


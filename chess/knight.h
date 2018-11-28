#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    public:
        Knight(int x, int y, bool white);
        bool canMove(int x, int y);
        bool canAttack(int x, int y);

    protected:

    private:
};

#endif // KNIGHT_H


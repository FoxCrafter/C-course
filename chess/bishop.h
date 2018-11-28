#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : virtual public Piece
{
    public:
        Bishop(int x, int y, bool white);
        bool canMove(int x, int y);
        bool canAttack(int x, int y);

    protected:

    private:
};

#endif // BISHOP_H


#ifndef QUEEN_H
#define QUEEN_H

#include "rook.h"
#include "bishop.h"


class Queen : public Rook, public Bishop
{
    public:
        Queen(int x, int y, bool white);
        bool canMove(int x, int y);
        bool canAttack(int x, int y);

    protected:

    private:
};

#endif // QUEEN_H


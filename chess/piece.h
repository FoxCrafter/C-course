#ifndef PIECE_H
#define PIECE_H

class Piece{
    public:
        const enum Type{
            PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, N_TYPES
        } type;
        const bool white;
        Piece(Type type, int x, int y, bool white);
        virtual bool canMove(int x, int y) = 0;
        virtual bool canAttack(int x, int y) = 0;
        int getX();
        int getY();

    protected:
        int x, y;
};

#endif // PIECE_H


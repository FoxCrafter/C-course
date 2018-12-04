#ifndef BOARD_H
#define BOARD_H

#define MAX_N_PIECES 32

#include "pawn.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

class Board
{
public:
    Board();
    Piece* getPiece(int x, int y);
    bool removePiece(int x, int y);
    bool removePiece(Piece* piece);
    bool addPiece(Piece::Type type, int x, int y, bool white);
    void print();
    ~Board();
private:
    int getPieceId(int x, int y);
    int getPieceId(Piece* piece);
    bool removePiece(int id);

    Piece *pieces[MAX_N_PIECES];
};

#endif // BOARD_H


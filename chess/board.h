#ifndef BOARD_H
#define BOARD_H

#define MAX_N_PIECES 32

#include "piece.h"

class Board
{
public:
    Piece* getPiece(int x, int y);
    bool removePiece(int x, int y);
    bool removePiece(Piece* piece);
    bool addPiece(Piece::Type type, int x, int y, bool white);
    ~Board();
private:
    int getPieceId(int x, int y);
    int getPieceId(Piece* piece);
    bool removePiece(int id);
    
    Piece *pieces[MAX_N_PIECES];
};

#endif // BOARD_H


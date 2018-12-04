#include <iostream>

#include "board.h"

int main()
{
    Board b;
    b.addPiece(Piece::PAWN, 4, 8, false);
    b.addPiece(Piece::QUEEN, 3, 4, true);
    b.addPiece(Piece::KNIGHT, 7, 7, false);
    b.addPiece(Piece::PAWN, 5, 5, true);
    b.addPiece(Piece::QUEEN, 5, 4, false);
    b.addPiece(Piece::ROOK, 2, 5, true);
    b.addPiece(Piece::QUEEN, 1, 5, false);
    b.print();
    return 0;
}


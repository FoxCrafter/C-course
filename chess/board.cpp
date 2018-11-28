#include "board.h"
#include "pawn.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

Board::~Board()
{
    for(int i = 0; i < MAX_N_PIECES; i++)
    {
        delete pieces[i];
    }
}

Piece* Board::getPiece(int x, int y)
{
    int i = getPieceId(x, y);
    if(i >= 0)
    {
        return pieces[i];
    }
    return nullptr;
}

bool Board::removePiece(int x, int y)
{
    return removePiece(getPieceId(x, y));
}

bool Board::removePiece(Piece* piece)
{
    return removePiece(getPieceId(piece));
}

bool Board::removePiece(int i)
{
    if(i >= 0)
    {
        delete pieces[i];
        pieces[i] = nullptr;
        return true;
    }
    return false;
}

bool Board::addPiece(Piece::Type type, int x, int y, bool white)
{
    if(getPieceId(x, y) == -1)
    {
        int i = getPieceId(nullptr);
        if(i >= 0)
        {
            switch(type)
            {
            case Piece::PAWN:
                pieces[i] = new Pawn(x, y, white);
                break;
            case Piece::KNIGHT:
                pieces[i] = new Knight(x, y, white);
                break;
            case Piece::BISHOP:
                pieces[i] = new Bishop(x, y, white);
                break;
            case Piece::ROOK:
                pieces[i] = new Rook(x, y, white);
                break;
            case Piece::QUEEN:
                pieces[i] = new Queen(x, y, white);
                break;
            case Piece::KING:
                pieces[i] = new King(x, y, white);
                break;
            }
            return true;
        }
    }
    return false;
}

int Board::getPieceId(int x, int y)
{
    for(int i = 0; i < MAX_N_PIECES; i++)
    {
        if(pieces[i] != nullptr)
        {
            if(pieces[i]->getX() == x && pieces[i]->getY())
            {
                return i;
            }
        }
    }
    return -1;
}

int Board::getPieceId(Piece* piece)
{
    for(int i = 0; i < MAX_N_PIECES; i++)
    {
        if(pieces[i] == piece)
        {
            return i;
        }
    }
    return -1;
}



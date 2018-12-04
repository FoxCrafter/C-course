#include "board.h"

#include <iostream>

Board::Board()
{
    for(int i = 0; i < MAX_N_PIECES; i++)
    {
        pieces[i] = NULL;
    }
}

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
    return NULL;
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
        pieces[i] = NULL;
        return true;
    }
    return false;
}

bool Board::addPiece(Piece::Type type, int x, int y, bool white)
{
    if(getPieceId(x, y) == -1)
    {
        int i = getPieceId(NULL);
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
            default:
                pieces[i] = new King(x, y, white);
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
        if(pieces[i] != NULL)
        {
            if(pieces[i]->getX() == x && pieces[i]->getY() == y)
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

void Board::print()
{
    for(int i = 8; i >= 0; i--)
    {
        for(int j = 1; j <= 8; j++)
        {
            Piece* p = getPiece(j, i);
            if(p == NULL)
            {
                std::cout << '-';
            }
            else
            {
                char c;
                switch(p->type)
                {
                case Piece::PAWN:
                    c = 'P';
                    break;
                case Piece::KNIGHT:
                    c = 'N';
                    break;
                case Piece::BISHOP:
                    c = 'B';
                    break;
                case Piece::ROOK:
                    c = 'R';
                    break;
                case Piece::QUEEN:
                    c = 'Q';
                    break;
                default:
                    c = 'K';
                    break;
                }
                if(p->white)
                {
                    c += 'a' - 'A';
                }
                std::cout << c;
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

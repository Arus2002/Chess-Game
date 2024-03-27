#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "board.hpp"
#include "figures.hpp"

class Logic {
public:
    Logic() = default;
    void start();

private:
    Board m_board;
    WhitePawn whitePawn;
    BlackPawn blackPawn;
    WhiteRook whiteRook;
    BlackRook blackRook;
    WhiteKnight whiteKnight;
    BlackKnight blackKnight;
    WhiteBishop whiteBishop;
    BlackBishop blackBishop;
    WhiteKing whiteKing;
    BlackKing blackKing;
    WhiteQueen whiteQueen;
    BlackQueen blackQueen;
};
#endif
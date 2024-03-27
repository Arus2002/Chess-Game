#ifndef FIGURES_HPP
#define FIGURES_HPP

#include "board.hpp"

class Figures {
public:
    virtual void valid_steps(Board& m_board, std::string& color, int index1, int index2) = 0;
    virtual bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) = 0;
    int from_char_to_int_helper(char symbol) const;

protected:
    Board m_board;
};

class WhitePawn: public Figures {
public:
    void valid_steps(Board& m_board, std::string& white, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;
};

class BlackPawn: public Figures {
public:
    void valid_steps(Board& m_board, std::string& black, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;
};

class Rook: public Figures {
public:
    void valid_steps(Board& m_board, std::string& color, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;
};

class WhiteRook: public Rook {
public:
    void steps(Board& m_board, std::string& white);
};

class BlackRook: public Rook {
public:
    void steps(Board& m_board, std::string& black);
};

class Knight: public Figures {
public:
    void valid_steps(Board& m_board, std::string& color, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;
};

class WhiteKnight: public Knight {
public:
    void steps(Board& m_board, std::string& white);
};

class BlackKnight: public Knight {
public:
    void steps(Board& m_board, std::string& black);
};

class Bishop: public Figures {
public:
    void valid_steps(Board& m_board, std::string& color, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;
};

class WhiteBishop: public Bishop {
public:
    void steps(Board& m_board, std::string& white);
};

class BlackBishop: public Bishop {
public:
    void steps(Board& m_board, std::string& black);
};

class King: public Figures {
public:
    void valid_steps(Board& m_board, std::string& color, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;
};

class WhiteKing: public King {
public:
    void steps(Board& m_board, std::string& white);
};

class BlackKing: public King {
public:
    void steps(Board& m_board, std::string& black);
};

class WhiteQueen: public Figures {
public:
    void valid_steps(Board& m_board, std::string& color, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;

private:
    Rook m_rook;
    Bishop m_bishop;
};

class BlackQueen: public Figures {
public:
    void valid_steps(Board& m_board, std::string& color, int index1, int index2) override;
    bool is_empty(Board& m_board, const std::string& tmp, int index1, int index2) override;

private:
    Rook m_rook;
    Bishop m_bishop;
};

#endif
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>

class Board {
public:
    Board();
    void initialize_board();
    void draw_board();
    bool get_turn() const;
    bool get_exit() const;
    void set_turn(bool turn);
    void set_exit(bool exit);
    std::size_t size() const;
    std::vector<std::string>& operator[](size_t index);


private:
    bool m_turn;
    bool m_exit1;
    const int m_rows = 10; 
    const int m_cols = 10;
    std::vector<std::vector<std::string>> m_board;
};

#endif
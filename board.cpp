#include "board.hpp"

Board::Board() 
    : m_turn{false}
    , m_exit1{false}
    , m_rows{10}
    , m_cols{10}
    , m_board{10, std::vector<std::string>(10)}
{
    initialize_board();
}

void Board::initialize_board() {
    //initialize row a...j
    char ch = 'a';
    for (int j = 1; j < m_board[0].size() - 1; ++j) {
        m_board[0][j] = ch++;
    }

    int count_white{0};
    int count_black{0};

    for (int i = 1; i < m_board.size(); ++i) {
        for (int j = 0; j < m_board[i].size(); ++j) {
            if (i == 1 && j == 1) {
                m_board[i][j] = "wr1"; //Rook-navak
            }
            else if (i == 1 && j == 2) {
                m_board[i][j] = "wk1"; //Knight-dzi
            }
            else if (i == 1 && j == 3) {
                m_board[i][j] = "wb1"; //Bishop-pix
            }
            else if (i == 1 && j == 4) {
                m_board[i][j] = "WK";
            }
            else if (i == 1 && j == 5) {
                m_board[i][j] = "WQ";
            }
            else if (i == 1 && j == 6) {
                m_board[i][j] = "wb2"; //Bishop-pix
            }
            else if (i == 1 && j == 7) {
                m_board[i][j] = "wk2"; //Knight
            }
            else if (i == 1 && j == 8) {
                m_board[i][j] = "wr2"; //Rook-navak
            }
            else if (i == 2 && j <= 8) {
                m_board[i][j] = "wp"; //Pawn-zinvor
                m_board[i][j] += std::to_string(count_white);
                count_white++;
            }
            else if (i == 7 && j <= 8) {
                m_board[i][j] = "bp"; //Pawm-zinvor
                m_board[i][j] += std::to_string(count_black);
                count_black++;
            }
            else if (i == 8 && j == 1) {
                m_board[i][j] = "br1"; //Rook-navak
            }
            else if (i == 8 && j == 2) {
                m_board[i][j] = "bk1"; //Knight -dzi
            }
            else if (i == 8 && j == 3) {
                m_board[i][j] = "bb1"; //Bishop
            }
            else if (i == 8 && j == 4) {
                m_board[i][j] = "BK";
            }
            else if (i == 8 && j == 5) {
                m_board[i][j] = "BQ";
            }
            else if (i == 8 && j == 6) {
                m_board[i][j] = "bb2"; //Bishop-pix
            }
            else if (i == 8 && j == 7) {
                m_board[i][j] = "bk2"; // Knight-dzi
            }
            else if (i == 8 && j == 8) {
                m_board[i][j] = "br2";//Rook-navak
            }
        }
    }

    //initialize column with a...j
    ch = 'a';
    for (int j = 1; j < m_board[0].size() - 1; ++j) {
        m_board[m_board.size() - 1][j] = ch++;
    }
}

void Board::draw_board() {
    char ch = 'a';
    std::cout << "  | ";
    for (int j = 1; j < m_board[0].size() - 1; ++j) {
        std::cout << m_board[0][j] << " | ";
    }
    std::cout << " " << std::endl << std::endl;

    char count_left{'8'};
    char count_right{'8'};

    for (int i = 1; i < m_board.size() - 1; ++i) {
        for (int j = 0; j < m_board[i]. size(); ++j) {
            if (j == 0) {
                m_board[i][j] = count_left--;
                std::cout << " " << m_board[i][j] << "|";
            }
            else if (j == m_board[i].size() - 1) {
                m_board[i][j] = count_right--;
                std::cout << m_board[i][j];
            }
            else if (m_board[i][j] == "") {
                std::cout << "   |";
                //continue;
            }
            else if (m_board[i][j] == "wp1" || m_board[i][j] == "wp2" ||
                m_board[i][j] == "wp3" || m_board[i][j] == "wp4" ||
                m_board[i][j] == "wp5" || m_board[i][j] == "wp6" ||
                m_board[i][j] == "wp7" || m_board[i][j] == "wp8" ||
                m_board[i][j] == "bp1" || m_board[i][j] == "bp2" ||
                m_board[i][j] == "bp3" || m_board[i][j] == "bp4" ||
                m_board[i][j] == "bp5" || m_board[i][j] == "bp6" ||
                m_board[i][j] == "bp7" || m_board[i][j] == "bp8") {

                std::cout << m_board[i][j] << "|";
            }
            else if (m_board[i][j] == "WK" || m_board[i][j] == "WQ" ||
                m_board[i][j] == "BK" || m_board[i][j] == "BQ") {

                std::cout << m_board[i][j] << " |";
            }
            else {
                std::cout << m_board[i][j] << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    std::cout << "  | ";
    for (int j = 1; j < m_board[0].size() - 1; ++j) {
        std::cout << m_board[m_board.size() - 1][j] << " | ";
    }
    std::cout << std::endl;
}

bool Board::get_turn() const {
    return m_turn;
}

bool Board::get_exit() const {
    return m_exit1;
}

void Board::set_turn(bool turn) {
    m_turn = turn;
}

void Board::set_exit(bool exit) {
    m_exit1 = exit;
}

std::vector<std::string>& Board::operator[](size_t index) {
    return m_board[index];
}

std::size_t Board::size() const {
    return m_board.size();
}
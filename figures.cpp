#include "figures.hpp"

int Figures::from_char_to_int_helper(char symbol) const {
    switch (symbol) {
    case 'a':
        return 1;
    case 'b':
        return 2;
    case 'c':
        return 3;
    case 'd':
        return 4;
    case 'e':
        return 5;
    case 'f':
        return 6;
    case 'g':
        return 7;
    case 'h':
        return 8;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    default:
        return 0;
    }
}

void WhitePawn::valid_steps(Board& m_board, std::string& color, int indexx1, int indexx2) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i];
    }//wp1a6*/

    int index1, index2;
    for (int i = 1; i < m_board.size() - 1; ++i) {
        for (int j = 1; j < m_board[i].size() - 1; ++j) {
            if (m_board[i][j] == tmp) {
                if (color[4] >= '1' && color[4] <= '6') {
                    index1 = from_char_to_int_helper(color[3]); //a = 1
                    index2 = from_char_to_int_helper(color[4]); //6
                    if (index2 == (m_board.size() - 3 - i) && i == 2 && index1 == j && m_board[i + 2][j] == "") {
                        m_board[i + 2][j] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == (m_board.size() - 2 - i) && index1 == j && m_board[i + 1][j] == "") {
                        m_board[i + 1][j] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == m_board.size() - 2 - i && index1 == j - 1 && j > 1 && m_board[i + 1][j - 1][0] == 'b') {
                        m_board[i + 1][j - 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == m_board.size() - 2 - i && index1 == j + 1 && j < 8 && m_board[i + 1][j + 1][0] == 'b') {
                        m_board[i + 1][j + 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    else {
                        std::cout << "Not right step!" << std::endl;
                        m_board.set_turn(true);
                    }
                }
            }
        }
    }
}

bool WhitePawn::is_empty(Board& m_board, const std::string& color, int indexx1, int indexx2) { return true; }

void BlackPawn::valid_steps(Board& m_board, std::string& black, int indexx1, int indexx2) {
    std::string tmp = "";
    for (int i = 0; i < black.size() - 2; ++i) {
        tmp += black[i]; //color = bp1
    }
    int index1, index2;
    for (int i = 1; i < m_board.size() - 1; ++i) {
        for (int j = 1; j < m_board[i].size() - 1; ++j) {
            if (m_board[i][j] == tmp) {
                if (black[4] >= '3' && black[4] <= '8') {
                    index1 = from_char_to_int_helper(black[3]); //a = 1
                    index2 = from_char_to_int_helper(black[4]); //3
                    if (index2 == (m_board.size() + 1 - i) && i == 7 && index1 == j && m_board[i - 2][j] == "") {
                        m_board[i - 2][j] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == (m_board.size() - i) && index1 == j && m_board[i - 1][j] == "") {
                        m_board[i - 1][j] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == (m_board.size() - i) && index1 == j - 1 && j > 1 && m_board[i - 1][j - 1][0] == 'w') {
                        m_board[i - 1][j - 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == (m_board.size() - i) && index1 == j + 1 && j < 8 && m_board[i - 1][j + 1][0] == 'w') {
                        m_board[i - 1][j + 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    else {
                        std::cout << "Not right step!" << std::endl;
                        m_board.set_turn(true);
                    }
                }
            }
        }
    }
}

bool BlackPawn::is_empty(Board& m_board, const std::string& color, int indexx1, int indexx2) { return true; }

void Rook::valid_steps(Board& m_board, std::string& color, int index1, int index2) {
    bool isEmpty = false;
    isEmpty = is_empty(m_board, color, index1, index2);

    for (int i = 0; i < m_board.size() - 1; ++i) {
        for (int j = 0; j < m_board[i].size() - 1; ++j) {
            if (m_board[i][j] == color) {
                if (index1 >= 1 && index1 <= 8 && index2 >= 1 && index2 <= 8 && isEmpty == false && (m_board[m_board.size() - 1 - index2][index1][0] != color[0] || m_board[m_board.size() - 1 - index2][index1] == "") && (index1 == j || i == m_board.size() - 1 - index2)) {
                    m_board[m_board.size() - 1 - index2][index1] = m_board[i][j];
                    m_board[i][j] = "";
                    m_board.set_exit(true);
                    return;
                }
                else {
                    std::cout << "Not right step!" << std::endl;
                    m_board.set_turn(true);
                }
            }
        }
    }
}
    
bool Rook::is_empty(Board& m_board, const std::string& color, int index1, int index2) {
    int x{};
    int y{};
    for (int i = 0; i < m_board.size(); ++i) {
        for (int j = 0; j < m_board.size(); ++j) {
            if (m_board[i][j] == color) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != 0 && y != 0) {
            break;
        }
    }
    if (index1 == y) {
        for (int i = x + 1; i < m_board.size() - 1 - index2; ++i) {
            if (m_board[i][y] != "") {
                return true;
            }
        }
        for (int i = m_board.size() - 1 - index2 + 1; i < x; ++i) {
            if (m_board[i][y] != "") {
                return true;
            }
        }
    }
    else if (m_board.size() - 1 - index2 == x) {
        for (int j = y + 1; j < index1; ++j) {
            if (m_board[x][j] != "") {
                return true;
            }
        }
        for (int j = index1 + 1; j < y; ++j) {
            if (m_board[x][j] != "") {
                return true;
            }
        }
    }
    return false;
}

void WhiteRook::steps(Board& m_board, std::string& color) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i]; 
    }

    int index1 = from_char_to_int_helper(color[3]); // a = 1
    int index2 = from_char_to_int_helper(color[4]); // 5

    valid_steps(m_board, tmp, index1, index2);
}

void BlackRook::steps(Board& m_board, std::string& black) {
    std::string tmp = "";
    for (int i = 0; i < black.size() - 2; ++i) {
        tmp += black[i]; //color = br1a5
    }
    int index1 = from_char_to_int_helper(black[3]); // a = 1
    int index2 = from_char_to_int_helper(black[4]); // 5

    valid_steps(m_board, tmp, index1, index2);
}

void Knight::valid_steps(Board& m_board, std::string& color, int index1, int index2) {
    for (int i = 1; i < m_board.size() - 1; ++i) {
        for (int j = 1; j < m_board.size() - 1; ++j) {
            if (m_board[i][j] == color ) {
                if ((index1 == j + 2 || index1 == j - 2) && ((m_board.size() - 1 - index2 == i + 1) || (m_board.size() - 1 - index2 == i - 1)) && m_board[m_board.size() - 1 - index2][index1][0] != color[0]) {
                    m_board[m_board.size() - 1 - index2][index1] = m_board[i][j];
                    m_board[i][j] = "";
                    return;
                }
                else if ((m_board.size() - 1 - index2 == i + 2 || m_board.size() - 1 - index2 == i - 2) && ((index1 == j + 1) || (index1 == j - 1)) && m_board[m_board.size() - 1 - index2][index1][0] != color[0]) {
                    m_board[m_board.size() - 1 - index2][index1] = m_board[i][j];
                    m_board[i][j] = "";
                    return;
                }
                else {
                    std::cout << "Not right step!" << std::endl;
                    m_board.set_turn(true);
                }
            }
        }
    }
}

bool Knight::is_empty(Board& m_board, const std::string& color, int index1, int index2) {
    return true;
}

void WhiteKnight::steps(Board& m_board, std::string& color) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i]; //color = wk1c3 i = 1 j = 2
    }

    int index1 = from_char_to_int_helper(color[3]); // c = 3
    int index2 = from_char_to_int_helper(color[4]); // 3
    valid_steps(m_board, tmp, index1, index2);
}

void BlackKnight::steps(Board& m_board, std::string& black) {
    std::string tmp = "";
    for (int i = 0; i < black.size() - 2; ++i) {
        tmp += black[i]; //color = wk1c3 i = 1 j = 2
    }

    int index1 = from_char_to_int_helper(black[3]); // c = 3
    int index2 = from_char_to_int_helper(black[4]); // 3
    valid_steps(m_board, tmp, index1, index2);
}

void Bishop::valid_steps(Board& m_board, std::string& color, int index1, int index2) {
    bool isEmpty = false;
    isEmpty = is_empty(m_board, color, index1, index2);

    for (int i = 1; i < m_board.size() - 1; ++i) {
        for (int j = 1; j < m_board.size() - 1; ++j) {
            if (m_board[i][j] == color) {
                if (((i - (m_board.size() - 1 - index2) == j - index1) || (i - (m_board.size() - 1 - index2) == j + index1)) && m_board[m_board.size() - 1 - index2][index1][0] != color[0] && isEmpty == false) {
                    m_board[m_board.size() - 1 - index2][index1] = m_board[i][j];
                    m_board[i][j] = "";
                    m_board.set_exit(true);
                    return;
                }
                else if (((i - (m_board.size() - 1 - index2) == index1 - j) || (i + (m_board.size() - 1 - index2) == index1 - j)) && m_board[m_board.size() - 1 - index2][index1][0] != color[0] && isEmpty == false) {
                    m_board[m_board.size() - 1 - index2][index1] = m_board[i][j];
                    m_board[i][j] = "";
                    m_board.set_exit(true);
                    return;
                }
                else if (((i + (m_board.size() - 1 - index2) == j - index1) || (i + (m_board.size() - 1 - index2) == j + index1)) && m_board[m_board.size() - 1 - index2][index1][0] != color[0] && isEmpty == false) {
                    m_board[m_board.size() - 1 - index2][index1] = m_board[i][j];
                    m_board[i][j] = "";
                    m_board.set_exit(true);
                    return;
                }
                else {
                    std::cout << "Not right step!" << std::endl;
                    m_board.set_turn(true);
                }
            }
        }
    }
}

bool Bishop::is_empty(Board& m_board, const std::string& color, int index1, int index2) {
    int x{};
    int y{};
    for (int i = 0; i < m_board.size(); ++i) {
        for (int j = 0; j < m_board.size(); ++j) {
            if (m_board[i][j] == color) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != 0 && y != 0) {
            break;
        }
    }

    if (x > m_board.size() - 1 - index2) {
        size_t dest = x - (m_board.size() - 1 - index2);
        for (int i = 1; i < dest; ++i) {
            if (y > index1) {
                if (m_board[x - i][y - i] != "") {
                    return true;
                }
            }
            if (y < index1) {
                if (m_board[x - i][y + i] != "") {
                    return true;
                }
            }
        }
    }
    if (x < m_board.size() - 1 - index2) {
        size_t dest = m_board.size() - 1 - index2 - x;
        for (int i = 1; i < dest; ++i) {
            if (y < index1) {
                if (m_board[x + i][y + i] != "") {
                    return true;
                }
            }
            if (y > index1) {
                if (m_board[x + i][y - i] != "") {
                    return true;
                }
            }
        }
    }
    return false;
}

void WhiteBishop::steps(Board& m_board, std::string& color) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i]; //color = wk1c3 i = 1 j = 2
    }

    int index1 = from_char_to_int_helper(color[3]); // c = 3
    int index2 = from_char_to_int_helper(color[4]); // 3

    valid_steps(m_board, tmp, index1, index2);
}

void BlackBishop::steps(Board& m_board, std::string& black) {
    std::string tmp = "";
    for (int i = 0; i < black.size() - 2; ++i) {
        tmp += black[i]; //color = wk1c3 i = 1 j = 2
    }

    int index1 = from_char_to_int_helper(black[3]); // c = 3
    int index2 = from_char_to_int_helper(black[4]); // 3

    valid_steps(m_board, tmp, index1, index2);
}

void King::valid_steps(Board& m_board, std::string& color, int index1, int index2) {
    for (int i = 1; i < m_board.size() - 1; ++i) {
        for (int j = 1; j < m_board[i].size() - 1; ++j) {
            if (m_board[i][j] == color) {
                if (color[3] >= '1' && color[3] <= '8') {
                    if (index2 == m_board.size() - 2 - i && index1 == j && (m_board[i + 1][j] == "" || m_board[i + 1][j][0] != color[0])) {
                        m_board[i + 1][j] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == m_board.size() - i && index1 == j && (m_board[i - 1][j] == "" || m_board[i - 1][j][0] != color[0])) {
                        m_board[i - 1][j] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == m_board.size() - 1 - i && index1 == j - 1 && j > 1 && (m_board[i][j - 1] == "" || m_board[i][j - 1][0] != color[0])) {
                        m_board[i][j - 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    if (index2 == m_board.size() - 1 - i && index1 == j + 1 && j < 8 && (m_board[i][j + 1] == "" || m_board[i][j + 1][0] != color[0])) {
                        m_board[i][j + 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    //dzax verevi kisaankyunagits
                    if (index2 == m_board.size() - 2 - i && index1 == j - 1 && (m_board[i + 1][j - 1] == "" || m_board[i + 1][j - 1][0] != color[0])) {
                        m_board[i + 1][j - 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    //aj verevi kisaankyuagots
                    if (index2 == m_board.size() - 2 - i && index1 == j + 1 && (m_board[i + 1][j + 1] == "" || m_board[i + 1][j + 1][0] != color[0])) {
                        m_board[i + 1][j + 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    //dzax nerqevi kisaankyunagits
                    if (index2 == m_board.size() - i && index1 == j - 1 && (m_board[i - 1][j - 1] == "" || m_board[i - 1][j - 1][0] != color[0])) {
                        m_board[i - 1][j - 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    //aj nerqevi kisaankyunagits
                    if (index2 == m_board.size() - i && index1 == j + 1 && (m_board[i - 1][j + 1] == "" || m_board[i - 1][j + 1][0] != color[0])) {
                        std::cout << 5;
                        m_board[i - 1][j + 1] = m_board[i][j];
                        m_board[i][j] = "";
                        return;
                    }
                    else {
                        std::cout << "Not right step!" << std::endl;
                        m_board.set_turn(true);
                    }
                }
            }
        }
    }
}

bool King::is_empty(Board& m_board, const std::string& color, int index1, int index2) {
    return true;
}

void WhiteKing::steps(Board& m_board, std::string& color) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i]; //tmp = WKd3
    }

    int index1, index2;
    index1 = from_char_to_int_helper(color[2]); //a = 1
    index2 = from_char_to_int_helper(color[3]); //6

    valid_steps(m_board, tmp, index1, index2);
}

void BlackKing::steps(Board& m_board, std::string& black) {
    std::string tmp = "";
    for (int i = 0; i < black.size() - 2; ++i) {
        tmp += black[i]; //tmp = WKd3
    }

    int index1, index2;
    index1 = from_char_to_int_helper(black[2]); //a = 1
    index2 = from_char_to_int_helper(black[3]); //6

    valid_steps(m_board, black, index1, index2);
}

void WhiteQueen::valid_steps(Board& m_board, std::string& color, int indexx1, int indexx2) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i]; //tmp = WKd3
    }
    int index1, index2;
    index1 = from_char_to_int_helper(color[2]); //a = 1
    index2 = from_char_to_int_helper(color[3]); //6
    m_rook.valid_steps(m_board, tmp, index1, index2);
    if (m_board.get_exit()) {
        m_board.set_exit(false);
        m_board.set_turn(false);
        return;
    }
    m_bishop.valid_steps(m_board, tmp, index1, index2);
    if (m_board.get_exit()) {
        m_board.set_exit(false);
        m_board.set_turn(false);
        return;
    }
}

bool WhiteQueen::is_empty(Board& m_board, const std::string& tmp, int indexx1, int indexx2) { return true; }

void BlackQueen::valid_steps(Board& m_board, std::string& color, int indexx1, int indexx2) {
    std::string tmp = "";
    for (int i = 0; i < color.size() - 2; ++i) {
        tmp += color[i]; //tmp = WKd3
    }

    int index1, index2;
    index1 = from_char_to_int_helper(color[2]); //a = 1
    index2 = from_char_to_int_helper(color[3]); //6
    m_rook.valid_steps(m_board, tmp, index1, index2);
    if (m_board.get_exit()) {
        m_board.set_exit(false);
        m_board.set_turn(false);
        return;
    }
    m_bishop.valid_steps(m_board, tmp, index1, index2);
    if (m_board.get_exit()) {
        m_board.set_exit(false);
        m_board.set_turn(false);
        return;
    }
}

bool BlackQueen::is_empty(Board& m_board, const std::string& tmp, int indexx1, int indexx2) { return true; }

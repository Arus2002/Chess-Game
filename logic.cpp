#include "logic.hpp"

void Logic::start() {
    m_board.draw_board();
    bool flag = false;
    std::string white, black;
    while (true) {
        std::cout << "White's turn!" << std::endl;
        std::cin >> white; //wp1a6
        std::string tmp = "";
        for (int i = 0; i < white.size() - 3; ++i) {
            tmp += white[i];
        } 
        std::string tmpforKingAndQueen = "";
        for (int i = 0; i < white.size() - 2; ++i) {
            tmpforKingAndQueen += white[i];
        }
        if (tmp == "wp") {
            whitePawn.valid_steps(m_board, white, 0, 0);
        }
        else if (tmp == "wr") {
            whiteRook.steps(m_board, white);
        }
        else if (tmp == "wk") {
            whiteKnight.steps(m_board, white);
        }
        else if (tmp == "wb") {
            whiteBishop.steps(m_board, white);
        }
        else if (tmpforKingAndQueen == "WK") {
            whiteKing.steps(m_board, white);
        }
        else if (tmpforKingAndQueen == "WQ") {
            whiteQueen.valid_steps(m_board, white, 0, 0);
        }
        else {
            m_board.set_turn(true);
        }
        if (m_board.get_turn()) {
            m_board.set_turn(false);
            continue;
        }
        m_board.draw_board();

        while (true) {
            std::cout << "Black's turn!" << std::endl;
            std::cin >> black;
            tmp = "";
            for (int i = 0; i < black.size() - 3; ++i) {
                tmp += black[i];
            }
            tmpforKingAndQueen = "";
            for (int i = 0; i < black.size() - 2; ++i) {
                tmpforKingAndQueen += black[i];
            }
            if (tmp == "bp") {
                blackPawn.valid_steps(m_board, black, 0, 0);
            }
            else if (tmp == "br") {
                blackRook.steps(m_board, black);
            }
            else if (tmp == "bk") {
                blackKnight.valid_steps(m_board, black, 0, 0);
            }
            else if (tmp == "bb") {
                blackBishop.valid_steps(m_board, black, 0, 0);
            }
            else if (tmpforKingAndQueen == "BK") {
                blackKing.valid_steps(m_board, black, 0, 0);
            }
            else if (tmpforKingAndQueen == "BQ") {
                blackQueen.valid_steps(m_board, black, 0, 0);
            }
            else {
                m_board.set_turn(true);
            }
            if (m_board.get_turn()) {
                m_board.set_turn(false);
                continue;
            }
            else {
                m_board.draw_board();
                break;
            }
        }
    }
}
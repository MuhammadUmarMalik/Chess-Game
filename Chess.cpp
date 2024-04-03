#include <iostream>
#include <graphics.h>

const int BOARD_SIZE = 8;
const int SQUARE_SIZE = 80;

class ChessBoardGUI {
public:
    ChessBoardGUI() {
        initwindow(BOARD_SIZE * SQUARE_SIZE, BOARD_SIZE * SQUARE_SIZE, "Chess Board");
           setbkcolor(LIGHTGRAY); // Set background color
        initializeBoard();
    }

    void run() {
        while (!kbhit()) {
            delay(100); // Delay to reduce CPU usage
            drawBoard();
        }
        closegraph();
    }

private:
    // Struct to represent squares
    struct Square {
        int x1, y1, x2, y2;
    };

    Square squares[BOARD_SIZE][BOARD_SIZE];

    void initializeBoard() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                squares[i][j].x1 = j * SQUARE_SIZE;
                squares[i][j].y1 = i * SQUARE_SIZE;
                squares[i][j].x2 = (j + 1) * SQUARE_SIZE;
                squares[i][j].y2 = (i + 1) * SQUARE_SIZE;
            }
        }
    }

   void drawBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if ((i + j) % 2 == 0) {
                setfillstyle(SOLID_FILL,WHITE); // Light square color
            } else {
                setfillstyle(SOLID_FILL,BLACK); // Dark square color
            }
            bar(squares[i][j].x1, squares[i][j].y1, squares[i][j].x2, squares[i][j].y2); // Draw filled rectangle
        }
    }
}

};

int main() {
    ChessBoardGUI chessBoard;
    chessBoard.run();
    return 0;
}

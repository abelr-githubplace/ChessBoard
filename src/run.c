#include "../header/board.h"

int main(){
    Board* B = newBoard();
    setBoard(B);
    unsigned m[4];
    displayBoardWhite(B);

    scanf("%lc%u,%lc%u", &m[0], &m[1], &m[2], &m[3]);
    PosToCoord(m);
    move(B, m);
    displayBoardBlack(B);

    unsigned l[4] = { 101, 7, 101, 5 }; 
    PosToCoord(l);
    move(B, l);
    displayBoardWhite(B);

    deleteBoard(B);

    return EXIT_SUCCESS;
}
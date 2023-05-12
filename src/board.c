#include "../header/board.h"

struct board* newBoard(){
    //Board
    struct board* board = malloc(sizeof(struct board));
    if(!board) errx(EXIT_FAILURE, "Memory shortage: could not create a new board.\n");
    
    //State
    board->state = WHITE;
    
    //Array
    for(size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
            board->array[i][j] = EMPTY;
        }
    }
    
    //Last-move
    for(size_t i = 0; i < 4; i++){
        board->last_move[i] = 0;
    }

    return board;
}

void clearBoard(struct board* Board){
    for(size_t i = 0; i < 8; i++){
        for(size_t j = 0; j < 8; j++){
            Board->array[i][j] = EMPTY;
        }
    }
}

void setBoard(struct board* Board){
    clearBoard(Board);

    //Ponds
    for(size_t i = 0; i < 8; i++){
        Board->array[1][i] = W_POND;
        Board->array[6][i] = B_POND;
    }

    //Knights
    Board->array[0][b] = W_KNIGHT;
    Board->array[0][g] = W_KNIGHT;
    Board->array[7][b] = B_KNIGHT;
    Board->array[7][g] = B_KNIGHT;

    //Bishops
    Board->array[0][c] = W_BISHOP;
    Board->array[0][f] = W_BISHOP;
    Board->array[7][c] = B_BISHOP;
    Board->array[7][f] = B_BISHOP;

    //Rooks
    Board->array[0][a] = W_ROOK;
    Board->array[0][h] = W_ROOK;
    Board->array[7][a] = B_ROOK;
    Board->array[7][h] = B_ROOK;

    //Queens
    Board->array[0][d] = W_QUEEN;
    Board->array[7][d] = B_QUEEN;

    //Kings
    Board->array[0][e] = W_KING;
    Board->array[7][e] = B_KING;
    
}

void displayBoardBlack(struct board* Board){
    printf("\t________________________________________\n\n");
    printf("\t\t\tThe Board\n\n");
    for(size_t i = 0; i < 8; i++){
        printf("\t%8lu|", i+1);
        for(size_t j = 0; j < 8; j++){
            switch (Board->array[i][j])
            {
            case EMPTY:
                printf("  |");
                break;
            case W_POND:
                printf("\u2659 |");
                break;
            case W_KNIGHT:
                printf("\u2658 |");
                break;
            case W_BISHOP:
                printf("\u2657 |");
                break;
            case W_ROOK:
                printf("\u2656 |");
                break;
            case W_QUEEN:
                printf("\u2655 |");
                break;
            case W_KING:
                printf("\u2654 |");
                break;
            case B_POND:
                printf("\u265F |");
                break;
            case B_KNIGHT:
                printf("\u265E |");
                break;
            case B_BISHOP:
                printf("\u265D |");
                break;
            case B_ROOK:
                printf("\u265C |");
                break;
            case B_QUEEN:
                printf("\u265B |");
                break;
            case B_KING:
                printf("\u265A |");
                break;

            default:
                printf("%2u|", Board->array[i][j]);
                break;
            }
        }
        printf("\n");
    }
    printf("\t\t  a  b  c  d  e  f  g  h\n\n");
    printf("\t________________________________________\n\n");
}

void displayBoardWhite(struct board* Board){
    printf("\t________________________________________\n\n");
    printf("\t\t\tThe Board\n\n");
    for(size_t i = 8; i > 0; i--){
        printf("\t%8lu|", i);
        for(size_t j = 0; j < 8; j++){
            switch (Board->array[i-1][j])
            {
            case EMPTY:
                printf("  |");
                break;
            case W_POND:
                printf("\u2659 |");
                break;
            case W_KNIGHT:
                printf("\u2658 |");
                break;
            case W_BISHOP:
                printf("\u2657 |");
                break;
            case W_ROOK:
                printf("\u2656 |");
                break;
            case W_QUEEN:
                printf("\u2655 |");
                break;
            case W_KING:
                printf("\u2654 |");
                break;
            case B_POND:
                printf("\u265F |");
                break;
            case B_KNIGHT:
                printf("\u265E |");
                break;
            case B_BISHOP:
                printf("\u265D |");
                break;
            case B_ROOK:
                printf("\u265C |");
                break;
            case B_QUEEN:
                printf("\u265B |");
                break;
            case B_KING:
                printf("\u265A |");
                break;

            default:
                printf("%2u|", Board->array[i-1][j]);
                break;
            }
        }
        printf("\n");
    }
    printf("\t\t  a  b  c  d  e  f  g  h\n\n");
    printf("\t________________________________________\n\n");
}

void deleteBoard(struct board* Board){
    free(Board);
}

void move(struct board* Board, unsigned move[4]){
    if(isEmpty(Board->array[move[0]][move[1]])){
        printf("Move disabled: There is no piece on this square.\n");
        return;
    }
    if(Board->state == MATE){
        printf("Move disabled: This play has ended.\n");
        return;
    }
    if(sameColor(Board->array[move[2]][move[3]], Board->array[move[0]][move[1]])){
        printf("Move disabled: You cannot eat your own pieces.\n");
        return;
    }

    // checkmate ?
    Board->state = (Board->state + 1) % 2;

    for(size_t i = 0; i < 4; i++){
        Board->last_move[i] = move[i];
    }
    Board->array[move[2]][move[3]] = Board->array[move[0]][move[1]];
    Board->array[move[0]][move[1]] = EMPTY;
}

bool isWhite(unsigned P){
    return P >= W_POND && P <= W_KING;
}

bool isEmpty(unsigned S){
    return S == EMPTY;
}

bool sameColor(unsigned P1, unsigned P2){
    return isWhite(P1) == isWhite(P2);
}

void PosToCoord(unsigned array[4]){
    printf("%u,%u -> %u,%u\n", array[0], array[1], array[2], array[3]);

    array[0] -= (unsigned)'a';
    array[1] -= 1;
    array[2] -= (unsigned)'a';
    array[3] -= 1;

    printf("%u,%u -> %u,%u\n", array[0], array[1], array[2], array[3]);

    unsigned tmp = array[0];
    array[0] = array[1];
    array[1] = tmp;
    tmp = array[2];
    array[2] = array[3];
    array[3] = tmp;
}
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//Wyświetla plansze
void PrintBoard(uint8_t *board, size_t N)
{
    size_t dim = N*N;
    size_t it_dim;
    size_t it_col = 0;

    for(it_dim = 0; it_dim < dim; it_dim++)
    {
      it_col++;
      printf(" %d ", board[it_dim]);
      if(it_col == N)
      {
        printf("\n");
        it_col = 0;
      }
    }
}


//sprawdza ataki
uint8_t SafeCheck(uint8_t *board, size_t row, size_t col, size_t N)
{
    int i, j;

    //sprawdz w kolumnie
    for (i = 0; i < col; i++)
        if (board[row*N + i])
            return 0;

    //diagonala 1
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i*N + j])
            return 0;

    //diagonala 2
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i*N + j])
            return 0;
    return 1;
}


uint8_t _Solve(uint8_t *board, size_t col, size_t N)
{
    //Wszystkie figury rozstawione
    if (col >= N)
        return 1;

    //A jak nie, to sprawdzamy wiersz po wierszu czy można ustawić
    for (int i = 0; i < N; i++)
    {
      //Można ustawić w danej pozycji? (col, i)
        if (SafeCheck(board, i, col, N))
        {
            //To ustaw
            board[i*N + col] = 1;

            //rekurencyjnie próbuj ustawiać na kolejnych (col+1)
            if (_Solve(board, col + 1, N))
                return 1;

            //Jak nie możesz ustawić to cofnij krok i spróbuj na kolejnym wierszu
            board[i*N + col] = 0; // BACKTRACK
        }
    }
    return 0;
}


uint8_t SolveNH(uint8_t *board, size_t N)
{

    if (_Solve(board, 0, N) == 0)
    {
        printf("Brak rozwiązan");
        return 0;
    }

    PrintBoard(board, N);
    return 1;
}


int main(int argc, char* argv[])
{
    size_t N = 3;
    N = atoi(argv[1]);
    uint8_t* board = malloc(sizeof(uint8_t)*N*N);

    SolveNH(board, N);

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_symbol(int severity);
int check_game_result(char game_matrix[3][3]);


// Hämta räckvidden en svårighetsgrad skall ha. Används för att generera symboler.
int get_severity_range(int severity_in)
{
    int severity = 0;
    if (severity_in == 1) {
        severity = 3;
    } else if (severity_in == 2) {
        severity = 4;
    } else if (severity_in == 3) {
        severity = 5;
    }
    return severity;
}


// Skapar och skriver ut de framslumpade symbolerna genom en tvådimension array.
int generate_game_matrix(int severity, int *round_count)
{
    // Tidsfrö för slumpgenerator
    srand((unsigned)time(NULL));
    char game_matrix[3][3]; // Tvådimensionell array
    char symbol;
    *round_count = *round_count + 1;  // Öka med ett per spelomgång
    
    // Skriv ut ny spelomgång
    printf("\n***** Spelomgång: %d *****************\n", *round_count);

    // Första dimensionen
    for (int i=0; i<3; i++) {
        printf("\n");
        // Andra dimensionen
        for (int j=0; j<3; j++) {
            symbol = get_symbol(severity); // Tilldela slumpsymbol
            game_matrix[i][j] = symbol;
            printf("[  %c  ]", symbol); // Skriv ut slumpsymbol
        }
    }
    
    return check_game_result(game_matrix);;
}


// Kontrollerar om generate_game_matrix() har genererat några vinstrader och räknar isf upp count_win
// med ett per vinstrad.
int check_game_result(char game_matrix[3][3])
{
    int count_win = 0; // Antal vunna rader
    
    // 1 rad horisontal
    if (game_matrix[0][0] == game_matrix[0][1] && game_matrix[0][0] == game_matrix[0][2]) {
        count_win += 1;
    }
    // 2 rader horisontal
    if (game_matrix[1][0] == game_matrix[1][1] && game_matrix[1][0] == game_matrix[1][2]) {
        count_win += 1;
    }
    // 3 rader horisontal
    if (game_matrix[2][0] == game_matrix[2][1] && game_matrix[2][0] == game_matrix[2][2]) {
        count_win += 1;
    }
    
    // 1 rad vertikal
    if (game_matrix[0][0] == game_matrix[1][0] && game_matrix[0][0] == game_matrix[2][0]) {
        count_win += 1;
    }
    // 2 rader vertikal
    if (game_matrix[0][1] == game_matrix[1][1] && game_matrix[0][1] == game_matrix[2][1]) {
        count_win += 1;
    }
    // 3 rader vertikal
    if (game_matrix[0][2] == game_matrix[1][2] && game_matrix[0][2] == game_matrix[2][2]) {
        count_win += 1;
    }
    
    // Diagonal vänster-topp - höger-botten
    if (game_matrix[0][0] == game_matrix[1][1] && game_matrix[0][0] == game_matrix[2][2]) {
        count_win += 1;
    }
    // Diagonal vänster-botten - höger-topp
    if (game_matrix[2][0] == game_matrix[1][1] && game_matrix[2][0] == game_matrix[0][2]) {
        count_win += 1;
    }
    
    return count_win;
}


// Hämtar symbol att presentera. Funktionen anropas varje varv i iterationen i generate_game_matrix().
// int severity används för att avgöra vilken räckvid slumpgeneratorn ska använda.
// Ju högre värde på severity desto svårare - ju fler symboler kommer användas.
char get_symbol(int severity)
{
    char symbol;
    int number = rand() % severity + 1; // Slumpar nummer mellan 1-X (X: beronde på svårighetsgrad)
    
    // Returnerar en symbol för motsvarande slumpnummer
    switch (number) {
        case 1:
            symbol = 'O';
            break;
        case 2:
            symbol = 'W';
            break;
        case 3:
            symbol = 'X';
            break;
        case 4:
            symbol = 'I';
            break;
        case 5:
            symbol = 'U';
            break;
    }
    return symbol;
}


// Räknar ut hur mycket pengar som ska erhållas vid vinst, beroende på hur många rutor som vunnits
// och vilken svårighetsgrad som är vald.
void calculate_money_won(int bet, int row_won_count, int *money_won, int *account, int severity_in)
{
    if (row_won_count == 1) {
        *money_won = bet * 2;
        
    } else if (row_won_count == 2) {
        *money_won = bet * 4;
        
    } else if (row_won_count == 3) {
        *money_won = bet * 8;
        
    } else if (row_won_count == 4) {
        *money_won = bet * 16;
        
    } else if (row_won_count == 8) { // Fullt spel: max 8 rader
        *money_won = bet * 128;
        
    } else {
        *money_won = 0;
    }
    
    if (row_won_count > 0) { // Lägg till vinst på spelkonto
        if (severity_in == 1) {
            *money_won = *money_won * 0.5;  // Lätt: Halva vinstsumman
        } else if (severity_in == 2) {
            // ... Medel: (Oförändrat) En gånger pengarna
        } else if (severity_in == 3) {
            *money_won = *money_won * 3;  // Svårt: Tre gånger pengarna
        }
        *account += *money_won;
    }
}

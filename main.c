#include <stdio.h>
#include "menu.h"
#include "game.h"


int main()
{
    int account = 0; // Användarens spelkonto
    int bet = 0; // Beloppet som satsas
    int severity_in = 0;  // Vald svårighetsgrad
    int severity = 0;  // Svårighetsgradens räckvidd
    int row_won_count = 0; // Antal rader som vunnits per spel
    int money_won = 0; // Bellopp som vunnits per spel
    int round_count = 0; // Antal spel
    
    // Skriver ut välkomstmenyn
    welcome_menu();
    // Hämtar svårtighetsgrad från användare
    severity_in = severity_select();
    
    // Hämta svårighetsgradens räckvidd
    severity = get_severity_range(severity_in);
        
    // Meny för att sätta in pengar
    transaction_menu();
    // Användaren överför pengar på kontot
    account = make_transaction();
    
    // Skriver ut beloppet på insättningen
    printf("\nDu överförde %i kr.\n", account);
    
    // Spelet pågår tills kontot är tomt, eller spelet avbryts
    while (account > 0) {
        
        // Fråga efter belopp tills ett korrekt belopp angivits, eller spelare avslutar.
        make_bet(&account, &bet);
        
        if (bet == 0) { // Användaren avbröt spelet. Saldo skrives ut.
            printf("\nTack för att du spelade! Ditt slutsaldo är %i kr.\n\n", account);
            break;
        }
        
        // Börja spela och returnera antal vunna rader/kolumner/diagonaler
        row_won_count = generate_game_matrix(severity, &round_count);
        
        // Beräknar eventuell vinstsumma
        calculate_money_won(bet, row_won_count, &money_won, &account, severity_in);

        
        // Skriver ut resultat
        print_result(row_won_count, bet, money_won);

        
        // Om pengarna är slut avslutas spelet.
        if (account < 1) {
            printf("Ditt spelkonto är nu tomt. :( Tack för att du spelade.\n");
        }
    }
    
}


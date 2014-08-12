#include <stdio.h>


// Skriver ut välkomstmenyn som visar alternativ för att välja svårighetsgrad
void welcome_menu()
{
    printf("\nVälkommen till “The One Armed Bandit”.\n");
    printf("*************************************\n");
    printf("\nVälj svårighetsgrad på spelet.\n");
    printf("Ju svårare spel, desto mindre är chansen att vinna, men desto högre blir vinsten.\n\n");
    printf("1) Lätt\n");
    printf("2) Medel\n");
    printf("3) Svår\n");
    printf("Ange en siffra 1-3: ");
}


// Skriver meny som visar vilka belopp man kan överföra till spelkontot
void transaction_menu()
{
    printf("\nSätt in pengar på ditt spelkonto.\n");
    printf("Du kan sätta in:\n");
    printf("1) 20 kr.\n");
    printf("2) 50 kr.\n");
    printf("3) 100 kr.\n");
    printf("4) 250 kr.\n");
    printf("5) 500 kr.\n");
    printf("6) 1000 kr.\n");
    printf ("Ange en siffra 1-6: ");
}


// Hämtar användarens input vid vald svårighetsgrad
int severity_select()
{
    int menu_in = 0;
    while (1) {
        scanf("%d", &menu_in);
        if (menu_in < 1 || menu_in > 3) {
            printf("Fel. Du måste ange en siffra mellan 1 och 3. Försök igen: ");
        } else {
            printf("\nVald svårighetsgrad: ");
            if (menu_in == 1) {
                printf("*** LÄTT ***\n");
            } else if (menu_in == 2) {
                printf("*** MEDEL ***\n");
            } else if (menu_in == 3) {
                printf("*** SVÅR ***\n");
            }
            return menu_in;
        }
    }
}


// Hämtar användarens inmatade belopp att överföra till spelkontot
int make_transaction()
{
    int menu_in; // meny input
    int value = 0; // beloppet
    while (1) {
        scanf("%d", &menu_in);
        if (menu_in < 1 || menu_in > 6) { // endast ett val mellan 1 och 6
            printf("Fel. Du måste ange en siffra mellan 1 och 6. Försök igen: ");
        } else {
            // översätt menyval till rätt pengabelopp
            if (menu_in == 1) {
                value = 20;
            } else if (menu_in == 2) {
                value = 50;
            } else if (menu_in == 3) {
                value = 100;
            } else if (menu_in == 4) {
                value = 250;
            } else if (menu_in == 5) {
                value = 500;
            } else if (menu_in == 6) {
                value = 1000;
            }
            return value; // returnera det insatta beloppet
        }
    }
}


// Fråga efter belopp tills ett korrekt belopp angivits, eller spelare avslutar.
void make_bet(int *account, int *bet)
{
    // Skriver ut saldo och ber spelaren att satsa.
    printf("Ditt saldo är: %i kr.\n\n", *account);
    printf("Ange hur mycket du vill satsa. Avsluta med \"0\": ");
    
    while (1) {
        scanf("%d", &*bet);
        
        if (*bet > 0 && *bet <= *account) { // Beloppet får ej överstiga kontots salda
            *account -= *bet; // Dra av satsat belopp från konto
            break;
        } else if (*bet == 0) { // Avslutar med 0
            break;
        } else {
            printf("Ange ett korrekt belopp: ");
        }
    }
}

void print_result(int row_won_count, int bet, int money_won)
{
    printf("\n\n*************************************\n");
    if (row_won_count == 1) {
        printf("\nDu fick %i rad.", row_won_count);
    } else {
        printf("\nDu fick %i rader.", row_won_count);
    }
    printf("\nDu satsade %i kr och fick %i kr tillbaka.\n", bet, money_won);
}

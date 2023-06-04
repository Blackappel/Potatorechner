/**
 * 
*/

//--------------------------------------------------- INCLUDES -
#include <stdio.h>
#include "types.h"
#include "input.h"

int main (void) {
    Iterator tokens = {NULL, NULL};
    Token * token   = NULL;

    tokens = getConsoleInput();
    printf("Eingabe war: ");
    while ( tokens.hasNext() ) {
        token = (Token*)tokens.getNext(token);

        switch (token->type) {
        case ADD:
            printf("+  ");
            break;
        case SUB:
            printf("-  ");
            break;
        case MUL:
            printf("*  ");
            break;
        case DIV:
            printf("/  ");
            break;
        case EXP:
            printf("^  ");
            break;
        case NUM:
            printf("%lf  ", token->ext.NUM_val);
            break;
        case VAR:
            printf("%s  ", token->ext.VAR_val);
            break;
        case ROT:
            printf("ROOOT  ");
            break;
        case BASE:
            printf("_%d", token->ext.BASE_val);
            break;
        case B_OPEN:
            printf("(  ");
            break;
        case B_CLOSE:
            printf(")  ");
            break;
        default :
            printf("???  ");
            break;
        }
    }
    printf("\n");

    return 0;    
}
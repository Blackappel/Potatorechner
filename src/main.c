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
    while ( tokens.hasNext() ) {
        token = (Token*)tokens.getNext(token);

        // TODO - Hier Toller Quellcode -------------
        
    }
    

    return 0;    
}
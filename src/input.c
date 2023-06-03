/**
 * Implementierung der Eingabe
 * @author Lukas Steen
*/

//------------------------------------------------------------------ INCLUDES -
#include <stdlib.h>
#include <stdio.h>
#include "input.h"

//------------------------------------------------------------- INTERNE TYPEN -

/**
 * Implementierung der HasNextFunc.
*/
Bool hasNext (void);

/**
 * Implementierung der GetNextFunc
*/
void * next (void * old);

/**
 * Realisiert die Aufnahme der Konsoleneingabe.
*/
void getInputString (char ** result, int * length);

//----------------------------------------------------------------- VARIABLES -
int g_length, 
    g_pos;
char * g_string;


Iterator getConsoleInput (void) {
    Iterator ret;
        ret.getNext = next;
        ret.hasNext = hasNext;
    
    getInputString(&g_string, &g_length);
    g_pos = 0;

    return ret;
}

//----------------------------------------------------------- IMPLEMENTATIONS -
Bool hasNext (void) {
    return (g_pos < g_length) ? bool_true : bool_false;
}

void * next (void * old) {
    /*== Verarbeitung von n Zeichen zu einem Token in temp ================================================*/
    /**/ #define PROCESS_SYMBOLES(n, tt) { temp->type = (tt); tokenFound = bool_true; g_pos = g_pos + (n); }
    /*=====================================================================================================*/
    if (hasNext()) {
        Token * temp;
        Bool tokenFound = bool_false;
        
        temp = (Token*)old;
   
        while (!tokenFound && g_pos <= g_length) {
            if (g_string[g_pos] == '+') {
                PROCESS_SYMBOLES(1,ADD)
            } else
            if (g_string[g_pos] == '-') {
                PROCESS_SYMBOLES(1,SUB)
            } else
            if (g_string[g_pos] == '*') {
                PROCESS_SYMBOLES(1,MUL)
            } else
            if (g_string[g_pos] == '/') {
                PROCESS_SYMBOLES(1,DIV)
            } else
            if (g_string[g_pos] == '_') {
                PROCESS_SYMBOLES(1,BASE) // - TODO - Das hier ist noch nicht fertig!
            } else
            if (g_string[g_pos] == '^') {
                PROCESS_SYMBOLES(1,EXP)
            } else
            if (g_string[g_pos] == '(') {
                PROCESS_SYMBOLES(1,B_OPEN)
            } else
            if (g_string[g_pos] == ')') {
                PROCESS_SYMBOLES(1,B_CLOSE)
            } else
            if (g_pos+3 < g_length 
                    && g_string[g_pos  ] == 'r'
                    && g_string[g_pos+1] == 'o'
                    && g_string[g_pos+2] == 'o'
                    && g_string[g_pos+3] == 't') {
                PROCESS_SYMBOLES(4,ROT)
            } else
            if (g_string[g_pos] >= 'a' && g_string[g_pos] >= 'z') {
                PROCESS_SYMBOLES(0,VAR) // - TODO - Das hier ist noch nicht fertig!
            } else
            if ((g_string[g_pos] >= '0' && g_string[g_pos] <= '9') 
                    || (g_string[g_pos] >= 'A' && g_string[g_pos] <= 'F')) {
                PROCESS_SYMBOLES(0,NUM) // - TODO - Das hier ist noch nicht fertig!
            } else
            if (g_string[g_pos] == '\0') {
                PROCESS_SYMBOLES(0,END)
            }
        }
        if (!tokenFound) {
            temp->type = ERROR;
        }

        return temp;
    } else {
        free(old);
        return NULL;
    }
}

void getInputString (char ** result, int * length) {
    #define PUFFER_SIZE    5
    #define PUFFER_GROWTH 10
    int s_size = 0,
        i = 0;
    Bool end = bool_false;
    char * temp = NULL,
         next = '\0';

    temp = malloc(PUFFER_SIZE * sizeof(char));
    *result = NULL;
        
    do {
        next = (char)fgetc(stdin);
        if (next != '\n') {
            temp[s_size++] = next;
            if (s_size >= PUFFER_SIZE && (s_size - PUFFER_SIZE) % PUFFER_GROWTH == 0) {
                temp = (char*)realloc(temp, (s_size + PUFFER_GROWTH) * sizeof(char));
            }
        } else {
            temp[s_size++] = '\0';
            end = bool_true;
        }
    } while (!end);

    if (s_size > 1) {
        *result = (char*)realloc(*result, s_size * sizeof(char));
        for (i = 0; i < s_size; i++) {
            (*result)[i] = temp[i];
        }
        *length = s_size - 1;
    }
    free(temp);    
}
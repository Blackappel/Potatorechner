/**
 * types.h beinhaltet alle global benoetigten Typen von Calculator.
 * @author Lukas Steen
*/
#ifndef __TYPES_H__
#define __TYPES_H__

/**
 * Allgeneine Typen
 *---------------------------------------------------------------------------*/
typedef enum {bool_false = 0, bool_true} Bool;


/**
 * Deklarstion der möglichen Token, und dazugehörigen Typen.
 *---------------------------------------------------------------------------*/
typedef enum {
    ERROR = -1, END,
    ADD, SUB, MUL, DIV, EXP,
    NUM, BASE, VAR, ROT,
    B_OPEN, B_CLOSE
} TokenType;

typedef union u_token_extend {
    double NUM_val;
    int    BASE_val;
    char * VAR_val;
} TokenExtend;

typedef struct s_token {
    TokenType   type;
    TokenExtend ext;
} Token;


/**
 * Deklaration Eines Iterators
 *---------------------------------------------------------------------------*/

typedef void * IteratorElem;

/**
 * Praedikat ob ein nächstes Element vorhanden ist.
 * @return true, wenn ja, false, wenn nicht.
*/
typedef Bool (*HasNextFunc) (void);

/**
 * Ermittelt und gibt das naechste Element aus dem Iterator zurück.
 * @param old Adresse des alten Elementes welches überschrieben werden soll.
 *      Wenn NULL wird eine neuer Bereich erstellt.
 * @return Das naechste Element, NULL wenn es keins gibt. In diesem Fall wird
 *      old ebenfalls freigegeben.
*/
typedef IteratorElem (*GetNextFunc) (IteratorElem old);

/**
 * Struktur welche von der Fabrikmethode (Selber zu implementieren) des
 * Iterators zurueck gegeben werden wird.
*/
typedef struct s_tierator {
    HasNextFunc hasNext;
    GetNextFunc getNext;
} Iterator;

#endif
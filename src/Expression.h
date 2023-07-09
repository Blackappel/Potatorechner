/**
 * Stellt alle Komponenten zur Verwaltung und Erstellung von Expressions
 * zur verfühgung.
 * @author Lukas Steen 
*/
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
//--------------------------------------------------- INCLUDES -
#include "types.h"

/**
 * Allgemeiner Typ einer Expression
 *---------------------------------------------------------------------------*/
typedef void * Expr;

typedef enum {
    ET_VAL, ET_VAR,
    ET_ADD, ET_SUB,
    ET_MUL, ET_DIV, ET_POV,
    ET_INV, ET_ROT
} ExprType;

typedef unsigned char ChildSelection;
#define SELECT_CHILD 2
#define SELECT_LEFT  4
#define SELECT_RIGHT 1

/**
 * Löst eine rekusieve Lösung der gegebenen Expression (Expr) aus.
 * @param expression Zu lösende Expr. 
*/
double solve (Expr thisE);

/**
 * Erzeugt eine neue Expression (Expr)
 * @param type Type der zu erzeugenden Expr.
*/
Expr Expression (ExprType type);

/**
 * Löst eine Rekusive Zerstörung der angegenbenen Expr aus.
 * @param to_delete zu zerstörende Expr.
*/
void Destroy (Expr to_delete);

/**
 * Hängt child in die geg. Expression thisE  ein. Dabei spezifiziert 
 * select wo child eingehängt werden soll.
 * @param thisE txt
 * @param select tyt
 * @param child new
*/
void pushChild (Expr thisE, ChildSelection select, Expr child);

/**
 * Gibt eine Referenz auf das in select spezifizierte Child von thisE zurück
 * ohne das eine änderung stat findet.
 * @param thisE txt
 * @param select txt
*/
Expr peekChild (Expr thisE, ChildSelection select);

/**
 * Gibt eine Referenz auf das in select spezifizierte Child von thisE zurück
 * und entfernt das Child aus thisE.
 * @param thisE txt
 * @param select txt
*/
Expr popChild (Expr thisE, ChildSelection select);

/**
 * gibt den Typen von thisE zurück
 * @param thisE tyt
*/
ExprType getType (Expr thisE);

#endif
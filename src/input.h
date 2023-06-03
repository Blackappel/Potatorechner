/**
 * Realisiert die Konsolenbasierte Eingabe in das System.
 * @author Lukas Steen
*/
#ifndef __INPUT_H__
#define __INPUT_H__

#include "types.h"

/**
 * Erzaeugt einen Iterator über eine Folge von Tokens. Die Tokens werden hierbei
 * aus einer Konsoleneingabe abgeleitet. Wobei die Eingabe waehren diese Methode
 * laeuft aufgenommen wird.
 * @return Den Iterator Ueber die Konsoleneingabe, in der Form von Tokens.
*/
Iterator getConsoleInput (void);

#endif
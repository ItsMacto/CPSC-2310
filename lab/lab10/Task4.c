/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/

#include "functions.h"

/* 
 * absV - absolute value of x
 *   Example: absV(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absV(int x) {
    int mask = x >> 31;
    return (x + mask) ^ mask;
}

/* 
 * binAnd - x&y using only ~ and |
 *   Example: binAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int binAnd(int x, int y) {
    return ~((~x) | (~y)); 
}

/* 
 * binNotOr - ~(x|y) using only ~ and &
 *   Example: binNotOr(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 */
int binNotOr(int x, int y) {
    return ~x & ~y;
}

/* 
 * binOr - x|y using only ~ and &
 *   Example: binOr(6, 5) = 7
 *   Legal ops: ~ &
 */
int binOr(int x, int y) {
    return ~(~x & ~y);
 
}

/* 
 * binXor - x^y using only ~ and &
 *   Example: binXor(4, 5) = 1
 *   Legal ops: ~ &
 */
int binXor(int x, int y) {

    return ~(~x & ~y) & ~(x & y);
}




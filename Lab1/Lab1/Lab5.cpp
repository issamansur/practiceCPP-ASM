#include <iostream>

int main()
{
    __asm {
        mov ebx, 02317BC11h
        // ebx = 2317bc11
        mov bx, 01452h
        // ebx = 23171452, bx = 1452
        movzx ax, bh
        // ax = 0014
        movzx cx, bl
        // cx = 0052
    }
}
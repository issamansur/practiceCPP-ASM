#include <iostream>
using namespace std;

int main()
{
	// 5. Write program on c++ and ASM (with inserting)
	// Compare results

	// Solutions:
	
	// for best experience 
	// 1. will use 'else' in c++
	// 2. will no use additional check in asm

	int a = 16;
	int x = 32;
	int y, y1, y2;
	

	// Solution c++
	if (x < 0)
		y1 = abs(x);
	else
		y1 = x - a; // y1=16

	if (x % 3 == 1)
		y2 = a + x;
	else
		y2 = 7; // y2=7

	y = y1 - y2; // y=9

	cout << y << endl; // y=9


	// Solution asm
	__asm {
		// check 1
		mov eax, [x]
		jl eax, 0 cond1
		// if x >= 0
		sub eax, [a]
		jmp stage2
		// if x < 0
			cond1:
		neg eax

		// check 2
			stage2:
		// save y1
		mov [y1], eax

		mov ebx, [x]
		mov ecx, 3
		div ecx
		
		cmp edx, 1 cond2
		// if x % 3 != 1
		mov [y2], 7
		jmp onend
		// if x % 3 != 1
			cond2:
		mov eax, [a]
		add eax, [x]
		mov [y2], eax
			onend:
		
		sub [y1], [y2]

		mov [y], [y1]
	}
	cout << y << endl;
}
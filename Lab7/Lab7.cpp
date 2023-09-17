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
	
	// Solution c++
	int a = 16, x = 32;
	int y, y1, y2;
	

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
	a = 16, x = 32;
	__asm {
		// START condition 1
		cmp a, 0 // a <> 0 ?
		// if x < 0, then go to 'x_less_than_zero'
		jl x_less_than_zero
		// else
		mov eax, x
		sub eax, a // eax = x - a
		mov y1, eax // y1 = eax = x - a
		jmp condition_2

	x_less_than_zero :
		neg eax // eax = abs(x)
		// set y1
		mov y1, eax // y1 = eax = abs(x)
		// END condition 1


		// START condition 2
	condition_2 :
		mov eax, x // eax = x
		mov ecx, 3 // ecx = 3
		mov edx, 0 // !!! very important to zero EDX
		div ecx // edx = EDX:eax % ecx = x % 3
		
		cmp edx, 1 // (edx = x % 3) == 1 ?
		// if x % 3 == 1, then go to 'x_div_3_equal_1'
		je x_div_3_equal_1
		// else 
		mov y2, 7 // y2 = 7
		jmp on_end
	x_div_3_equal_1 :
		mov eax, x // eax = x
		add eax, a // eax = eax + a = x + a
		mov y2, eax // y2 = eax = x + a
		// END condition 2

	on_end:
		mov eax, y1 // eax = y1
		sub eax, y2 // eax = eax - y2 = y1 - y2

		mov y, eax // y = eax = y1 - y2
	}
	cout << y << endl;
}
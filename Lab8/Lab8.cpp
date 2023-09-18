#include <iostream>

using namespace std;

int main()
{
	// 5. Write program on c++ and ASM (with inserting)
	// Compare results

	// Find sum of func's values
	// func: y = 2 * x^2 + 5x - 3
	// from: 1
	// to: 7
	// step: 1 


	// Solutions:

	// Solution c++
	int s = 0;

	for (int x = 1; x <= 7; x++)
		s += x * x + 5 * x - 3;

	cout << s << endl; // y=259


	// Solution asm

	s = 0;
	// for comfort will go from 7 downto 1
	__asm {
		mov ecx, 7 // set needed max value (eax <=> x)

		// START cycle
		start :
		xor ebx, ebx // value of func on one step; ebx = 0

			mov eax, ecx // eax = ecx = x
			mul eax // eax = eax * eax = x^2
			add ebx, eax // ebx = eax = x^2

			mov eax, 5 // eax = 5
			mul ecx // eax = eax * ecx = 5 * x
			add ebx, eax // ebx = eax = x^2 + 5 * x

			add ebx, -3 // ebx = x^2 + 5 * x - 3
			add s, ebx
			// END cycle

			// cycle condition
			loop start // decrement ecx -> ecx = ecx - 1
	}
	cout << s << endl;
}

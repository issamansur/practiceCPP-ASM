#include <iostream>
using namespace std;

int main()
{
	// 5. Change values of two variables
	
	// solution:
	
	// we will use "eax" - 32 bit 
	// because int - 4 bytes = 32 bit

	// variant 1 (use 2 registers)
	int one = 16, two = 32;

	__asm {
		mov eax, one // eax=16
		mov ebx, two // ebx=32
		mov one, ebx // one=32
		mov two, eax // two=16
	}
	cout << "one = " << one << endl; // one=32
	cout << "two = " << two << endl; // two=16

	// variant 2 (use only 1 register)
	one = 16, two = 32;

	__asm {		
		mov eax, one // eax=16
		xchg eax, two // eax=32, two=16
		mov one, eax // one = 32
	}
	cout << "one = " << one << endl; // one=32
	cout << "two = " << two << endl; // two=16
}

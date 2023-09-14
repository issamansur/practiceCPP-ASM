#include <iostream>
using namespace std;

int main()
{
	// 5. Change values of two variables
	int one = 16;
	int two = 32;
	// eax - 32 bit as int - 2 bytes = 32 bit
	__asm {
		mov eax, [one]
		// cannot insert from var to var
		// so use second registr
		mov ebx, two
		mov [two], eax
		mov [one], ebx
	}
	cout << "one = " << one << endl;
	cout << "two = " << two << endl;
}

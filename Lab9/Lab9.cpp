#include <iostream>
using namespace std;

int main()
{
	// 5. Write program on c++ and ASM (with inserting)
	// Compare results

	// 4. Given an array of integers: 
	// 52, 24, 17, -15, 33, 11, 48, 18, -9, 5. 
	// Based on this array of integers, 
	// find their arithmetic mean and construct an array 
	// whose elements equal to the difference between 
	// the original elements and the resulting average.


	// Solutions:
	int a[10] = { 52, 24, 17, -15, 33, 11, 48, 18, -9, 5 };
	int size_array = 10;

	cout << "Input array:" << endl;
	for (int i = 0; i < size_array; i++)
		cout << a[i] << " ";
	cout << endl << endl;


	// Solution c++
	int sum = 0;
	double b1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < size_array; i++)
		sum += a[i];
	cout << "Sum: " << sum << endl << endl;

	double average = sum * 1.0 / size_array;
	cout << "Average: " << average << endl << endl;

	for (int i = 0; i < size_array; i++)
		b1[i] = abs(a[i] - average);

	cout << "Output array (by c++):" << endl;
	for (int i = 0; i < size_array; i++)
		cout << b1[i] << " ";
	cout << endl << endl;


	// Solution asm
	sum = 0;
	double b2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// find sum
	__asm {
		// set counter for looping
		mov ecx, size_array
		mov esi, 0
		// set variable for sum
		mov eax, 0

		// START cycle
	start:
		mov eax, [a + esi * 4]
		add sum, eax

		inc esi
		// END cycle

		// cycle condition
		loop start // decrement ecx -> ecx = ecx - 1
	}
	cout << "Sum: " << sum << endl << endl;

	// find average
	_asm {
		// use FPU (Floating Point Unit):
		// fild = (floating integer load)
		fild dword ptr[sum] // FPU = [sum, ...]
		fild dword ptr[size_array] // FPU = [size_array, sum, ...]
		// fdiv = (floating-point division)
		fdiv // FPU = [sum/size_array, size_array, sum, ...]
		// fstp = (floating - point store and pop)
		fstp qword ptr[average] // average = sum/size_array
	}
	cout << "Average: " << average << endl << endl;

	// set array b2
	__asm {
		// set counter for looping
		mov ecx, size_array
		mov esi, 0
		// set variable for sum
		mov eax, 0

		// START cycle
	start2:
		fild dword ptr[a + esi * 4]
		fld qword ptr[average]
		// fsub = (floating substraction)
		fsub // FPU = [b2[i]-average, average, b2[i], ...]
		fabs
		fstp qword ptr[b2 + esi * 8]


		inc esi
		// END cycle

		// cycle condition
		loop start2 // decrement ecx -> ecx = ecx - 1
	}

	cout << "Output array (by asm):" << endl;
	for (int i = 0; i < size_array; i++)
		cout << b2[i] << " ";
	cout << endl;
}
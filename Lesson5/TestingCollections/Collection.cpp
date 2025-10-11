#include <iostream>
#include <vector>


int main()
{
	//Random-Acess
	//Bidirectional
	//Forward
	//Input
	//Output

	//input used for single-pass algorithms that process containers sequentially.
	//accessing each element only once

	//output Like input iterators but used for assigning elements during a single pass.
	//not for accesing them.

	std::vector<int> v;
	v.push_back(5); v.push_back(2); v.push_back(3); v.push_back(8); v.push_back(2);
	v.push_back(3); v.push_back(1); v.push_back(7);


	std::cout << "\n\n\n\n\n\n";

	char a = '3';
	char* p = &a;
	uintptr_t myAddress = reinterpret_cast<uintptr_t>(p);
	int randomNum = (myAddress ^ (myAddress >> 16)) % 2;

	std::cout << "this is p turned into an int: " << (myAddress ^ (myAddress >> 15)) << std::endl;
	
	std::cout << v.capacity();
}
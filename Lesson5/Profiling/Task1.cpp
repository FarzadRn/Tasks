// Includes
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include <array>
// Constants
const int NUM_ELEMENTS = 1000000;


// Functions declarations
void ProfileBackInsertVector(std::vector<int>& vec);
void ProfileRandomAcessVector(std::vector<int>& vec);
void ProfileBackInsertList(std::list<int>& liste);
void ProfileFrontInsertList(std::list<int>& liste);
void ProfileRandomAcessArray(int array[]);
void ProfileBackInsertDeque(std::deque<int>& deq);
void ProfileFrontInsertDeque(std::deque<int>& deq);
void ProfileRandomAcessDeque(std::deque<int>& deq);
// Functions Definitions
void AccessTimeforHalfNum(std::list<int>& liste);
void ProfileRandomAcessCppArray(std::array<int, NUM_ELEMENTS>& Array);
int main()
{
	//vec.reserve(NUM_ELEMENTS);
	{
		// testing arrays: Profiling RandomAccess
		std::array<int, NUM_ELEMENTS> moyArray;
		ProfileRandomAcessCppArray(moyArray);
	}

	{
		int* myArray = new int(NUM_ELEMENTS);
		ProfileRandomAcessArray(myArray);
	}

	{
		std::vector<int> vec = { 0 };
		ProfileBackInsertVector(vec);
		// TODO: Profile RandomAccessVector
		ProfileRandomAcessVector(vec);
	}

	{
		// TODO: Create list
		std::list<int> myL;
		// TODO: ProfileBackInsertList
		ProfileBackInsertList(myL);
		AccessTimeforHalfNum(myL);
		// TODO: ProfileFrontInsertList
		ProfileFrontInsertList(myL);
	}

	{
		// TODO: Create deque
		std::deque<int> myDeq(NUM_ELEMENTS);
		// TODO: ProfileBackInsertDeque
		ProfileBackInsertDeque(myDeq);
		// TODO: ProfileFrontInsertDeque
		ProfileFrontInsertDeque(myDeq);
		// TODO: ProfileRandomAccessDeque
		ProfileRandomAcessDeque(myDeq);
	}
	return 0;
}
void ProfileRandomAcessCppArray(std::array<int, NUM_ELEMENTS>& Array)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		Array[i] = i;
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to random-acess " << NUM_ELEMENTS << "s elements for CPP style(?) array: " << duration.count() << " ms\n";
}
void AccessTimeforHalfNum(std::list<int>& liste)
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	std::list<int>::iterator it = liste.begin();
	std::advance(it, NUM_ELEMENTS / 2);
	for (std::list<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		*it;
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to access " << NUM_ELEMENTS << "s elements of list: " << duration.count() << " ms\n";
}
void ProfileBackInsertVector(std::vector<int>& vec)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		vec.push_back(i);
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to insert " << NUM_ELEMENTS << "s at the back for std::vector: " << duration.count() << " ms\n";
}
void ProfileRandomAcessVector(std::vector<int>& vec)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	int j = 0;
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		vec[i] = i;
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to random-acess " << NUM_ELEMENTS << "s for std::vector: " << duration.count() << " ms\n";
}

void ProfileBackInsertList(std::list<int>& liste)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		liste.push_back(i);
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to insert " << NUM_ELEMENTS << "s at the back for std::list: " << duration.count() << " ms\n";
}
void ProfileFrontInsertList(std::list<int>& liste)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		liste.push_front(i);
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to insert " << NUM_ELEMENTS << "s at the front for std::list: " << duration.count() << " ms\n";
}
void ProfileRandomAcessArray(int array[])
{
	
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	int j = 0;
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		array[i] = i;
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to random-acess " << NUM_ELEMENTS << "s for array: " << duration.count() << " ms\n";
}
void ProfileBackInsertDeque(std::deque<int>& deq)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		deq.push_back(i);
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to insert " << NUM_ELEMENTS << "s at the back for std::deque: " << duration.count() << " ms\n";
}
void ProfileFrontInsertDeque(std::deque<int>& deq)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		deq.push_front(i);
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to insert " << NUM_ELEMENTS << "s at the front for std::deque: " << duration.count() << " ms\n";
}
void ProfileRandomAcessDeque(std::deque<int>& deq)
{
	// Start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	// Insert elements at the back
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		deq[i] = i;
	}

	// End time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	// Duration
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken to random-acess " << NUM_ELEMENTS << "s for std::deque: " << duration.count() << " ms\n";
}

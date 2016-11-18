#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <map>

#include "PinHit.h"
#include "Heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

// global variable for type of heap
std::string heapType = "--max";

//forward declare so I can define it below main
void printGreeting();

std::vector<PinHit> ReadPins(char* fileName, int* totalHits);

template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots);

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits);

int main(int argc, char* argv[]) {

	printGreeting();
	int totalHits = 0;
	std::vector<PinHit> myPins = ReadPins(argv[1], &totalHits);
    std::cout << totalHits << std::endl;
	for(unsigned int i = 0; i < myPins.size(); i++){
        if(myPins[i].GetKey() != -1){
        std::cout << myPins[i].GetKey() << "|" << myPins[i].GetValue() << std::endl;
	}
	}
    std::cout << totalHits;
	return EXIT_SUCCESS;
}

// prints your name and section
void printGreeting() {
	std::cout << "Steven Heckman, Section 05" << std::endl;
}

// implement these two functions
std::vector<PinHit> ReadPins(char* fileName, int* totalHits) {
    std::ifstream pinFile;
    std::string line;
    std::vector<PinHit> myPins;
    std::map<int, int> pinMap;
    int pin;
    pinFile.open(fileName, std::ios::in);
    while(std::getline(pinFile, line)){
        bool rerun = false;
        pin = atoi(line.c_str());
        if((pinMap.find(pin)) == pinMap.end()){
            PinHit *newPin= new PinHit(pin, 1);
            myPins.push_back(*newPin);
            pinMap.insert(std::pair<int,int> (pin, (myPins.size()-1)));
        }
        else{
            myPins[pinMap.find(pin)->second].IncrementHits();
        }
        *totalHits += 1;
    }
    return myPins;
}

template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots) {

}

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits) {

	int UPPER_BOUND = totalHits; // used for failsafes

	/*
	* His fictional bank with fictional cards and
	* "normal pins" will allow you to incorrectly attempt
	* to access his card 3 times per hour. You have from
	* the start of the assignment to the end to hack as
	* many accounts as possible (14 days * 24 hr/day * 3
	* attempts/hr = 1008 attempts per card)
	*/
	int MAX_ATTEMPTS = 1008;

	int hackAttemptsLeft = MAX_ATTEMPTS;
	int successfulHacks = 0;

  	srand (time(NULL)); // seeds our random generator with the current time
	int randomNumHits = rand() % totalHits; // generates a random hit between 0 and total hits
	//randomNumHits = 0; // change this if you want to hardcode in your hits for a specific pin
	int curHits = 0; // our variable for crawling
	int randomIndex = -1; // the index where our new random pinhit lives
	int newHits = 0; // number of hits in new "random" pin
	int failSafe = 0; // always good to have one of these in what could be an infinite loop

	/*
	* Linearly searches through PinHits until
	* we've accrued enough hits to reach our random hits
	* which will then determine the next pin to try to hack.
	* We use newHits to make sure we don't pick a random pin
	* that's not in our heap.
	*/
	PinHit curPinHit;
	while (newHits == 0 && failSafe < UPPER_BOUND) {

		for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
			curHits += PinHits[i].GetValue();
			randomIndex = i;
		}
		// should have found the random pin by now
		curPinHit = PinHits[randomIndex];
		newHits = curPinHit.GetValue(); // make sure it's actually in our heap
		std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
		failSafe++;
	}

	// let's make a copy of the heap so we don't modify the original.
	Heap<T, m_size>* heapCopy;

	if (heapType == "--min") {
		heapCopy = new MinHeap<T, m_size>(*heap);
	} else if (heapType == "--max") {
		heapCopy = new MaxHeap<T, m_size>(*heap);
	} else {
		heapCopy = new Heap<T, m_size>(*heap);
	}

	failSafe = 0;

	PinHit defaultPin;

	// exit once hacking 10000 accounts, either a hacking prodigy or something is wrong
	int MAX_NUM_HACKS = 10000;

	while (0 < hackAttemptsLeft && successfulHacks < MAX_NUM_HACKS) {

		// grabs our root
		PinHit topOfHeap = heapCopy->Remove();
		if (topOfHeap == defaultPin)
			break;

		std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

		if (hackAttemptsLeft == 1)
		std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

		hackAttemptsLeft--;

		// account was hacked!
		if (topOfHeap == curPinHit) {
			std::cout << "We got them!" << std::endl;
			successfulHacks++;

			// reset our heap
			if (heapType == "--min") {
				heapCopy = new MinHeap<T, m_size>(*heap);
			} else if (heapType == "--max") {
				heapCopy = new MaxHeap<T, m_size>(*heap);
			} else {
				heapCopy = new Heap<T, m_size>(*heap);
			}

			// reset
			hackAttemptsLeft = MAX_ATTEMPTS;
			randomNumHits = rand() % totalHits;
			curHits = 0;
			randomIndex = -1;
			newHits = 0;
			failSafe = 0;
			while (newHits == 0 && failSafe < UPPER_BOUND) {

				for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
					curHits += PinHits[i].GetValue();
					randomIndex = i;
				}
				// should have found the random pin by now
				curPinHit = PinHits[randomIndex];
				newHits = curPinHit.GetValue(); // make sure it's actually in our heap
				std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
				failSafe++;
			}

			std::cout << "Valid Random Pin: " << curPinHit.GetKey() << " found!" << std::endl;
		}
	}

	return successfulHacks;

}

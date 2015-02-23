/*
 * Initializer.cpp
 *
 * Created on: May 10, 2014
 * Author: jp
 */

#include "Includes.h"
#include "SemaphoreArray.h"
#include "SharedMemory.h"

using namespace std;

int main(int argc, char** argv) {

	char* programName = argv[0];
	int id = getpid();
	stringstream ss;

	int amountOfProducers = AMOUNT_OF_SMOKERS;
	int amountOfConsumers = AMOUNT_OF_AGENTS;

	SemaphoreArray::create(PAPER_SEMAPHORE_ID);
	SemaphoreArray::create(TOBACO_SEMAPHORE_ID);
	SemaphoreArray::create(MATCHES_SEMAPHORE_ID);
	Process::announce(programName, id, LIGHTBLUE, "ipcs succesfully created.");



	Process::createProcesses(PRODUCER_PROCESS_NAME, amountOfProducers);
	Process::createProcesses(CONSUMER_PROCESS_NAME, amountOfConsumers);
	Process::announce(programName, id, LIGHTBLUE, "inicialization complete.");

}


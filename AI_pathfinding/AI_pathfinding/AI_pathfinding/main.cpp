#include "AI_pathfindingApp.h"

int main() {
	
	// allocation
	auto app = new AI_pathfindingApp();

	//1280, 720
	//1920, 1080
	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}
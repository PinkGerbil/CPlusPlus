#include "_2DGameBootstrapApp.h"

int main() {
	
	// allocation
	auto app = new _2DGameBootstrapApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}
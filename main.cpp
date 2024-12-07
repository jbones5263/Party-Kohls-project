#include "Engine.h"

int main()
{
	// Declare an instance of Engine
	Engine engine;
	// Start the engine
	engine.run();
	// Quit in the usual way when the engine is stopped

	RotationMatrix R(45);
	ScalingMatrix S(10);
	TranslationMatrix T(2, 5, 4);
	cout << R << S << T << endl;

	

	return 0;
}
#include "SystemClass.h"
#include "Scene.h"
#include "MainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	SystemClass* System;
	bool result;


	// Create the system object.
	System = SystemClass::GetInstance();
	if (!System)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = System->Initialize();

	SystemClass::GetInstance()->SetBoolVariable("started", false);

	Scene* scene = new MainScene();
	System->SetScene(scene);
	if (result)
	{
		System->Run();
	}

	// Shutdown and release the system object.
	System->Shutdown();
	delete System;
	System = 0;

	return 0;
}

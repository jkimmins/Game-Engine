#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "XInput.lib")
#include <iostream>

#define GAMEPAD_BUTTONS_COUNT 14
#define XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE  7849
#define XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE 8689
#define XINPUT_GAMEPAD_TRIGGER_THRESHOLD    30

namespace myengine
{
	struct Core;

	struct xController
	{
		int cId;
		XINPUT_STATE state;
		float deadzoneX;
		float deadzoneY;
		//Gamepad() : deadzoneX(0.05f), deadzoneY(0.02f) {}
		//Gamepad(float dzX, float dzY) : deadzoneX(dzX), deadzoneY(dzY) {}

		float leftStickX;
		float leftStickY;
		float rightStickX;
		float rightStickY;
		float leftTrigger;
		float rightTrigger;

		int  GetPort();
		XINPUT_GAMEPAD *GetState();
		bool CheckConnection();
		bool Refresh();
		bool IsPressed(WORD);
	};
}

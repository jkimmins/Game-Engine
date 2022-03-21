#include <myengine/myengine.h>

#include <iostream>


/*
-----For some reason the curuthers model can't be loaded and causes a crash so I've commented it out for now-----
*/
struct Player : public Component
{
	void onInitialize(int team, int type, std::string name)
	{
		//std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();

		//std::shared_ptr<Model> cm = getCore()->getResources()->load<Model>("models/curuthers/curuthers");
		//r->setModel(cm);
  }
};

struct Controller : public Component
{
	SDL_Renderer* renderer = SDL_CreateRenderer(SDL_GL_GetCurrentWindow(), -1, 0);
	//TTF_Font* roboto = TTF_OpenFont("fonts\Roboto-Black", 24);
	//SDL_Color white = { 255, 255, 255 };

	void onTick()
	{
	    bool wasConnected = true;
	    Sleep(100);
	    SDL_RenderClear(renderer);

	    if (!getCore()->getXController()->Refresh())
	    {
		    if (wasConnected)
		    {
			    wasConnected = false;

			    std::cout << "Please connect an Xbox controller." << std::endl;
		    }
	    }
	    else
	    {
		    if (!wasConnected)
		    {
			    wasConnected = true;

			    std::cout << "Controller connected on port " << getCore()->getXController()->GetPort() << std::endl;
		    }

		    std::cout << "Left thumb stick: (" << getCore()->getXController()->leftStickX << ", " << getCore()->getXController()->leftStickY << ")   Right thumb stick : (" << getCore()->getXController()->rightStickX << ", " << getCore()->getXController()->rightStickY << ")" << std::endl;

		    std::cout << "Left analog trigger: " << getCore()->getXController()->leftTrigger << "   Right analog trigger: " << getCore()->getXController()->rightTrigger << std::endl;

		    if (getCore()->getXController()->rightStickX == 1)
	  	    {
		  	  getTransform()->rotate(0, -1, 0);
	  	    }
		    if (getCore()->getXController()->rightStickX == -1)
		    {
			    getTransform()->rotate(0, 1, 0);
    		}
		    if (getCore()->getXController()->rightStickY == 1)
		    {
			    getTransform()->translate(0, 0, -0.1f);
		    }
		    if (getCore()->getXController()->rightStickY == -1)
		    {
			    getTransform()->translate(0, 0, 0.1f);
		    }

		    if (getCore()->getXController()->IsPressed(XINPUT_GAMEPAD_A))
		    {
			    std::cout << "(A) button pressed" << std::endl;
			    getCore()->getGUI()->setColour(renderer, 255, 0, 0, 255);
			    getCore()->getGUI()->drawFilledRect(renderer, 0, 0, 200, 150);
				//getCore()->getGUI()->drawMessage(renderer, roboto, white, "test", 200, 200, 100, 100);
		    }
			if (getCore()->getXController()->IsPressed(XINPUT_GAMEPAD_B))
			{
				std::cout << "(B) button pressed" << std::endl;
				getCore()->getGUI()->setColour(renderer, 0, 255, 0, 255);
				getCore()->getGUI()->drawEmptyRect(renderer, 400, 400, 100, 300);
			}
			if (getCore()->getXController()->IsPressed(XINPUT_GAMEPAD_X))
			{
				std::cout << "(X) button pressed" << std::endl;
				getCore()->getGUI()->setColour(renderer, 0, 0, 255, 255);
				getCore()->getGUI()->drawFilledRect(renderer, 01, 10, 400, 50);
			}
			if (getCore()->getXController()->IsPressed(XINPUT_GAMEPAD_Y))
			{
				std::cout << "(Y) button pressed" << std::endl;
				getCore()->getGUI()->setColour(renderer, 250, 150, 50, 255);
				getCore()->getGUI()->drawEmptyRect(renderer, 200, 200, 200, 200);
			}
	    }

		if (getCore()->getKeyboard()->getKey('q'))
		{
			getCore()->getGUI()->setColour(renderer, 255, 0, 0, 255);
			getCore()->getGUI()->drawFilledRect(renderer, 0, 0, 200, 150);
			//getCore()->getGUI()->drawMessage(renderer, roboto, white, "test", 200, 200, 100, 100);

			getCore()->getGUI()->setColour(renderer, 0, 255, 0, 255);
			getCore()->getGUI()->drawEmptyRect(renderer, 400, 400, 100, 300);

			getCore()->getGUI()->setColour(renderer, 0, 0, 255, 255);
			getCore()->getGUI()->drawFilledRect(renderer, 01, 10, 400, 50);

			getCore()->getGUI()->setColour(renderer, 250, 150, 50, 255);
			getCore()->getGUI()->drawEmptyRect(renderer, 200, 200, 200, 200);
		}

	    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderPresent(renderer);
		
		if(getCore()->getKeyboard()->getKey('w'))
	    {
			getTransform()->translate(0, 0, -0.1f);
        }
        else if(getCore()->getKeyboard()->getKey('s'))
        {
			getTransform()->translate(0, 0, 0.1f);
        }

      if(getCore()->getKeyboard()->getKey('a'))
      {
		  getTransform()->rotate(0, 1, 0);
      }
      else if(getCore()->getKeyboard()->getKey('d'))
      {
		  getTransform()->rotate(0, -1, 0);
      }
    }
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
  
	//Add test player object
	std::shared_ptr<Entity> pe = core->addEntity();
	pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
	std::shared_ptr<Player> p = pe->addComponent<Player>(1, 2, "Test Player");
  
	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();
	camera->addComponent<Controller>();
  
	std::shared_ptr<Entity> c2 = core->addEntity();
	c2->getTransform()->setPosition(rend::vec3(0, 20, 0));
	c2->getTransform()->rotate(-90, 0, 0);
	std::shared_ptr<Camera> mc = c2->addComponent<Camera>();
	mc->addRenderTexture();
  
	core->start();
  
	return 0;
}

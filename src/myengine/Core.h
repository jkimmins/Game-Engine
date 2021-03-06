#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace myengine
{

struct Renderer;
struct Entity;
struct Keyboard;
struct xController;
struct GUI;
struct Camera;
struct Resources;

struct Model;

struct Core
{
  static std::shared_ptr<Core> initialize();

  std::shared_ptr<Entity> addEntity();
  std::shared_ptr<Keyboard> getKeyboard();
  std::shared_ptr<xController> getXController();
  std::shared_ptr<GUI> getGUI();
  std::shared_ptr<Camera> getCamera();
  std::shared_ptr<Resources> getResources();

  void start();

private:
  friend struct myengine::Camera;
  friend struct myengine::Renderer;
  friend struct myengine::Model;

  std::vector<std::shared_ptr<Entity> > entities;
  std::weak_ptr<Core> self;
  SDL_Window* window;
  SDL_GLContext glContext;
  std::shared_ptr<rend::Context> context;
  std::shared_ptr<Keyboard> keyboard;
  std::shared_ptr<xController> xboxController;
  std::shared_ptr<GUI> gui;
  std::shared_ptr<Resources> resources;

  std::weak_ptr<Camera> currentCamera;
  std::vector<std::weak_ptr<Camera> > cameras;

};

}

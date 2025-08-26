#include "Core/Game.h"
#include "Core/Window.h"
#include "Graphics/GraphicsFactory.h"
#include "Scenes/CubeScene.h"

int main() {
    std::unique_ptr<Meteor::Game> game = std::make_unique<Meteor::Game>();
    Meteor::Window& window = (Meteor::Window&)game->GetWindow();
    auto renderer = Meteor::GraphicsFactory::CreateRenderer(window);
    Meteor::CubeScene scene;
    scene.SetRenderer(renderer);

    game->AddLayer(&scene);
    game->Run();

    return 0;
}
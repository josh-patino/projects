#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
//#include "Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"
#include "AssetManager.hpp"
#include <sstream>
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "KeyboardController.hpp"
#include "UILabel.hpp"
#include "ColliderComponent.hpp"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = { 0,0,800,640 };

AssetManager* Game::assets = new AssetManager(&manager);

bool Game::isRunning = false;

auto& player(manager.addEntity());
auto& label(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    if (TTF_Init() == -1)
    {
        std::cout << "Error : SDL_TTF" << std::endl;
    }

    assets->AddTexture("terrain", "/Users/joshuapatino/Desktop/projects/projects/Resources/mario_terrain.png");
    assets->AddTexture("player", "/Users/joshuapatino/Desktop/projects/projects/Resources/mario_animations.png");
    assets->AddTexture("projectile", "/Users/joshuapatino/Downloads/assets/proj.png");

    assets->AddFont("arial", "/Users/joshuapatino/Downloads/assets/arial.ttf", 16);

    map = new Map("terrain", 3, 32);
    //ecs implementation

    map->LoadMap("/Users/joshuapatino/Downloads/assets/map.map", 25, 20);

    player.addComponent<TransformComponent>(800.0f, 640.0f, 32 , 32, 4);
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

    SDL_Color white = { 255, 255, 255, 255 };
    
    label.addComponent<UILabel>(10, 10, "Test String", "arial", white);

    assets->CreateProjectile(Vector2D(600, 600), Vector2D(2,0),200, 2, "projectile");
    assets->CreateProjectile(Vector2D(600, 620), Vector2D(2, 0), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(400, 600), Vector2D(2, 1), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(600, 600), Vector2D(2, -1), 200, 2, "projectile");

}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));

void Game::handleEvents()
{
    
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT :
        isRunning = false;
        break;
    default:
        break;
    }
}



void Game::update()
{

    SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPos = player.getComponent<TransformComponent>().position;

    std::stringstream ss;
    ss << "Player position: " << playerPos;
    label.getComponent<UILabel>().SetLabelText(ss.str(), "arial");

    manager.refresh();
    manager.update();

    
    for (auto& c : colliders)
    {
        SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
        if (Collision::AABB(cCol, playerCol))
        {
            player.getComponent<TransformComponent>().position = playerPos;
        }
    }

    for (auto& p : projectiles)
    {
        if (Collision::AABB(player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
        {
            std::cout << "Hit player!" << std::endl;
            p->destroy();
        }
    }

    camera.x = static_cast<int>(player.getComponent<TransformComponent>().position.x - 400);
    camera.y = static_cast<int>(player.getComponent<TransformComponent>().position.y - 320);

    if (camera.x < 0)
        camera.x = 0;
    if (camera.y < 0)
        camera.y = 0;
    if (camera.x > camera.w)
        camera.x = camera.w;
    if (camera.y > camera.h)
        camera.y = camera.h;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    for (auto& t : tiles)
    {
        t->draw();
    }

    for (auto& c : colliders)
    {
        c->draw();
    }

    for (auto& p : players)
    {
        p->draw();
    }

    for (auto& p : projectiles)
    {
        p->draw();
    }

    label.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

#include "Engine.h"

#include <iostream>
#include <ostream>



#ifdef TRACY_ENABLE
#include <tracy/Tracy.hpp>
#endif

int Engine::Init()
{
#ifdef TRACY_ENABLE
    ZoneScoped;
#endif

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    my_window_ = SDL_CreateWindow("Hello SDL2", 100, 100, 640*2, 480*2, SDL_WINDOW_SHOWN);
    if (my_window_ == nullptr) {
        SDL_Quit();
        return 1;
    }

    // Create SDL Renderer
    renderer_ = SDL_CreateRenderer(my_window_, 1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr) {
        SDL_DestroyWindow(my_window_);
        SDL_Quit();
        return 1;
    }

    graphic_manager_ = new GraphicManager();

    // Initialize Dear ImGui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Initialize ImGui for SDL and SDL_Renderer
    ImGui_ImplSDL2_InitForSDLRenderer(my_window_, renderer_);
    ImGui_ImplSDLRenderer2_Init(renderer_);
}

int Engine::Loop()
{
    while (!quit_) 
    {
        // Poll for events
        while (SDL_PollEvent(&event_)) {
            ImGui_ImplSDL2_ProcessEvent(&event_); // Process ImGui events
            if (event_.type == SDL_QUIT) {
                quit_ = true;  // Exit loop if the window is closed
            }
        }

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Create a simple ImGui window
        ImGui::Begin("Debug window");
        ImGui::Text("Hello, world!");
        ImGui::End();

        // Rendering
        ImGui::Render();
        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255); // Clear with a black color
        SDL_RenderClear(renderer_);
        graphic_manager_->Clear();

        // Render ImGui data
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());

        // TODO : Finish the switch case
        switch (int i = 1)
        {
        case  0 :
            solar_system_.MovePlanet();
            for (auto& planet : solar_system_.planets())
            {
                graphic_manager_->CreateCircle(planet.position(), 25.0f, {255, 0, 255});
            }
            break;

        case 1:
            // TODO : Make the collider check
            //The collider can go past trough each others and make other change colors
            
        	collision_.MoveCircle();
            collision_.CheckCollisions();
            for (auto& circle : collision_.circles_)
            {
              if(circle.second.is_colliding)
              {
                  graphic_manager_->CreateCircle(circle.first.position(), circle.second.radius_, {0, 255, 0});
                  // std::cout << "Circles colliding" << std::endl;
              }
              else
              {
                  graphic_manager_->CreateCircle(circle.first.position(), circle.second.radius_, {0, 0, 255});
              }
            }
            
            break;

        case 2:
            // TODO : Make the collisions check
            //The collider must bounce between each others when they collide
            aabb_.UpdateAABBs(20.0f);
            aabb_.ResolveCollisions();
            
            break;

		default: 
            break;
        }

        SDL_RenderGeometry(
            renderer_, nullptr, 
            graphic_manager_->vertices().data(), 
            graphic_manager_->vertices().size(), 
            graphic_manager_->idx_vertices().data(), 
            graphic_manager_->idx_vertices().size()
        );


        // Present the frame
        SDL_RenderPresent(renderer_);
    }

    // Cleanup ImGui and SDL
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(my_window_);
    SDL_Quit();

    return 0;
}
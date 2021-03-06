/* Tower-Defence
 *
 * Author: Jukka Vatjus-Anttila <jukka.vatjusanttila@gmail.com>
 *
 * For conditions of distribution and use, see copyright notice in LICENSE.txt
 */

#include <iostream>

#include "GameLogic/cGameEntity.h"
#include "GameLogic/cMapper.h"
#include "GameLogic/entityEnums.h"
#include "Renderer/cRenderer.h"
#include "EventHandler/cEventHandler.h"

#include "common.h"

bool appRunning;

void print() { ; }

int main(int argc, char** argv)
{
#if defined(UNIX)
    std::cout << "Hello tower defense linux version - experimental branch on github - v0.1.6!\n";
#else
    std::cout << "Hello tower defense win32 version - experimental branch on github - v0.1.6!\n";
#endif

    appRunning = true;

    // Initialize variables for gameloop timer logic
    sf::Clock clock;
    const int framerate = 60;
    float framestartTime = 0;
    float difference = 0;
    float sleepTime = 0;
    float frameBudget = 1/(float)framerate;

    // Singletons
    renderer::cRenderer *render;
    gamelogic::cMapper *mapper;
    IOHandling::cEventHandler *eventHandler;

    try {
        render = renderer::cRenderer::getInstance();
        mapper = gamelogic::cMapper::getInstance();
        eventHandler = IOHandling::cEventHandler::getInstance();
    } catch (std::bad_alloc& e) {
        std::cout << "Initial memory allocation for mapper and renderer failed! " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    // Start running the clock just before gameloop
    clock.Reset();

    // Gameloop
    while(appRunning)
    {
        // Get current framestart time
        framestartTime = clock.GetElapsedTime();

        // Update game logic and renderer instance.
        mapper->update(framestartTime);
        render->update(framestartTime);
        eventHandler->update();

        // Get time elapsed in game logic update
        difference = clock.GetElapsedTime() - framestartTime;

        // If difference is smaller than budgeted, rest until next frame
        if (difference < frameBudget)
        {
            // Rendering budgets:
            // 60fps = 16,667ms
            // 30fps = 33,333ms
            // 10fps = 100ms
            //  5fps = 200ms
            sleepTime = frameBudget - difference;
            // Sleep for rest of the frame
            sf::Sleep(sleepTime);
        }
    }
    // End of gameloop. Destroy mapper.
    delete eventHandler;
    delete render;
    delete mapper;


    return EXIT_SUCCESS;
}


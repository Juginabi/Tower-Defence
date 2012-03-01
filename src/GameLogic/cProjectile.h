/* Tower-Defence
 *
 * Author: Jukka Vatjus-Anttila <jukka.vatjusanttila@gmail.com>
 *
 * For conditions of distribution and use, see copyright notice in LICENSE.txt
 */

#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <string>
#include "cGameEntity.h"
#include <SFML/System/Vector2.hpp>


namespace gamelogic {

class cProjectile : public cGameEntity
{
public:
    cProjectile(cGameEntity *owner, cGameEntity *target);
    ~cProjectile();
    void update(float frametime);
    std::string name();
    void initializeEntity();
private:
    // Name for this entity. Possibly obsolete.
    std::string entityName_;

    // Entity movespeed on map.
    int movespeed_;

    // Last move time for movement interpolation.
    float lastMoveTime_;

    // Owner entity. No use cases yet.
    cGameEntity *owner_;

    // Target entity. No actual use cases yet.
    cGameEntity *target_;

    // Position
    sf::Vector2f position_;

    // Direction vector
    sf::Vector2f direction_;

};
} // gamelogic

#endif
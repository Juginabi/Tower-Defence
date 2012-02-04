/* 
 * File:   towerEntity.h
 * Author: Jukka Vatjus-Anttila
 *
 * Created on January 23, 2012, 8:51 PM
 */
#ifndef TOWERENTITY_H
#define	TOWERENTITY_H

#include <string>
class gameEntity;

class towerEntity : public gameEntity
{
public:
    /// Constructor
    towerEntity();

    /// Destructor
    ~towerEntity();

    /// Set damage output for tower
    void setDamage(const unsigned int);

    /// Set maximum fire range for tower
    void setRange(const unsigned int);

    /// Set target entity for tower
    void setTarget(gameEntity*);

    /// Update method for towerEntity
    void update(float);

    /// Get entity name
    std::string name();

private:
    /// Fire method. Launches projectile towards enemy entity.
    void fire();

    /// Acquires target enemy entity if possible
    void acquireTarget();

    /// Target entity. NULL if no target acquired.
    gameEntity* enemy;

    /// Tower damage output
    unsigned int damage;

    /// Tower maximum range
    unsigned int range;

    /// Reload timeout
    int reloadTimeout_;

    /// Entity name
    std::string entityName;  
};

#endif	/* TOWERENTITY_H */


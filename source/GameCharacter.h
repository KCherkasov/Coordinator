#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "LevelableObject.h"
#include "Faction.h"

class GameCharacter: public LevelableObject {
  public:
    GameCharacter(const size_t& own_id = FREE_ID, const size_t& level = START_LEVEL, const Faction& faction ): LevelableObject(own_id, level) { _faction = faction; }
    virtual ~GameCharacter() {}
    size_t get_health() const { return _health; }
    size_t get_faction(Faction& result) const { return _faction; }
    size_t get_stats(std::vector<size_t>& result) const;
    size_t get_stats(const size_t& index, size_t& result) const;
    virtual size_t get_power() const = 0;
    virtual size_t get_power(const size_t& target_archetype_id) const = 0;
    virtual size_t get_defense() const = 0;
    virtual size_t get_defense(const size_t& attacker_archetype_id) const = 0;
    size_t set_faction_id(const size_t& value);
    size_t set_health(const size_t& value);
    size_t set_stats(const std::vector<size_t>& value);
    size_t set_stats(const size_t& index, const size_t& value);
    size_t increase_health(const size_t& shift = 1);
    size_t decrease_health(const size_t& shift = 1);
  protected:
    Faction& _faction;
    size_t _health;
    std::vector<size_t> _stats;
};

#endif

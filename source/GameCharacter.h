#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "LevelableObject.h"

class GameCharacter: public LevelableObject {
  public:
    GameCharacter(const size_t& own_id = FREE_ID, const size_t& level = START_LEVEL, const size_t& faction_id = FREE_ID, ): LevelableObject(own_id, level) { _faction_id = faction_id; }
    virtual ~GameCharacter() {}
    size_t get_faction_id() { return _faction_id; }
    size_t get_stats(std::vector<size_t>& result);
    size_t get_stats(const size_t& index, size_t& result);
    size_t set_faction_id(const size_t& value);
    size_t set_stats(const std::vector<size_t>& value);
    size_t set_stats(const size_t& index, const size_t& value);
  protected:
    size_t _faction_id;
    std::vector<size_t> _stats;
};

#endif

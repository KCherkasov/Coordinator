#ifndef ENEMY_H
#define ENEMY_H

#include "GameCharacter.h"
#include "CharacterArchetype.h"

class Enemy: public GameCharacter {
  public:
    Enemy(const EnemyTemplate& data, const CharacterArchetype& archetype);
    virtual ~Enemy() {}
    size_t get_archetype_id() const { return _archetype.get_own_id(); }
    size_t get_loot_list(std::vector<LootData>& result) const;
    size_t get_loot_list(const size_t& index, LootData& result) const;
    size_t get_reward(std::vector<size_t>& result) const;
    size_t get_reward(const size_t& index, size_t& result) const;
    size_t get_power() const;
    size_t get_power(const size_t& target_archetype_id) const;
    size_t get_defense() const;
    size_t get_defense(const size_t& attacker_archetype_id) const;
    size_t get_save_data(EnemyTemplate& save_data) const;
    size_t set_loot_list(const std::vector<LootData>& value);
    size_t set_loot_list(const size_t& index, const LootData& value);
    size_t set_reward(const std::vector<size_t>& value);
    size_t set_reward(const size_t& index, const size_t& value);
    size_t what(std::string& result) const;
    size_t update();
  protected:
    CharacterArchetype& _archetype;
    std::vector<LootData> _loot_list;
    std::vector<size_t> _reward;
    static size_t _id;
};

#endif

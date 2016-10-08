#ifndef ENEMY_H
#define ENEMY_H

#include "GameCharacter.h"

struct LootData {
  LootData(const size_t& item_id = FREE_ID, const size_t& drop_chance = PERCENT_CAP, const size_t& max_quantity = 1): _item_id(item_id), _drop_chance(drop_chance), _max_quantity(max_quantity) {}
  size_t _item_id;
  size_t _drop_chance;
  size_t _max_quantity;

  LootData& operator == (const LootData& rhs) {
    _item_id = rhs._item_id;
    _drop_chance = rhs._drop_chance;
    _max_quantity = rhs._max_quantity;
    return *this;
  }

  friend bool operator == (const LootData& lhs, const LootData& rhs);
  friend bool operator < (const LootData& lhs, const LootData& rhs);
  friend bool operator > (const LootData& lhs, const LootData& rhs);
};

class Enemy: public GameCharacter {
  public:
    Enemy(const EnemyTemplate& data);
    virtual ~Enemy() {}
    size_t get_loot_list(std::vector<LootData>& result);
    size_t get_loot_list(const size_t& index, LootData& result);
    size_t get_reward(std::vector<size_t>& result);
    size_t get_reward(const size_t& index, size_t& result);
    size_t get_save_data(EnemyTemplate& save_data);
    size_t set_loot_list(const std::vector<LootData>& value);
    size_t set_loot_list(const size_t& index, const LootData& value);
    size_t set_reward(const std::vector<size_t>& value);
    size_t set_reward(const size_t& index, const size_t& value);
    size_t what(std::string& result);
    size_t update();
  protected:
    std::vector<LootData> _loot_list;
    std::vector<size_t> _reward;
    static size_t _id;
};

#endif

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
    Enemy();
    virtual ~Enemy() {}
  protected:
    std::vector<LootData> _loot_list;
    std::vector<size_t> _reward;
    static size_t _id;
};

#endif

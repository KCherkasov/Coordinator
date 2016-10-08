#include "Enemy.h"

size_t Enemy::_id = FREE_ID;

bool operator == (const LootData& lhs, const LootData& rhs) {
  if (lhs._item_id != rhs._item_id) {
    return false;
  }
  if (lhs._drop_chance != rhs._drop_chance) {
    return false;
  }
  if (lhs._max_quantity != rhs._max_quantity) {
    return false;
  }
  return true;
}

bool operator < (const LootData& lhs, const LootData& rhs) {
  return lhs._item_id < rhs._item_id;
}

bool operator > (const LootData& lhs, const LootData& rhs) {
  return lhs._item_id > rhs._item_id;
}



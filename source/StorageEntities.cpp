#include "StorageEntities.h"

bool operator == (const ItemTemplate& lhs, const ItemTemplate& rhs) {
  if (lhs._own_id != rhs._own_id) {
    return false;
  }
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._level != rhs._level) {
    return false;
  }
  if (lhs._owner_id != rhs._owner_id) {
    return false;
  }
  if (lhs._rarity != rhs._rarity) {
    return false;
  }
  if (lhs._kind != rhs._kind) {
    return false;
  }
  if (lhs._price != rhs._price) {
    return false;
  }
  if (lhs._bonuses != rhs._bonuses) {
    return false;
  }
  if (lhs._slots != rhs._slots) {
    return false;
  }
  return true;
}

bool operator < (const ItemTemplate& lhs, const ItemTemplate& rhs) {
  return lhs._price < rhs._price;
}

bool operator > (const ItemTemplate& lhs, const ItemTemplate& rhs) {
  return lhs._price > rhs._price;
}

bool operator == (const MercSpecTemplate& lhs, const MercSpecTemplate& rhs) {
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._base_merc_stats != rhs._base_merc_stats) {
    return false;
  }
  return true;
}


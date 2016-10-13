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

bool operator < (const MercSpecTemplate& lhs, const MercSpecTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const MercSpecTemplate& lhs, const MercSpecTemplate& rhs) {
  return lhs._own_id > rhs._own_id;
}

bool operator == (const EnemyTemplate& lhs, const EnemyTemplate& rhs) {
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._level != rhs._level) {
    return false;
  }
  if (lhs._faction_id != rhs._faction_id) {
    return false;
  }
  if (lhs._stats != rhs._stats) {
    return false;
  }
  if (lhs._loot_list != rhs._loot_list) {
    return false;
  }
  if (lhs._reward != rhs._reward) {
    return false;
  }
  return true;
}

bool operator < (const EnemyTemplate& lhs, const EnemyTemplate& rhs) {
  return lhs._level < rhs._level;
}

bool operator > (const EnemyTemplate& lhs, const EnemyTemplate& rhs) {
  return lhs._level > rhs._level;
}

bool operator == (const MercenaryTemplate& lhs, const MercenaryTemplate& rhs) {
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
  if (lhs._faction_id != rhs._faction_id) {
    return false;
  }
  if (lhs._stats != rhs._stats) {
    return false;
  }
  if (lhs._spec_id != rhs._spec_id) {
    return false;
  }
  if (lhs._experience != rhs._experience) {
    return false;
  }
  if (lhs._personality != rhs._personality) {
    return false;
  }
  if (lhs._history != rhs._history) {
    return false;
  }
  if (lhs._equipment != rhs._equipment) {
    return false;
  }
  return true;
}

bool operator < (const MercenaryTemplate& lhs, const MercenaryTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const MercenaryTemplate& lhs, const MercenaryTemplate& rhs) {
  return lhs._own_id > rhs._own_id;
}

bool operator == (const FactionTemplate& lhs, const FactionTemplate& rhs) {
  if (lhs._own_id != rhs._own_id) {
    return false;
  }
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._influence != rhs._influence) {
    return false;
  }
  if (lhs._relationship != rhs._relationship) {
    return false;
  }
  return true;
}

bool operator < (const FactionTemplate& lhs, const FactionTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const FactionTemplate& lhs, const FactionTemplate& rhs) {
  return lhs._own_id > rhs._own_id;
}


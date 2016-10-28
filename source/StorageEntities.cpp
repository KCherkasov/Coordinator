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

bool operator == (const CharacterArchetypeTemplate& lhs, const CharacterArchetypeTemplate& rhs) {
  if (lhs._own_id != rhs._own_id) {
    return false;
  }
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._power_mods != rhs._power_mods) {
    return false;
  }
  if (lhs._defense_mods != rhs._defense_mods) {
    return false;
  }
  return true;
}

bool operator < (const CharacterArchetypeTemplate& lhs, const CharacterArchetypeTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const CharacterArchetypeTemplate& lhs, const CharacterArchetypeTemplate& rhs) {
  return lhs._own_id > rhs._own_id;
}

bool operator == (const HeroClassTemplate& lhs, const HeroClassTemplate& rhs) {
  if (lhs._own_id != rhs._own_id) {
    return false;
  }
  if (lhs._archetype_id != rhs._archetype_id) {
    return false;
  }
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._stat_bonuses != rhs._stat_bonuses) {
    return false;
  }
  if (lhs._att_power_modifiers != rhs._att_power_modifiers) {
    return false;
  }
  if (lhs._defense_modifiers != rhs._defense_modifiers) {
    return false;
  }
  return true;
}

bool operator < (const HeroClassTemplate& lhs, const HeroClassTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const HeroClassTemplate& lhs, const HeroClassTemplate& rhs) {
  return lhs._own_id > rhs._own_id;
}

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
  if (lhs._health != rhs._health) {
    return false;
  }
  if (lhs._stats != rhs._stats) {
    return false;
  }
  if (lhs._archetype_id != rhs._archetype_id) {
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

bool operator == (const HeroTemplate& lhs, const HeroTemplate& rhs) {
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
  if (lhs._health != rhs._health) {
    return false;
  }
  if (lhs._stats != rhs._stats) {
    return false;
  }
  if (lhs._class_id != rhs._class_id) {
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

bool operator < (const HeroTemplate& lhs, const HeroTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const HeroTemplate& lhs, const HeroTemplate& rhs) {
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

bool operator == (const QuestTemplate& lhs, const QuestTemplate& rhs) {
  if (lhs._own_id != rhs._own_id) {
    return false;
  }
  if (lhs._name != rhs._name) {
    return false;
  }
  if (lhs._description != rhs._description) {
    return false;
  }
  if (lhs._location_id != rhs._location_id) {
    return false;
  }
  if (lhs._level != rhs._level) {
    return false;
  }
  if (lhs._employer_faction != rhs._employer_faction) {
    return false;
  }
  if (lhs._target_faction != rhs._target_faction) {
    return false;
  }
  if (lhs._life_time != rhs._life_time) {
    return false;
  }
  if (lhs._birth_time != rhs._birth_time) {
    return false;
  }
  if (lhs._phase != rhs._phase) {
    return false;
  }
  if (lhs._rewards != rhs._rewards) {
    return false;
  }
  if (lhs._bonuses != rhs._bonuses) {
    return false;
  }
  if (lhs._heroes != rhs._heroes) {
    return false;
  }
  if (lhs._enemies != rhs._enemies) {
    return false;
  }
  return true;
}

bool operator < (const QuestTemplate& lhs, const QuestTemplate& rhs) {
  return lhs._own_id < rhs._own_id;
}

bool operator > (const QuestTemplate& lhs, const QuestTemplate& rhs) {
  return lhs._own_id > rhs._own_id;
}

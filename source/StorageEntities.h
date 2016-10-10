#ifndef STORAGE_ENTITIES_H
#define STORAGE_ENTITIES_H

#include "Miscellaneous.h"

struct ItemTemplate {
  size_t _own_id;
  std::string _name;
  std::string _description;
  size_t _level;
  size_t _owner_id;
  size_t _rarity;
  size_t _kind;
  size_t _price;
  std::vector<size_t> _bonuses;
  std::vector<bool> _slots;

  ItemTemplate& operator = (const ItemTemplate& rhs) {
    _own_id = rhs._own_id;
    if (!_name.empty()) {
      _name.clear();
    }
    _name = rhs._name;
    if (!_description.empty()) {
      _description = rhs._description;
    }
    _level = rhs._level;
    _owner_id = rhs._owner_id;
    _rarity = rhs._rarity;
    _kind = rhs._kind;
    _price = rhs._price;
    if (!_bonuses.empty()) {
      _bonuses.clear();
    }
    _bonuses = rhs._bonuses;
    if (!_slots.empty()) {
      _slots.clear();
    }
    _slots = rhs._slots;
    return *this;
  }
  friend bool operator == (const ItemTemplate& lhs, const ItemTemplate& rhs);
  friend bool operator < (const ItemTemplate& lhs, const ItemTemplate& rhs);
  friend bool operator > (const ItemTemplate& lhs, const ItemTemplate& rhs);
};

struct InventoryTemplate {
  std::vector<ItemTemplate> _equipment;

  InventoryTemplate& operator = (const InventoryTemplate& rhs) {
    _equipment.clear();
    _equipment = rhs._equipment;
    return *this;
  }
};

struct MercSpecTemplate {
  std::string _name;
  std::string _description;
  std::vector<size_t> _base_merc_stats;

  MercSpecTemplate& operator = (const MercSpecTemplate& rhs) {
    if (!_name.empty()) {
      _name.clear();
    }
    _name = rhs._name;
    if (!_description.empty()) {
      _description.clear();
    }
    _description = rhs._description;
    if (!_base_merc_stats.empty()) {
      _base_merc_stats.clear();
    }
    _base_merc_stats = rhs._base_merc_stats;
    return *this;
  }

  friend bool operator == (const MercSpecTemplate& lhs, const MercSpecTemplate& rhs);
};

struct EnemyTemplate {
  std::string _name;
  std::string _description;
  size_t _level;
  std::vector<size_t> _stats;
  std::vector<LootData> _loot_list;
  std::vector<size_t> _reward;

  EnemyTemplate& operator = (const EnemyTemplate& rhs) {
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _level = rhs._level;
    _stats.clear();
    _stats = rhs._stats;
    _loot_list.clear();
    _loot_list = rhs._loot_list;
    _reward.clear();
    _reward = rhs._reward;
    return *this;
  }
};

struct MercenaryTemplate {
  size_t _own_id;
  std::string _name;
  std::string _description;
  size_t _level;
  std::vector<size_t> _stats;
  size_t _spec_id;
  std::vector<size_t> _experience;
  std::vector<size_t> _personality;
  InventoryTemplate _equipment;

  MercenaryTemplate& operator = (const MercenaryTemplate& rhs) {
    _own_id = rhs._own_id;
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _level = rhs._level;
    _stats.clear();
    _stats = rhs._stats;
    _spec_id = rhs._spec_id;
    _experience.clear();
    _experience = rhs._experience;
    _personality.clear();
    _personality = rhs._personality;
    _equipment = rhs._equipment;
    return *this;
  }
};

#endif

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
};

#endif

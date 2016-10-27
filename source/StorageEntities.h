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

struct CharacterArchetypeTemplate {
  size_t _own_id;
  std::string _name;
  std::string _description;
  std::vector<size_t> _power_mods;

  CharacterArchetypeTemplate& operator = (const CharacterArchetypeTemplate& rhs) {
    _own_id = rhs._own_id;
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _power_mods.clear();
    _power_mods = rhs._power_mods;
    return *this;
  }

  friend bool operator == (const CharacterArchetypeTemplate& lhs, const CharacterArchetypeTemplate& rhs);
  friend bool operator < (const CharacterArchetypeTemplate& lhs, const CharacterArchetypeTemplate& rhs);
  friend bool operator > (const CharacterArchetypeTemplate& lhs, const CharacterArchetypeTemplate& rhs);
};

struct HeroClassTemplate {
  size_t _own_id;
  size_t _archetype_id;
  std::string _name;
  std::string _description;
  std::vector<size_t> _stat_bonuses;
  std::vector<size_t> _att_power_modifiers;
  std::vector<size_t> _defense_modifiers;

  HeroClassTemplate& operator = (const HeroClassTemplate& rhs) {
    _own_id = rhs._own_id;
    _archetype_id = rhs._archetype_id;
    if (!_name.empty()) {
      _name.clear();
    }
    _name = rhs._name;
    if (!_description.empty()) {
      _description.clear();
    }
    _description = rhs._description;
    if (!_stat_bonuses.empty()) {
      _stat_bonuses.clear();
    }
    _stat_bonuses = rhs._stat_bonuses;
    if (!_att_power_modifiers.empty()) {
      _att_power_modifiers.clear();
    }
    _att_power_modifiers.clear();
    if (!_defence_modifiers.empty()) {
      _defense_modifiers.clear();
    }
    _defense_modifiers = rhs._defense_modifiers;
    return *this;
  }

  friend bool operator == (const HeroClassTemplate& lhs, const HeroClassTemplate& rhs);
  friend bool operator < (const HeroClassTemplate& lhs, const HeroClassTemplate& rhs);
  friend bool operator > (const HeroClassTemplate& lhs, const HeroClassTemplate& rhs);
};

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

struct EnemyTemplate {
  std::string _name;
  std::string _description;
  size_t _level;
  size_t _faction_id;
  std::vector<size_t> _stats;
  size_t _archetype_id;
  std::vector<LootData> _loot_list;
  std::vector<size_t> _reward;

  EnemyTemplate& operator = (const EnemyTemplate& rhs) {
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _level = rhs._level;
    _faction_id = rhs._faction_id;
    _stats.clear();
    _stats = rhs._stats;
    _archetype_id = rhs._archetype_id;
    _loot_list.clear();
    _loot_list = rhs._loot_list;
    _reward.clear();
    _reward = rhs._reward;
    return *this;
  }

  friend bool operator == (const EnemyTemplate& lhs, const EnemyTemplate& rhs);
  friend bool operator < (const EnemyTemplate& lhs, const EnemyTemplate& rhs);
  friend bool operator > (const EnemyTemplate& lhs, const EnemyTemplate& rhs);
};

struct HeroTemplate {
  size_t _own_id;
  std::string _name;
  std::string _description;
  size_t _level;
  size_t _faction_id;
  std::vector<size_t> _stats;
  size_t _class_id;
  std::vector<size_t> _experience;
  std::vector<size_t> _personality;
  std::vector<size_t> _history;
  InventoryTemplate _equipment;

  HeroTemplate& operator = (const HeroTemplate& rhs) {
    _own_id = rhs._own_id;
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _level = rhs._level;
    _faction_id = rhs._faction_id;
    _stats.clear();
    _stats = rhs._stats;
    _class_id = rhs._class_id;
    _experience.clear();
    _experience = rhs._experience;
    _personality.clear();
    _personality = rhs._personality;
    _history.clear();
    _history = rhs._history;
    _equipment = rhs._equipment;
    return *this;
  }

  friend bool operator == (const HeroTemplate& lhs, const HeroTemplate& rhs);
  friend bool operator < (const HeroTemplate& lhs, const HeroTemplate& rhs);
  friend bool operator > (const HeroTemplate& lhs, const HeroTemplate& rhs);
};

struct FactionTemplate {
  size_t _own_id;
  std::string _name;
  std::string _description;
  size_t _influence;
  size_t _relationship;

  FactionTemplate& operator = (const FactionTemplate& rhs) {
    _own_id = rhs._own_id;
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _influence = rhs._influence;
    _relationship = rhs._relationship;
    return *this;
  }

  friend bool operator == (const FactionTemplate& lhs, const FactionTemplate& rhs);
  friend bool operator < (const FactionTemplate& lhs, const FactionTemplate& rhs);
  friend bool operator > (const FactionTemplate& lhs, const FactionTemplate& rhs);
};

struct QuestTemplate {
  size_t _own_id;
  std::string _name;
  std::string _description;
  size_t _level;
  size_t _location_id;
  size_t _employer_faction;
  size_t _target_faction;
  size_t _life_time;
  size_t _birth_time;
  size_t _phase;
  std::vector<size_t> _rewards;
  std::vector<size_t> _bonuses;
  std::vector<size_t> _heroes;
  std::vector<EnemyTemplate> _enemies;

  QuestTemplate& operator = (const QuestTemplate& rhs) {
    _own_id = rhs._own_id;
    _name.clear();
    _name = rhs._name;
    _description.clear();
    _description = rhs._description;
    _location_id = rhs._location_id;
    _level = rhs._level;
    _employer_faction = rhs._employer_faction;
    _target_faction = rhs._target_faction;
    _life_time = rhs._life_time;
    _birth_time = rhs._birth_time;
    _phase = rhs._phase;
    _rewards.clear();
    _rewards = rhs._rewards;
    _bonuses.clear();
    _bonuses = rhs._bonuses;
    _heroes.clear();
    _heroes = rhs._heroes;
    _enemies.clear();
    _enemies = rhs._enemies;
    return *this;
  }

  friend bool operator == (const QuestTemplate& lhs, const QuestTemplate& rhs);
  friend bool operator < (const QuestTemplate& lhs, const QuestTemplate& rhs);
  friend bool operator > (const QuestTemplate& lhs, const QuestTemplate& rhs);
};

#endif

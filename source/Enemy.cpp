#include "Enemy.h"

size_t Enemy::_id = FREE_ID;

Enemy::Enemy(const EnemyTemplate& data, const CharacterArchetype& archetype): _own_id(data._own_id), _name(data._name), _description(data._description), _level(data._level), _faction(faction), _health(data._health), _stats(data._stats), _archetype(archetype), _loot_list(data._loot_list), _reward(data._reward) {
  if (_own_id == FREE_INDEX) {
    _own_id = ++_id;
  } else {
    if (_id < _own_id) {
      _id = _own_id;
    }
  }
}

size_t Enemy::get_loot_list(std::vector<LootData>& result) const {
  result.clear();
  result = _loot_list;
  return RC_OK;
}

size_t Enemy::get_loot_list(const size_t& index, LootData& result) const {
  if (index < _loot_list.size()) {
    result = _loot_list[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Enemy::get_reward(std::vector<size_t>& result) const {
  result.clear();
  result = _reward;
  return RC_OK;
}

size_t Enemy::get_reward(const size_t& index, size_t& result) const {
  if (index < _reward.size()) {
    result = _reward[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Enemy::get_power() {
  size_t power = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _stats.size(); ++i) {
    size_t archetype_mod;
    _archetype.get_power_mods(i, archetype_mod);
    power += (_stats[i] * archetype_mod / PERCENT_CAP);
  }
  return power;
}

size_t Enemy::get_power(const size_t& target_archetype_id) {
  size_t power = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _stats.size(); ++i) {
    size_t archetype_mod;
    _archetype.get_power_mods(i, archetype_mod);
    power += (_stats[i] * archetype_mod / PERCENT_CAP);
  }
  return power;
}

size_t Enemy::get_defense() {
  size_t defense = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _stats.size(); ++i) {
    size_t archetype_mod;
    _archetype.get_defense_mods(i, archetype_mod);
    power += (_stats[i] * archetype_mod / PERCENT_CAP);
  }
  return defense;
}

size_t Enemy::get_defense(const size_t& attacker_archetype_id) {
  size_t defense = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _stats.size(); ++i) {
    size_t archetype_mod;
    _archetype.get_defense_mods(i, archetype_mod);
    power += (_stats[i] * archetype_mod / PERCENT_CAP);
  }
  return defense;
}

size_t Enemy::get_save_data(EnemyTemplate& save_data) const {
  save_data._name.clear();
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
  _faction.get_own_id(save_data._faction_id);
  save_data._health = _health;
  save_data._stats.clear();
  save_data._stats = _stats;
  save_data._loot_list.clear();
  save_data._loot_list = _loot_list;
  save_data._reward.clear();
  save_data._reward = _reward;
  return RC_OK;
}

size_t Enemy::set_loot_list(const std::vector<LootData>& value) {
  _loot_list.clear();
  _loot_list = value;
  return RC_OK;
}

size_t Enemy::set_loot_list(const size_t& index, const LootData& value) {
  if (index < _loot_list.size()) {
    _loot_list[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Enemy::set_reward(const std::vector<size_t>& value) {
  _reward.clear();
  _reward = value;
  return RC_OK;
}

size_t Enemy::set_reward(const size_t& index, const size_t& value) {
  if () {
    _reward[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Enemy::what(std::string& result) const {
  result.clear();
  return RC_OK;
}

size_t Enemy::short_what(std::string& result) const {
  result.clear();
  return RC_OK;
}

size_t Enemy::update() {
  return RC_OK;
}

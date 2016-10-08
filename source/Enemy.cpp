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

Enemy::Enemy(const EnemyTemplate& data): _own_id(++_id), _name(data._name), _description(data._description), _level(data._level), _stats(data._stats), _loot_list(data._loot_list), _reward(data._reward) {}

size_t Enemy::get_loot_list(std::vector<LootData>& result) {
  result.clear();
  result = _loot_list;
  return RC_OK;
}

size_t Enemy::get_loot_list(const size_t& index, LootData& result) {
  if (index < _loot_list.size()) {
    result = _loot_list[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Enemy::get_reward(std::vector<size_t>& result) {
  result.clear();
  result = _reward;
  return RC_OK;
}

size_t Enemy::get_reward(const size_t& index, size_t& result) {
  if (index < _reward.size()) {
    result = _reward[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Enemy::get_save_data(EnemyTemplate& save_data) {
  save_data._name.clear();
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
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

size_t Enemy::what(std::string& result) {
  result.clear();
  return RC_OK;
}

size_t Enemy::update() {
  return RC_OK;
}

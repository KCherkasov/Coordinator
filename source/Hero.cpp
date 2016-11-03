#include "Hero.h"
#include "Contract.h"

size_t Hero::_id = SIZE_T_DEFAULT_VALUE;

Hero::Hero(const HeroTemplate& data, HeroClass& hero_class, Faction& faction): _own_id(data._own_id), _name(data._name), _description(data._description), _level(START_LEVEL), _faction(faction), _hero(data._health), _stats(data._stats), _class(hero_class), _experience(data._experience), _personality(data._personality), _history(data._history), _equipment(data._equipment) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_id > _own_id) {
      _id = _own_id;
    }
  }
  if (data._level > _level) {
    _level = data._level;
  }
}

Hero::~Hero() {
  for (size_t i = 0; i < _contracts.size(); ++i) {
    if (_contracts[i] != NULL) {
      _contracts[i]->remove_merc(this);
    }
  }
}

size_t Hero::level_up() {
  size_t stat_points = POINTS_PER_LEVEL;
  while (true) {
    size_t stat_id = roll_dice(_stats.size());
    ++_stats[stat_id];
    --stat_points;
    if (stat_points == 0) {
      break;
    }
  }
  return RC_OK;
}

size_t Hero::get_class(HeroClass& result) const {
  result = _class;
  return RC_OK;
}

size_t Hero::get_experience(std::vector<size_t>& result) const {
  result.clear();
  result = _experience;
  return RC_OK;
}

size_t Hero::get_experience(const size_t& index, size_t& result) const  {
  if (index < _experience.size()) {
    result = _experience[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::get_personality(std::vector<size_t>& result) const {
  result.clear();
  result = _personality;
  return RC_OK;
}

size_t Hero::get_personality(const size_t& index, size_t& result) const {
  if (index < _personality.size()) {
    result = _personality[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::get_history(std::vector<size_t>& result) const {
  result.clear();
  result = _history;
  return RC_OK;
}

size_t Hero::get_history(const size_t& index, size_t& result) const {
  if (index < _history.size()) {
    result = _history[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::get_equipment(Inventory& result) const {
  result = _equipment;
  return RC_OK;
}

size_t Hero::get_power() const {
  size_t power = SIZE_T_DEFAULT_VALUE;
  size_t limit;
  if (_stats.size() > SI_DEFENSE) {
    limit = SI_DEFENSE;
  } else {
    limit = _stats.size();
  }
  for (size_t i = 0; i < limit; ++i) {
    size_t modifier;
    size_t class_bonus;
    size_t items_bonus;
    _class.get_power_mods(i, modifier);
    _class.get_stat_bonuses(i, class_bonus);
    _equipment.get_bonuses(i, items_bonus);
    power += ((_stats[i] + class_bonus + items_bonus) * modifier / PERCENT_CAP);
  }
  return power;
}

size_t Hero::get_power(const size_t& target_archetype_id) const {
  size_t power = SIZE_T_DEFAULT_VALUE;
  size_t limit;
  if (_stats.size() > SI_DEFENSE) {
    limit = SI_DEFENSE;
  } else {
    limit = _stats.size();
  }
  for (size_t i = 0; i < limit; ++i) {
    size_t modifier;
    size_t class_bonus;
    size_t items_bonus;
    _class.get_power_mods(i, modifier);
    _class.get_stat_bonuses(i, class_bonus);
    _equipment.get_bonuses(i, items_bonus);
    power += ((_stats[i] + class_bonus + items_bonus) * modifier / PERCENT_CAP);
  }
  size_t power_mod;
  _class.get_att_power_modifiers(target_archetype_id, power_mod);
  power = power * power_mod / PERCENT_CAP;
  return power;
}

size_t Hero::get_defense() const {
  size_t defense = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _stats.size(); ++i) {
    size_t modifier;
    size_t class_bonus;
    size_t items_bonus;
    _class.get_defense_mods(i, modifier);
    _class.get_stat_bonuses(i, class_bonus);
    _equipment.get_bonuses(i, items_bonus);
    defense += ((_stats[i] + class_bonus + items_bonus) * modifier / PERCENT_CAP);
  }
  return defense;
}

size_t Hero::get_defense(const size_t& attacker_archetype_id) const {
  size_t defense = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _stats.size(); ++i) {
    size_t modifier;
    size_t class_bonus;
    size_t items_bonus;
    _class.get_defense_mods(i, modifier);
    _class.get_stat_bonuses(i, class_bonus);
    _equipment.get_bonuses(i, items_bonus);
    defense += ((_stats[i] + class_bonus + items_bonus) * modifier / PERCENT_CAP);
  }
  size_t defense_mod;
  _class.get_defense_modifiers(attacker_archetype_id, defense_mod);
  defense = defense * defense_mod / PERCENT_CAP;
  return defense;
}

size_t Hero::get_save_data(MercenaryTemplate& save_data) const {
  save_data._own_id = _own_id;
  save_data._name.clear()
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
  save_data._faction_id = _faction_id;
  save_data._health = _health;
  save_data._stats.clear();
  save_data._stats = _stats;
  save_data._class_id = _class.get_own_id();
  save_data._experience.clear();
  save_data._experience = _experience;
  save_data._personality.clear/();
  save_data._personality = _personality;
  save_data._history.clear();
  save_data._history = _history;
  _equipment.get_save_data(save_data._equipment);
  return RC_OK;
}

size_t Hero::set_class(Hero& value) {
  _class = value;
  return RC_OK;
}

size_t Hero::set_experience(const std::vector<size_t>& value) {
  if (value.empty) {
    return RC_BAD_INPUT;
  }
  _experience.clear();
  _experience = value;
  return RC_OK;
}

size_t Hero::set_experience(const size_t& index, const size_t& value) {
  if (index < _experience.size()) {
    _experience[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::set_personality(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _personality.clear();
  _personality = value;
  return RC_OK;
}

size_t Hero::set_personality(const size_t& index, const size_t& value) {
  if (index < _personality.size()) {
    _personality[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::set_history(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _history.clear();
  _history = value;
  return RC_OK;
}

size_t Hero::set_history(const size_t& index, const size_t& value) {
  if (index < _history.size()) {
    _history[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::what(std::string& result) const {
  result.clear();
  result += _name;
  result.append("        ");
  std::string buffer;
  buffer.clear();
  _class.short_what(buffer);
  result += buffer;
  buffer.clear();
  result.append("\n\n");
  convert_to_string(_level, buffer);
  result += buffer;
  buffer.clear();
  result.append(" Level (");
  convert_to_string(_experience[0], buffer);
  result += buffer;
  buffer.clear();
  result.append(" / ");
  convert_to_string(_experience[1], buffer);
  result += buffer;
  buffer.clear();
  result.append(" Exp)\nFaction: ");
  _faction.get_name(buffer);
  result += buffer;
  buffer.clear();
  result.append("\n\nStats:\n");
  std::vector<size_t> equipment_bonuses;
  _equipment.get_bonuses(equipment_bonuses);
  for (size_t i = 0; i < _stats.size(); ++i) {
    _dictionary->get_stat_name(i, buffer);
    result.append(": ");
    buffer.clear();
    convert_to_string(_stats[i] + equipment_bonuses[i], buffer);
    result += buffer;
    buffer.clear();
    result.append(" (");
    convert_to_string(_stats[i], buffer);
    result += buffer;
    buffer.clear();
    convert_to_string(equipment_bonuses[i], buffer);
    result.append(" + ");
    result += buffer;
    buffer.clear();
    result.append(")\n");
  }
  result.apppend("History:\n");
  for (size_t i = 0; i < _history.size(); ++i) {
    _dictionary->get_hero_history_name(i, buffer);
    result.append(": ");
    buffer.clear();
    convert_to_string(_history[i], buffer);
    result += buffer;
    buffer.clear();
    result.append("\n");
  }
  return RC_OK;
}

size_t Hero::short_what(std::string& result) const {
  result.clear();
  result += _name;
  result.append(" ");
  std::string buffer;
  convert_to_string(_level, buffer);
  result += buffer;
  buffer.clear();
  result.append(" level ");
  _class.get_name(buffer);
  result += buffer;
  buffer.clear();
  result.append("\nFaction: ");
  _faction.get_name(buffer);
  result += buffer;
  result.append("\n");
  buffer.clear();
  return RC_OK;
}

size_t Hero::update() {
  while (_experience[0] >= _experience[1]) {
    level_up();
  }
  if (_health == CH_DEAD) {
    // some code here to send suicide message
  }
  if (_quest == NULL) {
    // some code here to process idle activity
  }
  return RC_OK;
}

size_t Hero::add_history(const size_t& index, const size_t& amount) {
  if (index < _history.size()) {
    _history[index] += amount;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Hero::add_experience(const size_t& amount) {
  _experience[0] += amount;
  level_up();
  return RC_OK;
}

size_t Hero::add_quest(Quest* to_add) {
  if (_quest != NULL) {
    return RC_ALREADY_BUSY;
  }
  if (to_add = NULL) {
    return RC_BAD_INPUT;
  }
  _quest = to_add;
  return RC_OK;
}

size_t Hero::remove_quest() {
  if (_quest != NULL) {
    _quest->remove_hero(this);
  }
  _quest = NULL;
  return RC_OK;
}


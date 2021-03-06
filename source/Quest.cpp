#include "Quest.h"
#include "Hero.h"

size_t Quest::_id = SIZE_T_DEFAULT_VALUE;

Quest::Quest(QuestTemplate& data, Location& location, Faction& employer, Faction& target): _own_id(data._own_id), _name(data._name), _description(data._description), _to_delete(false), _level(data._level), _employer_faction(employer), _target_faction(target), _phase(data._phase), _life_time(data._life_time), _rewards(data._rewards), _bonuses(data._bonuses) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_own_id > _id) {
      _id = _own_id;
    }
  }
  for (size_t i = 0; i < data._mercs.size(); ++i) {
    Hero* new_hero = NULL;
    // some code here to get reference by merc's _own_id
    _heroes.push_back(new_hero);
    new_hero = NULL;
  }
  for (size_t i = 0; i < data._enemies.size(); ++i) {
    Enemy* new_enemy = new Enemy(data._enemies[i]);
    _enemies.push_back(new_enemy);
    new_enemy = NULL;
  }
}

Quest::~Quest() {
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      _heroes[i]->remove_contract(this);
    }
  }
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (_enemies[i] != NULL) {
      delete _enemies[i];
    }
  }
}

size_t Quest::remove_loot(const size_t& index) {
  if (index < _loot.size()) {
    _loot.erase(_loot.begin() + index);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::count_fees() {
  srand(static_cast<size_t>(time(0)));
  size_t fees = SIZE_T_DEFAULT_VALUE;
  while (_damage > SIZE_T_DEFAULT_VALUE) {
    size_t index = rand() % LO_SIZE;
    size_t cost = std::max(1, index * DAMAGE_COST_PER_SIZE);
    if (_damage >= cost) {
      _damage -= cost;
      LocationObject object;
      _location.get_fees(index, object);
      fees += object._price;
    }
  }
  return fees;
}

size_t Quest::give_reward(QuestReward& reward, const bool& with_rep_dmg) {
  srand(static_cast<size_t>(time(0)));
  size_t experience_grant = _rewards[RI_EXPERIENCE];
  size_t money_grant = _rewards[RI_MONEY];
  for (size_t i = 0; i < _level; ++i) {
    experience_grant *= EXP_RAISE_PER_LEVEL;
    experience_grant /= PERCENT_CAP;
    money_grant *= MONEY_RAISE_PER_LEVEL;
    money_grant /= PERCENT_CAP;
  }
  if (rand() % PERCENT_CAP < PERCENT_CAP / 2) {
    size_t money_bonuses = _bonuses[RI_MONEY];
    size_t exp_bonuses = _bonuses[RI_EXPERIENCE];
    for (size_t i = 0; i < _level; ++i) {
      money_bonuses *= MONEY_RAISE_PER_LEVEL;
      money_bonuses /= PERCENT_CAP;
      exp_bonuses *= EXP_RAISE_PER_LEVEL;
      exp_bonuses /= PERCENT_CAP;
    }
    money_grant += money_bonuses;
    experience_grant = exp_bonuses;
  }
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      size_t bonus_exp = experience_grant * roll_dice() / PERCENT_CAP;
      _heroes[i]->add_experience(RI_EXPERIENCE, bonus_exp + experience_grant);
      _heroes[i]->add_history(HH_QUESTS_COMPLETED);
    }
  }
  reward._level;
  reward._cash = money_grant;
  reward._fees = count_fees();
  reward._experience = experience_grant;
  reward._loot.clear();
  reward._loot = _loot;
  return RC_OK;
}

size_t Quest::get_location(Location& result) {
  result = _location;
  return RC_OK;
}

size_t Quest::get_rewards(std::vector<size_t>& result) const {
  result.clear();
  result = _rewards;
  return RC_OK;
}

size_t Quest::get_rewards(const size_t& index, size_t& result) const {
  if (index < _rewards.size()) {
    result = _rewards[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_bonuses(std::vector<size_t>& result) const {
  result.clear();
  result = _bonuses;
  return RC_OK;
}

size_t Quest::get_bonuses(const size_t& index, size_t& result) const {
  if (index < _bonuses.size()) {
    result = _bonuses[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_heroes(std::vector<Hero*>& result) const {
  if (!result.empty()) {
    return RC_BAD_INPUT;
  } else {
    result = _heroes;
    return RC_OK;
  }
}

size_t Quest::get_heroes(const size_t& index, Hero*& result) const {
  if (index < _heroes.size()) {
    if (result == NULL) {
      result = _heroes[index];
      return RC_OK;
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_enemies(std::vector<Enemy*>& result) const {
  if (!result.empty()) {
    return RC_BAD_INPUT;
  } else {
    result = _enemies;
    return RC_OK;
  }
}

size_t Quest::get_enemies(const size_t& index, Enemy*& result) const {
  if (index < _enemies.size()) {
    if (result == NULL) {
      result = _enemies[index];
      return RC_OK;
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_save_data(QuestTemplate& save_data) const {
  save_data._own_id = _own_id;
  save_data._name.clear();
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
  save_data._location_id = _location.get_own_id();
  _employer_faction.get_own_id(save_data._employer_faction);
  _target_faction.get_own_id(save_data._target_faction);
  save_data._phase = _phase;
  save_data._life_time;
  save_data._rewards.clear();
  save_data._rewards = _rewards;
  save_data._bonuses = _bonuses;
  save_data._heroes.clear();
  for (size_t i = 0; i < _heroes.size()) {
    if (_heroes[i] != NULL) {
      save_data._heroes.push_back(_heroes[i]->get_own_id());
    }
  }
  save_data._enemies.clear();
  for(size_t i = 0; i < _enemies.size()) {
    if (_enemies[i] = NULL) {
      EnemyTemplate to_add;
      _enemies[i]->get_save_data(to_add);
      save_data._enemies.push_back(to_add);
    }
  }
  save_data._loot.clear();
  save_data._loot = _loot;
  return RC_OK;
}

size_t Quest::set_location(Location& value) {
  _location = value;
  return RC_OK;
}

size_t Quest::set_employer_faction(const size_t& value) {
  _employer_faction = value;
  return RC_OK;
}

size_t Quest::set_target_faction(const size_t& value) {
  _target_faction = value;
  return RC_OK;
}

size_t Quest::set_rewards(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _rewards.clear();
  _rewards = value;
  return RC_OK;
}

size_t Quest::set_rewards(const size_t& index, const size_t& value) {
  if (index < _rewards.size()) {
    _rewards[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::set_bonuses(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _bonuses.clear();
  _bonuses = value;
  return RC_OK;
}

size_t Quest::set_bonuses(const size_t& index, const size_t& value) {
  if (index < _bonuses.size()) {
    _bonuses[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::set_heroes(const std::vector<Hero*>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _heroes.clear();
  _heroes = value;
  return RC_OK;
}

size_t Quest::set_heroes(const size_t& index, const Hero*& value) {
  if (index < _heroes.size()) {
    if (value == NULL) {
      return RC_BAD_INPUT;
    }
    _heroes[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::set_enemies(const std::vector<Enemy*>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (_enemies[i] != NULL) {
      delete _enemies[i];
    }
  }
  _enemies.clear();
  _enemies = value;
  return RC_OK;
}

size_t Quest::set_enemies(const size_t& index, const Enemy*& value) {
  if (index < _enemies.size()) {
    if (value == NULL) {
      return RC_BAD_INPUT;
    }
    if (_enemies[index] != NULL) {
      delete _enemies[index];
    }
    _enemies[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::what(std::string& result) {
  result.clear();

  return RC_OK;
}

size_t Quest::update() {
  ++_life_time;
  // code here to simulate battle
  
  size_t j = SIZE_T_DEFAULT_VALUE;
  while (!_enemies.empty() && j < _enemies.size()) {
    if (_enemies[j] != NULL) {
      _enemies[j]->update();
      if (_enemies[j]->to_delete()) {
        // code to give the rewards for kill ? shall we give it to a whole party, and if not, how shall we determine the one who has killed the monster ?
        delete _enemies[j];
        _enemies.erase(_enemies.begin() +j);
      } else {
        ++j;
      }
    } else {
      _enemies.erase(_enemies.begin() + j);
    }
  }
  if (_life_time >= QUEST_LIFE_TIME && (_phase == QP_PENDING || _phase == QP_RECRUITING)) {
    _phase = QP_EXPIRED;
    _to_delete = true;
  }
  if (_phase == QP_IN_PROGRESS && _heroes.empty()) {
    _phase = QP_FAILED;
    _to_delete = true;
  }
  if (_phase == QP_IN_PROGRESS && _enemies.empty()) {
    size_t chance = roll_dice();
    _to_delete = true;
    // maybe chances shall be tweaked or determined algorithm needed
    if (chance % 2 == 0) {
      _phase = QP_SUCCESS_TOTAL;
    } else {
      _phase = QP_SUCCESS_REL_DMG;
    }
  }
  if (_phase == QP_SUCCESS_TOTAL) {
    // code here to process success without relationship damage
    _employer_faction.increase_relationship(REPUTATION_PER_QUEST);
    _employer_faction.increase_influence();
    _target_faction.decrease_influence();
  }
  if (_phase == QP_SUCCESS_REL_DMG) {
    // code here to process success with relationship damage
    _employer_faction.increase_relationship(REPUTATION_PER_QUEST);
    _employer_faction.increase_influence();
    _target_faction.decrease_relationship(REPUTATION_PER_QUEST);
    _target_faction.decrease_influence();
  }
  if (_phase == QP_FAILED) {
    // code here to process fail
    _employer_faction.decrease_relationship(REPUTATION_PER_QUEST / 2);
    _target_faction.decrease_relationship(REPUTATION_PER_QUEST);
    _rewards[RI_MONEY] = SIZE_T_DEFAULT_VALUE;
    _rewards[RI_EXPERIENCE] = SIZE_T_DEFAULT_VALUE;
    _bonuses[RI_MONEY] = SIZE_T_DEFAULT_VALUE;
    _bonuses[RI_EXPERIENCE] = SIZE_T_DEFAULT_VALUE;
    _loot.clear();
  }
  if (_phase > QP_IN_PROGRESS) {
    _to_delete = true;
  }
  return RC_OK;
}

size_t Quest::increase_phase(const size_t& shift) {
  _phase = (_phase + shift) % QP_SIZE;
  return RC_OK;
}

size_t Quest::decrease_phase(const size_t& shift) {
  _phase = (_phase - shift) % QP_SIZE;
  return RC_OK;
}

size_t Quest::add_hero(const Hero*& new_hero) {
  if (new_hero == NULL) {
    return RC_BAD_INPUT;
  }
  _heroes.push_back(new_hero);
  return RC_OK;
}

size_t Quest::remove_hero(const size_t& index) {
  if (index < _heroes.size()) {
    _heroes.erase(_heroes.begin() + index);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::remove_hero(Hero* to_delete) {
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (to_delete == _heroes[i]) {
      _heroes.erase(_heroes.begin() + i);
      return RC_OK;
    }
  }
  return RC_NOT_FOUND;
}

size_t Quest::add_enemy(const Enemy*& new_enemy) {
  if (new_enemy == NULL) {
    return RC_BAD_INPUT;
  }
  _enemies.push_back(new_enemy);
  return RC_OK;
}

size_t Quest::remove_enemy(const size_t& index) {
  if (index < _enemies.size()) {
    if (_enemies[index] != NULL) {
      delete _enemies[index];
    }
    _enemies.erase(_enemies.begin() + index);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::remove_enemy(Enemy* to_delete) {
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (to_delete == _enemies[i]) {
      if (_enemies[i] != NULL) {
        delete _enemies[i];
      }
      _enemies.erase(_enemies.begin() + i);
      return RC_OK;
    }
  }
  return RC_NOT_FOUND;
}

size_t Quest::what(std::string& result) const {
  result.clear();
  result += _name;
  result.append(" ");
  std::string buffer;
  buffer.clear();
  convert_to_string(_level, buffer);
  buffer.append(" Level\nLocation: ");
  result += buffer;
  buffer.clear();
  _location.short_what(buffer);
  buffer.append("\nEmployer faction: ");
  result += buffer;
  buffer.clear();
  _employer_faction.get_name(buffer);
  buffer.append("\nTarger faction: ");
  result += buffer;
  buffer.clear();
  _target_faction.get_name(buffer);
  buffer.append("\nReward: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_rewards[RI_MONEY], buffer);
  buffer.append(" coins, ");
  result += buffer;
  buffer.clear();
  convert_to_string(_rewards[RI_EXPERIENCE], buffer);
  buffer.append(" Exp\nBonus: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_bonuses[RI_MONEY], buffer);
  buffer.append(" coins, ");
  result += buffer;
  buffer.clear();
  convert_to_string(_bonuses[RI_EXPERIENCE], buffer);
  buffer.append("Exp\nStatus: ");
  _dictionary->get_quest_phase_name(_phase, buffer);
  result += buffer;
  buffer.clear();
  result.append("\nDamage dealt: ");
  convert_to_string(_damage, buffer);
  result += buffer;
  buffer.clear();
  if (!_enemies.empty()) {
    buffer.append("\nEnemies:\n");
    result += buffer;
    buffer.clear();
    for (size_t i = 0; i < _enemies.size(); ++i) {
      if (_enemies[i] != NULL) {
        result.append("\t");
        buffer.clear();
        _enemies[i]->short_what(buffer);
        result += buffer;
      }
    }
  }
  buffer.clear();
  if (!_heroes.empty()) {
    result.append("Heroes:\n");
    for (size_t i = 0; i < _heroes.size(); ++i) {
      if (_heroes[i] != NULL) {
        result.append("\t");
        buffer.clear();
        _heroes[i]->short_what(buffer);
        result += buffer;
      }
    }
  }
  bu  `ffer.clear();
  return RC_OK;
}

size_t Quest::short_what(std::string& result) const {
  result.clear();
  result += _name;
  result.append(" ");
  std::string buffer;
  buffer.clear();
  convert_to_string(_level, buffer);
  buffer.append(" Level\nLocation: ");
  result += buffer;
  buffer.clear();
  _location.short_what(buffer);
  buffer.append("\nEmployer faction: ");
  result += buffer;
  buffer.clear();
  _employer_faction.get_name(buffer);
  buffer.append("\nTarger faction: ");
  result += buffer;
  buffer.clear();
  _target_faction.get_name(buffer);
  buffer.append("\nReward: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_rewards[RI_MONEY], buffer);
  buffer.append(" coins, ");
  result += buffer;
  buffer.clear();
  convert_to_string(_rewards[RI_EXPERIENCE], buffer);
  buffer.append(" Exp\nBonus: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_bonuses[RI_MONEY], buffer);
  buffer.append(" coins, ");
  result += buffer;
  buffer.clear();
  convert_to_string(_bonuses[RI_EXPERIENCE], buffer);
  buffer.append("Exp\nStatus: ");
  _dictionary->get_quest_phase_name(_phase, buffer);
  result += buffer;
  buffer.clear();
  convert_to_string(_damage, buffer);
  result.append("\nDamage dealt: ");
  result += buffer;
  buffer.clear();
  buffer.append("\nEnemies: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_enemies.size(), buffer);
  buffer.append("\nHeroes: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_heroes.size(), buffer);
  result += buffer;
  buffer.clear();  
  return RC_OK;
}
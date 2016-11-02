#include "TextStorage.h"

size_t TextStorage::read_stat_names(sqlite3*& connection) {
  _stat_names.clear();
  sqlite3_stmt* statement;
  ssize_t response = sqlite3_prepare(connection, "select id, stat1, stat2, stat3, stat4 from 'stat_names'", -1, &statement, 0);
  sqlite3_step(statement);
  for (size_t i = 0; i < SI_SIZE; ++i) {
    _stat_names.push_back();
    _stat_names[i].append(sqlite3_column_text(statement, i + 1));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_gender_names(sqlite3*& connection) {
  _gender_names.clear();
  sqlite3_stmt* statement;
  ssize_t response = sqlite3_prepare(connection, "select id, gender1, gender2 from 'gender_names'", -1, &statement, 0);
  sqlite3_step(statement);
  for (size_t i = 0; i < (size_t)MALE_GENDER + 1; ++i) {
    _gender_names.push_back();
    _gender_names.append(sqlite3_column_text(statement, i + 1));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_personality_stat_names(sqlite3*& connection) {
  _personality_stat_names.clear();
  sqlite3_stmt* statement;
  ssize_t response = sqlite3_prepare(connection, "select count(*) from 'personality_stat_names'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'personality_stat_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _personality_stat_names.push_back();
    _personality_stat_names[i].append(sqlite3_column_text(statement, 0));
  }
  return RC_OK;
}

size_t TextStorage::read_hero_history_names(sqlite3*& connection) {
  _hero_history_names.clear();
  sqlite3_stmt* statement;
  ssize_t response = sqlite3_prepare(connection, "select count(*) from 'hero_history_names'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'hero_history_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _hero_history_names.push_back();
    _hero_history_names.append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_health_state_names(sqlite3*& connection) {
  _health_state_names.clear();
  sqlite3_stmt* statement;
  ssize_t response = sqlite3_prepare(connection, "select count(*) from 'health_state_names'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  response = sqlite3_prepare(connection, "select name from 'health_state_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _health_state_names.push_back();
    _health_state_names[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_male_names(sqlite3*& connection) {
  _male_names.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'male_names'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'male_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _male_names.push_back();
    _male_names[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_female_names(sqlite3*& connection) {
  _female_names.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'female_names'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'female_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _female_names.push_back();
    _female_names[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_nicknames(sqlite3*& connection) {
  _nicknames.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'nicknames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'nicknames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _nicknames.push_back();
    _nicknames[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_surnames(sqlite3*& connection) {
  _surnames.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'surnames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'surnames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _surnames.push_back();
    _surnames[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t read_hero_description_beginning(sqlite3*& connection) {
  _hero_description_beginning.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'hero_description_beginning'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'hero_description_beginning'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	_hero_description_beginning.push_back();
	_hero_description_beginning[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t read_hero_description_middle(sqlite3*& connection) {
  _hero_description_middle.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'hero_description_middle'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'hero_description_middle'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	_hero_description_middle.push_back();
	_hero_description_middle[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t read_hero_description_ending(sqlite3*& connection) {
  _hero_description_ending.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'hero_description_ending'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'hero_description_ending'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	_hero_description_ending.push_back();
	_hero_description_ending[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_faction_firstnames(sqlite3*& connection) {
  _faction_firstname_templates.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_firstnames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'faction_firstnames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _faction_firstname_templates.push_back();
    _faction_firstname_templates[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_faction_lastnames(sqlite3*& connection) {
  _faction_lastname_templates.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_lastnames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'faction_lastnames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _faction_lastname_templates.push_back();
    _faction_lastname_templates[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t read_faction_description_beginning(sqlite3*& connection) {
  _faction_description_beginning.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_description_beginning'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'faction_description_beginning'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	_faction_description_beginning.push_back();
	_faction_description_beginning[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t read_faction_description_middle(sqlite3*& connection) {
  _faction_description_middle.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_description_middle'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'faction_description_middle'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	_faction_description_middle.push_back();
	_faction_description_middle[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t read_faction_description_ending(sqlite3*& connection) {
  _faction_description_ending.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_description_ending'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'faction_description_ending'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	_faction_description_ending.push_back();
	_faction_description_ending[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_okay_answers(sqlite3*& connection) {
  _hero_answers_okay.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'okay_answers'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'okay_answers'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _hero_answers_okay.push_back();
    _hero_answers_okay[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_risky_answers(sqlite3*& connection) {
  _hero_answers_risky.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'risky_answers'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'risky_answers'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _hero_answers_risky.push_back();
    _hero_answers_risky[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_greedy_answers(sqlite3*& connection) {
  _hero_answers_greedy.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'greedy_answers'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'greedy_answers'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _hero_answers_greedy.push_back();
    _hero_answers_greedy[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_item_rarity_names(sqlite3*& connection) {
  _item_rarity_names.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'item_rarity_names'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'item_rarity_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _item_rarity_names.push_back();
    _item_rarity_names[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::read_item_kind_names(sqlite3*& connection) {
  _item_kind_names.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'item_kind_names'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'item_kind_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _item_kind_names.push_back();
    _item_kind_names[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TextStorage::get_okay_answer(std::string& result) const {
  if (_hero_answers_okay.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _hero_answers_okay.size();
  result = _hero_answers_okay[id];
  return RC_OK;
}

size_t TextStorage::get_risky_answer(std::string& result) const {
  if (_hero_answers_risky.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _hero_answers_risky.size();
  result = _hero_answers_risky[id];
  return RC_OK;
}

size_t TextStorage::get_greedy_answer(std::string& result) const {
  if (_hero_answers_greedy.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _hero_answers_greedy.size();
  result = _hero_answers_greedy[id];
  return RC_OK;
}

size_t TextStorage::fill_storage(const std::string& db_name) {
  if (db_name.empty()) {
    return RC_EMPTY_STRING;
  }
  sqlite3* database;
  open_connection(db_name, database);
  read_stat_names(database);
  read_personality_stat_names(database);
  read_gender_names(database);
  read_health_state_names(database);
  read_hero_history_names(database);
  read_male_names(database);
  read_female_names(database);
  read_nicknames(database);
  read_surnames(database);
  read_hero_description_beginning(database);
  read_hero_description_middle(database);
  read_hero_description_ending(database);
  read_faction_firstnames(database);
  read_faction_lastnames(database);
  read_faction_description_beginning(database);
  read_faction_description_middle(database);
  read_faction_description_ending(database);
  read_okay_answers(database);
  read_risky_answers(database);
  read_greedy_answers(database);
  read_item_rarity_names(database);
  read_item_kind_names(database);
  close_connection(database);
  return RC_OK;  
}

size_t TextStorage::clear_storage() {
  _stat_names.clear();
  _personality_stat_names.clear();
  _gender_names.clear();
  _health_state_names.clear();
  _hero_history_names.clear();
  _male_names.clear();
  _female_names.clear();
  _nicknames.clear();
  _surnames.clear();
  _hero_description_beginning.clear();
  _hero_description_middle.clear();
  _hero_description_ending.clear();
  _faction_firstname_templates.clear();
  _faction_lastname_templates.clear();
  _faction_description_beginning.clear();
  _faction_description_middle.clear();
  _faction_description_ending.clear();
  _hero_answers_okay.clear();
  _hero_answers_risky.clear();
  _hero_answers_greedy.clear();
  _item_rarity_names.clear();
  _item_kind_names.clear();
  return RC_OK;
}

size_t TextStorage::get_stat_name(const size_t& id, std::string& result) const {
  if (id < _stat_names.size()) {
    result.clear();
    result = _stat_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_perosonality_stat_name(const size_t& id, std::string& result) const {
  if (id < _personality_stat_names.size()) {
    result.clear();
    result = _personality_stat_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_gender_name(const size_t& id, std::string& result) const {
  if (id < _gender_names.size()) {
    result.clear();
    result = _gender_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_health_state_name(const size_t& id, std::string& result) const {
  if (id < _health_state_names.size()) {
    result.clear();
    result += _health_state_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_hero_history_name(const size_t& id, std::string& result) const {
  if (id < _hero_history_names.size()) {
    result.clear();
    result += _hero_history_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::form_name(bool gender, std::string& result) const {
  if (_male_names.empty() || _female_names.empty() || _nicknames.empty() || _surnames.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  result.clear();
  size_t index = SIZE_T_DEFAULT_VALUE;
  if (gender == MALE_GENDER) {
    index = rand() % _male_names.size();
    result += _male_names[index];
  } else {
    index = rand() % _female_names.size();
    result += _female_names[index];
  }
  result.append(" ");
  // hero acquires a nickname with 50% chance (possibly needs to be tweaked)
  if (rand() % 2 == 0) {
    result.append("\'");
    index = rand() % _nicknames.size();
    result += _nicknames[index];
    result.append("\' ");
  }
  // hero acquires a surname with 75% chance (possibly needs to be tweaked later)
  if (rand() % PERCENT_CAP < 75) {
    index = rand() % _surnames.size();
    result += _surnames[index];
  }
  result.append("\n");
  return 0;
}

size_t TextStorage::get_male_name(const size_t& id, std::string& result) const {
  if (id < _male_names.size()) {
    result = _male_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_female_name(const size_t& id, std::string& result) const {
  if (id < _female_names.size()) {
    result = _female_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_nickname(const size_t& id, std::string& result) const {
  if (id < _nicknames.size()) {
    result = _nicknames[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_surname(const size_t& id, std::string& result) const {
  if (id < _surnames.size()) {
    result = _surnames[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::form_hero_description(std::string& result) const {
  if (_hero_description_beginning.empty() || _hero_description_middle.empty() || _hero_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  result.clear();
  size_t index = rand() % _hero_description_beginning.size();
  result += _hero_description_beginning[index];
  result.append("\n");
  index = rand() % _hero_description_middle.size();
  result += _hero_description_middle[index];
  result.append("\n");
  index = rand() % _hero_description_ending.size();
  result += _hero_description_ending[index];
  result.append("\n");
  return RC_OK;
}

size_t TextStorage::form_faction_name(std::string& result) const {
  if (_faction_firstname_templates.empty() || _faction_lastname_templates.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  result.clear();
  size_t index = SIZE_T_DEFAULT_VALUE;
  index = rand() % _faction_firstname_templates.size();
  result += _faction_firstname_templates[index];
  result.append(" ");
  index = rand() % _faction_lastname_templates.size();
  result += _faction_lastname_templates[index];
  return RC_OK;
}

size_t TextStorage::get_faction_firstname(const size_t& id, std::string& result) const {
  if (id < _faction_firstname_templates.size()) {
    result = _faction_firstname_templates[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_faction_lastname(const size_t& id, std::string& result) const {
  if (id < _faction_lastname_templates.size()) {
    result = _faction_lastname_templates[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::form_faction_description(std::string& result) const {
  if (_faction_description_beginning.empty() || _faction_description_middle.empty() || _faction_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  result.clear();
  size_t index = rand() % _faction_description_beginning.size();
  result += _faction_description_beginning[index];
  result.append("\n");
  index = rand() % _faction_description_middle.size();
  result += _faction_description_middle[index];
  result.append("\n");
  index = rand() % _faction_description_ending.size();
  result += _faction_description_ending[index];
  result.append("\n");
  return RC_OK;
}

size_t TextStorage::get_hero_answer(const size_t& answer_id, std::string& result) const {
  switch (answer_id) {
    case HA_OK: {
      return get_okay_answer(result);
    }
    case HA_TOO_BIG_RISK: {
      return get_risky_answer(result);
    }
    case HA_WANT_MORE_MONEY: {
      return get_greedy_answer(result);
    }
    default: {
      return RC_BAD_INDEX;
    }
  }
}

size_t TextStorage::get_item_rarity_name(const size_t& rarity_id, std::string& result) const {
  if (rarity_id < _item_rarity_names.size()) {
    result.clear();
    result = _item_rarity_names[rarity_id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_item_kind_name(const size_t& kind_id, std::string& result) const {
  if (kind_id < _item_kind_names.size()) {
    result.clear();
    result = _item_kind_names[kind_id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}


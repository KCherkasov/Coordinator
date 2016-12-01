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

size_t TextStorage::read_player_history_names(sqlite3*& connection) {
  _player_history_names.clear();
  sqlite3_stmt* statement;
  ssize_t response = sqlite3_prepare(connection, "select count(*) from 'player_history_names'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  response = sqlite3_prepare(connection, "select name from 'player_history_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _player_history_names.push_back();
    _player_history_names[i].append(sqlite3_column_text(statement, 0));
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

size_t TextStorage::read_quest_phase_names(sqlite3*& connection) {
  _quest_phase_names.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'quest_phase_names'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_phase_names'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _quest_phase_names.push_back();
    _quest_phase_names[i].append(sqlite3_column_text(statement, 0));
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
  read_player_history_names(database);
  read_okay_answers(database);
  read_risky_answers(database);
  read_greedy_answers(database);
  read_item_rarity_names(database);
  read_item_kind_names(database);
  read_quest_phase_names(database);
  close_connection(database);
  return RC_OK;  
}

size_t TextStorage::clear_storage() {
  _stat_names.clear();
  _personality_stat_names.clear();
  _gender_names.clear();
  _health_state_names.clear();
  _hero_history_names.clear();
  _player_history_names.clear();
  _hero_answers_okay.clear();
  _hero_answers_risky.clear();
  _hero_answers_greedy.clear();
  _item_rarity_names.clear();
  _item_kind_names.clear();
  _quest_phase_names.clear();
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

size_t TextStorage::get_player_history_name(const size_t& id, std::string& result) const {
  if (id < _player_history_names.size()) {
    result.clear();
    result += _player_history_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
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

size_t TextStorage::get_quest_phase_name(const size_t& phase_id, std::string& result) const {
  if (phase_id < _quest_phase_names.size()) {
    result.clear();
    result = _quest_phase_names[phase_id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

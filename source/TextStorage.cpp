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
  
}

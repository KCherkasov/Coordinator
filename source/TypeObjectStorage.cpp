#include "TypeObjectStorage.h"

size_t TypeObjectStorage::read_character_archetype_namedescrs(sqlite3*& connection, std::vector<CharacterArchetypeTemplate>& result) {
  sqlite3_stmt* statement;
  size_t count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'archetype_namedescrs'", -1, &statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name, description from 'archetype_namedescrs'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._name.clear();
    result[i]._name.append(sqlite3_column_text(statement, 0));
    result[i]._description.clear();
    result[i]._description.append(sqlite3_column_text(statement, 1));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TypeObjectStorage::read_character_archetype_power_def_mods(sqlite3*& connection, std::vector<CharacterArchetypeTemplate>& result) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'archetype_power_mods'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(statement, "select endurance, strength, agility, intelligence from 'archetype_power_mods'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._power_mods.clear();
    result[i]._power_mods.resize(SI_SIZE);
    for (size_t j = 0; j < result[i]._power_mods.size(); ++j) {
      result[i]._power_mods[j] = sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'archetype_defense_mods'", -1, &statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select endurance, strength, agility, intelligence from 'archetype_defense_mods'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._defense_mods.clear();
    result[i]._defense_mods.resize(SI_SIZE);
    for (size_t j = 0; j < result[i]._defense_mods.size(); ++j) {
      result[i]._defense_mods[j] = sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TypeObjectStorage::read_character_archetypes(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'archetype_namedescrs'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  std::vector<CharacterArchetypeTemplate> buffer(count);
  for (size_t i = 0; i < buffer.size(); ++i) {
    buffer._own_id = FREE_ID;
  }
  read_character_archetype_namedescrs(connection, buffer);
  read_character_archetype_power_def_mods(connection, buffer);
  _character_archetypes.clear();
  for (size_t i = 0; i < buffer.size(); ++i) {
    CharacterArchetype tmp(buffer[i]);
    _character_archetypes.push_back(tmp);
  }
  buffer.clear();
  return RC_OK;
}

size_t TypeObjectStorage::read_hero_class_data(sqlite3*& connection, std::vector<HeroClassTemplate>& result) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_class_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name, description, archetype_id from 'hero_class_data'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._own_id = FREE_ID;
    result[i]._name.clear();
    result[i]._name.append(sqlite3_column_text(statement, 0));
    result[i]._description.clear();
    result[i]._description.append(sqlite3_column_text(statement, 1));
    result[i]._archetype_id = sqlite3_column_int(statement, 2);
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TypeObjectStorage::read_hero_class_stat_bonuses(sqlite3*& connection, std::vector<HeroClassTemplate>& result) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_class_stat_bonuses'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select endurance, strength, agility, intelligence from 'hero_class_stat_bonuses'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._stat_bonuses.clear();
    result[i]._stat_bonuses.resize(SI_SIZE);
    for (size_t j = 0; j < result._stat_bonuses.size(); ++j) {
      result[i]._stat_bonuses[j]= sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TypeObjectStorage::read_hero_class_att_def_modifiers(sqlite3*& connection, std::vector<HeroClassTemplate>& result) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_class_att_power_modifiers'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select warrior, wizard, rogue, ranger from 'hero_class_att_power_modifiers'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._att_power_mods.clear();
    result[i]._att_power_mods.resize(CA_SIZE);
    for (size_t j = 0; j < result._att_power_mods.size(); ++j) {
      result[i]._att_power_mods[j] = sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'hero_class_defense_modifiers'", -1, &statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select warrior, wizard, rogue, ranger from 'hero_class_defense_modifiers'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    result[i]._defense_modifiers.clear();
    result[i]._defense_modifiers.resize(CA_SIZE);
    for (size_t j = 0; j < result[i]._defense_modifiers.size(); ++j) {
      result[i]._defense_modifiers[j] = sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TypeObjectStorage::read_hero_classes(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  std::vector<HeroClassTemplate> buffer(count);
  read_hero_class_data(connection, buffer);
  read_hero_class_stat_bonuses(connection, buffer);
  read_hero_class_att_def_modifiers(connection, buffer);
  _hero_classes.clear();
  for (size_t i = 0; i < buffer.size(); ++i) {
    HeroClass tmp(buffer[i]);
    _hero_classes.push_back(tmp);
  }
  return RC_OK;
}

size_t TypeObjectStorage::fill_storage(std::string& db_name) {
  if (db_name.empty()) {
    return RC_EMPTY_STRING;
  }
  sqlite3* database;
  open_connection(db_name, database);
  read_character_archetypes(database);
  read_hero_classes(database);
  close_connection();
  return RC_OK;
}

size_t TypeObjectStorage::clear_storage() {
  _character_archetypes.clear();
  _hero_classes.clear();
  return RC_OK;
}
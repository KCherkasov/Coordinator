#include "TemplateStorage.h"

size_t TemplateStorage::read_male_names(sqlite3*& connection) {
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

size_t TemplateStorage::read_female_names(sqlite3*& connection) {
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

size_t TemplateStorage::read_nicknames(sqlite3*& connection) {
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

size_t TemplateStorage::read_surnames(sqlite3*& connection) {
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

size_t TemplateStorage::read_hero_descriptions(sqlite3*& connection) {
  _hero_description_beginning.clear();
  _hero_description_middle.clear();
  _hero_description_ending.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'hero_descriptions'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select beginning, middle, ending from 'hero_descriptions'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	  _hero_description_beginning.push_back();
  	_hero_description_beginning[i].append(sqlite3_column_text(statement, 0));
    _hero_description_middle.push_back();
    _hero_description_middle[i].append(sqlite3_column_text(statement, 1));
    _hero_description_ending.push_back();
    _hero_description_ending[i].append(sqlite3_column_text(statement,2));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_hero_data(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select level, health, class_id from 'hero_data'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _heroes[i]._level = sqlite3_column_int(statement, 0);
    _heroes[i]._health = sqlite3_column_int(statement, 1);
    _heroes[i]._class_id = sqlite3_column_int(statement, 2);
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_hero_stats(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_stats'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select endurance, strength, agility, intelligence from 'hero_stats'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _heroes[i]._stats.clear();
    for (size_t j = 0; j < SI_SIZE; ++j) {
      _heroes[i].push_back(sqlite3_column_int(statement, j));
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_hero_personality(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_personality'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select greed, caution, inventive, accuracy, educability from 'hero_personality'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _heroes[i]._personality.clear();
    for (size_t j = 0; j < RS_SIZE; ++j) {
      _heroes[i]._personality.push_back(sqlite3_column_int(statement, j));
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_hero_equipment(sqlite3*& connection) {
  srand(static_cast<size_t>(time(0)));
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_equipment'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select head, armour, gloves, boots, main_hand, off_hand, neck, ring_1, ring_2 from 'hero_equipment'", -1, &statement, 0);
  for (size_t i = 0; i <  count; ++i) {
    sqlite3_step(statement);
    _heroes[i]._equipment._equipment.clear();
    for (size_t j = 0; j < IS_SIZE; ++j) {
      size_t id;
      if (sqlite3_column_int(statement, j) >= FREE_ID) {
        id = sqlite3_column_int(statement, j);
      } else {
        id = j + rand() % ITEMS_PER_SLOT;
      }
      _heroes[i]._equipment._equipment.push_back(_items[id]);
      _heroes[i]._equipment._equipment[j]._level = _heroes[i]._level;
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_heroes(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'hero_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  _heroes.clear();
  _heroes.resize(count);
  for (size_t i = 0; i < count; ++i) {
    _heroes[i]._own_id = FREE_ID;
    _heroes[i]._name.clear();
    _heroes[i]._description.clear();
    _heroes[i]._level = START_LEVEL;
    _heroes[i]._faction_id = FREE_ID;
    _heroes[i]._health = CH_HEALTHY;
    _heroes[i]._stats.clear();
    for (size_t j = 0; j < SI_SIZE; ++j) {
      _heroes[i]._stats.push_back(SIZE_T_DEFAULT_VALUE);
    }
    _heroes[i]._class_id = FREE_ID;
    _heroes[i]._experience.clear();
    for (size_t j = 0; j < PAIR_ARR_SIZE; ++j) {
      _heroes[i]._experience.push_back(SIZE_T_DEFAULT_VALUE);
    }
    _heroes[i]._experience[1] = FIRST_LEVELUP_CAP;
    _heroes[i]._personality.clear();
    for (size_t j = 0; j < RS_SIZE; ++j) {
      _heroes[i]._personality.push_back(SIZE_T_DEFAULT_VALUE);
    }
    _heroes[i]._history.clear();
    for (size_t j = 0; j < HH_SIZE; ++j) {
      _heroes[i]._history.push_back(SIZE_T_DEFAULT_VALUE);
    }
    _heroes[i]._equipment._equipment.clear();
  }
  read_hero_data(connection);
  read_hero_stats(connection);
  read_hero_personality(connection);
  read_hero_equipment(connection);
  return RC_OK;
}

size_t TemplateStorage::read_faction_firstnames(sqlite3*& connection) {
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

size_t TemplateStorage::read_faction_lastnames(sqlite3*& connection) {
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

size_t TemplateStorage::read_faction_descriptions(sqlite3*& connection) {
  _faction_description_beginning.clear();
  _faction_description_middle.clear();
  _faction_description_ending.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_descriptions'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select beginnning, middle, ending from 'faction_descriptions'", -1, &statement, 0);]
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	  _faction_description_beginning.push_back();
	  _faction_description_beginning[i].append(sqlite3_column_text(statement, 0));
	  _faction_description_beginning.push_back();
	  _faction_description_beginning[i].append(sqlite3_column_text(statement, 1));  
	  _faction_description_beginning.push_back();
	  _faction_description_beginning[i].append(sqlite3_column_text(statement, 2));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_faction_description_middle(sqlite3*& connection) {
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

size_t TemplateStorage::read_faction_description_ending(sqlite3*& connection) {
  _faction_description_ending.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'faction_description_ending'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select description from 'faction_description_ending'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
	  _faction_description_ending.push_back();
   	_faction_description_ending[i].append(sqlite3_column_text(statement, 0));
  }  
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_factions(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'faction_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select inluence, relationship from 'faction_data'", -1, &statement, 0);
  _factions.clear();
  _factions.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _factions[i]._own_id = FREE_ID;
    _faction[i]._name.clear();
    _faction[i]._description.clear();
    _faction[i]._influence = sqlite3_column_int(statement, 0);
    _faction[i]._relationship = sqlite3_column_int(statement, 1);
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_item_namedescrs(sqlite3*& connection) {
  _item_kind_names.clear();
  _item_slot_subnames.clear();
  _item_description_beginning.clear();
  _item_description_middle.clear();
  _item_description_ending.clear();
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
  sqlite3_prepare(connection, "select count(*) from 'item_slot_subnames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'item_slot_subnames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _item_slot_subnames.push_back();
    _item_slot_subnames.append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'item_description_beginning'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement,0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'item_description_beginning'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _item_description_beginning.push_back();
    _item_description_beginning.append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'item_description_middle'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'item_description_middle'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _item_description_middle.push_back();
    _item_description_middle.append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'item_description_ending'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement,0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'item_description_ending'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _item_description_ending.push_back();
    _item_description_ending.append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_item_bonuses(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'item_bonuses'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select endurance, strength, agility, intelligence from 'item_bonuses'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _items[i]._bonuses.clear();
    for (size_t j = 0; j < SI_SIZE; ++i) {
      _items[i]._bonuses.push_back(sqlite3_column_int(statement, j));
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_item_slots(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'item_slots'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select head, armour, gloves, boots, main_hand, off_hand, neck, ring_1, ring_2 from 'item_slots'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _items[i]._slots.clear();
    for (size_t j = 0; j < IS_SIZE; ++j) {
      _items[i]._slots.push_back(sqlite3_column_int(statement, j) > 0);
    }
  }
  return RC_OK;
}

size_t TemplateStorage::read_item_data(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'item_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select level, rarity, kind, price from 'item_data'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _items[i]._level = sqlite3_column_int(statement, 0);
    _items[i]._rarity = sqlite3_column_int(statement, 1);
    _items[i]._kind = sqlite3_column_int(statement, 2);
    _items[i]._price = sqlite3_column_int(statement, 3);
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_items(sqlite3*& connection) {
  _items.clear();
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count from 'item_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  _items.resize(count);
  for (size_t i = 0; i < _items.size(); ++i) {
    _items[i]._own_id = FREE_ID;
    _items[i]._name.clear();
    _items[i]._description.clear();
    _items[i]._level = START_LEVEL;
    _items[i]._owner_id = FREE_ID;
    _items[i]._rarity = IR_COMMON;
    _items[i]._kind = IK_SIZE;
    _items[i]._price = SIZE_T_DEFAULT_VALUE;
    _items[i]._bonuses.clear();
    for (size_t j = 0; j < SI_SIZE; ++i) {
      _items[i]._bonuses.push_back(SIZE_T_DEFAULT_VALUE);
    }
    _items[i]._slots.clear();
    for (size_t i = 0; j < IS_SIZE; ++i) {
      _items[i]._slots.push_back(false);
    }
  }
  read_item_bonuses(connection);
  read_item_slots(connection);
  read_item_data(connection);
  return RC_OK;  
}

size_t TemplateStorage::read_loot_data(sqlite3*& connection) {
  _loot_data.clear();
  size_t count = SIZE_T_DEFAULT_VALUE;
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'loot_data'", -1, &statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select item_id, drop_chance, max_quantity from 'loot_data'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _loot_data.push_back();
    _loot_data[i]._item_id = sqlite3_column_int(statement, 0);
    _loot_data[i]._drop_chance = sqlite3_column_int(statement, 1);
    _loot_data[i]._max_quantity = sqlite3_column_int(statement, 2);
  }
  sqlite3_finalize(statement);
  return RC_OK;
};

size_t TemplateStorage::read_enemy_namedescrs(sqlite3*& connection) {
  _enemy_firstnames.clear();
  _enemy_lastnames.clear();
  _enemy_description_beginning.clear();
  _enemy_description_middle.clear();
  _enemy_description_ending.clear();
  sqlite3_stmt* statement;
  size_t names_count = SIZE_T_DEFAULT_VALUE;
  sqlite3_prepare(connection, "select count(*) from 'enemy_firstnames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'enemy_firstnames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _enemy_firstnames.push_back();
    _enemy_firstnames[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'enemy_lastnames'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'enemy_lastnames'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _enemy_lastnames.push_back();
    _enemy_lastnames[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'enemy_description_beginning'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'enemy_description_beginning'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _enemy_description_beginning.push_back();
    _enemy_description_beginning[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'enemy_description_middle'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'enemy_description_middle'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _enemy_description_middle.push_back();
    _enemy_description_middle[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'enemy_description_ending'", -1, &statement, 0);
  sqlite3_step(statement);
  names_count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'enemy_description_ending'", -1, &statement, 0);
  for (size_t i = 0; i < names_count; ++i) {
    sqlite3_step(statement);
    _enemy_description_ending.push_back();
    _enemy_description_ending[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_enemy_data(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'enemy_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select level, health, archetype_id from 'enemy_data'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _enemies[i]._level = sqlite3_column_int(statement, 0);
    _enemies[i]._health = sqlite3_column_int(statement, 1);
    _enemies[i]._archetype_id =  sqlite3_column_int(statement, 2);
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_enemy_stats(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'enemy_stats'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select endurance, strength, agility, intelligence from 'enemy_stats'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    for (size_t j = 0; j < SI_SIZE; ++j) {
      _enemy[i]._stats[j] = sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_enemy_rewards(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'enemy_rewards'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select money, experience from 'enemy_rewards'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    for (size_t j = 0; j < RI_SIZE; ++j) {
      _enemies[i]._rewards[j] = sqlite3_column_int(statement, j);
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_enemies(sqlite3*& connection) {
  _enemies.clear();
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'enemies_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  _enemies.resize(count);
  for (size_t i = 0; i < count; ++i) {
    _enemies[i]._name.clear();
    _enemies[i]._description.clear();
    _enemies[i]._level = START_LEVEL;
    _enemies[i]._health = CH_HEALTHY;
    _enemies[i]._faction_id = FREE_ID;
    _enemies[i]._stats.clear();
    for (size_t j = 0; j < SI_SIZE; ++j) {
      _enemies[i]._stats.push_back(SIZE_T_DEFAULT_VALUE);
    }
    _enemies[i]._archetype_id = FREE_ID;
    _enemies[i]._loot_list.clear();
    _enemies[i]._rewards.clear();
    for (size_t j = 0; j < RI_SIZE; ++j) {
      _enemies[i]._rewards.push_back(SIZE_T_DEFAULT_VALUE);
    }
  }
  read_enemy_data(connection);
  read_enemy_stats(connection);
  read_enemy_rewards(connection);
  return RC_OK;
}

size_t TemplateStorage::read_quest_namedescrs(sqlite3*& connection) {
  sqlite3_stmt* statement;
  size_t count;
  sqlite3_prepare(connection, "select count(*) from 'quest_name_first'", -1, statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_name_first'", -1, statement, 0);
  _quest_name_first.clear();
  _quest_name_first.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quest_name_first[i].clear();
    _quest_name_first[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'quest_name_middle'", -1, statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_name_middle'", -1, statement, 0);
  _quest_name_middle.clear();
  _quest_name_middle.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quest_name_middle[i].clear();
    _quest_name_middle[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'quest_name_last'", -1, statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_name_last'", -1, statement, 0);
  _quest_name_last.clear();
  _quest_name_last.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quest_name_last[i].clear();
    _quest_name_last[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'quest_description_beginning'", -1, statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_description_beginning'", -1, statement, 0);
  _quest_description_beginning.clear();
  _quest_description_beginning.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quest_description_beginning[i].clear();
    _quest_description_beginning[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'quest_description_middle'", -1, statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_description_middle'", -1, statement, 0);
  _quest_description_middle.clear();
  _quest_description_middle.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quest_description_middle[i].clear();
    _quest_description_middle[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select count(*) from 'quest_description_ending'", -1, statement, 0);
  sqlite3_step(statement);
  count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select name from 'quest_description_ending'", -1, statement, 0);
  _quest_description_ending.clear();
  _quest_description_ending.resize(count);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quest_description_ending[i].clear();
    _quest_description_ending[i].append(sqlite3_column_text(statement, 0));
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_quest_data(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'quest_data'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);  
  sqlite3_prepare(connection, "select level, location_id, employer_faction, target_faction, life_time", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quests[i]._level = sqlite3_column_int(statement, 0);
    _quests[i]._location_id = sqlite3_column_int(statement, 1);
    _quests[i]._employer_faction = sqlite3_column_int(statement, 2);
    _quests[i]._target_faction = sqlite3_column_int(statement, 3);
    _quests[i]._life_time = sqlite3_column_int(statement, 4);
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_quest_rewards(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'quest_rewards'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select money, experience from 'quest_rewards'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quests[i]._rewards.clear();
    for (size_t j = 0; j < RI_SIZE; ++j) {
      _quests[i]._rewards.push_back(sqlite3_column_int(statement, j));
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_quest_bonuses(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "select count(*) from 'quest_bonuses'", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "select money, experience from 'quest_bonuses'", -1, &statement, 0);
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quests[i]._bonuses.clear();
    for (size_t j = 0; j < RI_SIZE; ++j) {
      _quests[i]._rewards.push_back(sqlite3_column_int(statement, j));
    }
  }
  return RC_OK;
}

size_t TemplateStorage::read_quest_enemies(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  sqlite3_prepare(connection, "", -1, &statement, 0);
  size_t enemy_id; 
  for (size_t i = 0; i < count; ++i) {
    sqlite3_step(statement);
    _quests[i]._enemies.clear();
    for (size_t j = 0; j < MAX_ENEMIES_PER_QUEST; ++j) {
      enemy_id = sqlite3_column_int(statement, j);
      if (enemy_id < _enemies.size()) {
        _quests[i]._enemies.push_back(_enemies[i]);
      }
    }
  }
  sqlite3_finalize(statement);
  return RC_OK;
}

size_t TemplateStorage::read_quests(sqlite3*& connection) {
  sqlite3_stmt* statement;
  sqlite3_prepare(connection, "", -1, &statement, 0);
  sqlite3_step(statement);
  size_t count = sqlite3_column_int(statement, 0);
  sqlite3_finalize(statement);
  _quests.clear();
  _quests.resize(count);
  for (size_t i = 0; i < count; ++i) {
    _quests[i]._own_id = FREE_ID;
    _quests[i]._name.clear();
    _quests[i]._description.clear();
    _quests[i]._birth_time = SIZE_T_DEFAULT_VALUE;
    _quests[i]._phase = QP_PENDING;
    _quests[i]._heroes.clear();
  }
  read_quest_data(connection);
  read_quest_rewards(connection);
  read_quest_bonuses(connection);
  read_quest_enemies(connection);
  return RC_OK;
}

size_t TemplateStorage::power_up_hero(HeroTemplate& result) const {
  size_t stat_points = SIZE_T_DEFAULT_VALUE;
  if (result._level > START_LEVEL) {
    for (size_t i = 0; i < (result._level - START_LEVEL); ++i) {
      _experience[0] = _experience[1];
      _experience[1] *= EXP_RAISE_PER_LEVEL;
      _experience[1] /= PERCENT_CAP;
      _stat_points += STAT_POINTS_PER_LEVEL;
    }
    srand(static_cast<size_t>(time(0)));
    while (stat_points > 0) {
      ++result._stats[rand() % result._stats.size()];
      --stat_points;
    }
  }
  return RC_OK;
}

size_t TemplateStorage::power_up_item(ItemTemplate& result) const {
  if (result._level > START_LEVEL) {
    size_t stat_points = SIZE_T_DEFAULT_VALUE;
    for (size_t i = 0; i < (result._level - START_LEVEL); ++i) {
      result._price *= MONEY_RAISE_PER_LEVEL;
      result._price /= PERCENT_CAP;
      stat_points += STAT_POINTS_PER_LEVEL;
    }
    srand(static_cast<size_t>(time(0)));
    while (stat_points > 0) {
      ++result._bonuses[rand() % result._bonuses.size()];
      --stat_points;
    }
  }
  return RC_OK;
}

size_t TemplateStorage::power_up_enemy(EnemyTemplate& result) const {
  if (result._level > START_LEVEL) {
    size_t stat_points = SIZE_T_DEFAULT_VALUE;
    for (size_t i = 0; i < (result._level - START_LEVEL); ++i) {
      _stat_points += STAT_POINTS_PER_LEVEL;
      result._rewards[RI_MONEY] *= MONEY_RAISE_PER_LEVEL;
      result._rewards[RI_MONEY] /= PERCENT_CAP;
      result._rewards[RI_EXPERIENCE] *= EXP_RAISE_PER_LEVEL;
      result._rewards[RI_EXPERIENCE] /= PERCENT_CAP;
    }
    srand(static_cast<size_t>(time(0)));
    while (stat_points > 0) {
      ++result._stats[rand() % result._stats.size()];
      --stat_points;
    }
  }
  return RC_OK;
}

size_t TemplateStorage::power_up_quest(QuestTemplate& result) const {
  
  return RC_OK;
}

size_t TemplateStorage::fill_storage(const std::string& db_name) {
  if (db_name.empty()) {
    return RC_EMPTY_STRING;
  }
  sqlite3* database;
  open_connection(db_name, database);
  read_male_names(database);
  read_female_names(database);
  read_nicknames(database);
  read_surnames(database);
  read_hero_descriptions(database);
  read_heroes(database);
  read_faction_firstnames(database);
  read_faction_lastnames(database);
  read_faction_descriptions(database);
  read_factions(database);
  read_item_namedescrs(database);
  read_items(database);
  read_loot_data(database);
  read_enemy_namedescrs(database);
  read_enemies(database);
  read_quest_namedescrs(database);
  read_quests(database);
  close_connection();
  return RC_OK;
}

size_t TemplateStorage::clear_storage() {
  _male_names.clear();
  _female_names.clear();
  _nicknames.clear();
  _surnames.clear();
  _hero_description_beginning.clear();
  _hero_description_middle.clear();
  _hero_description_ending.clear();
  _heroes.clear();
  _faction_firstname_templates.clear();
  _faction_lastname_templates.clear();
  _faction_description_beginning.clear();
  _faction_description_middle.clear();
  _faction_description_ending.clear();
  _factions.clear();
  _item_kind_names.clear();
  _item_slot_subnames.clear();
  _item_description_beginning.clear();
  _item_description_middle.clear();
  _item_description_ending.clear();
  _items.clear();
  _loot_data.clear();
  _enemy_firstnames.clear();
  _enemy_lastnames.clear();
  _enemy_description_beginning.clear();
  _enemy_description_middle.clear();
  _enemy_description_ending.clear();
  _enemies.clear();
  _quest_name_first.clear();
  _quest_name_middle.clear();
  _quest_name_last.clear();
  _quest_description_beginning.clear();
  _quest_description_middle.clear();
  _quest_description_ending.clear();
  _quests.clear();
  return RC_OK;
}

size_t TemplateStorage::form_name(bool gender, std::string& result) const {
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

size_t TemplateStorage::get_male_name(const size_t& id, std::string& result) const {
  if (id < _male_names.size()) {
    result = _male_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::get_female_name(const size_t& id, std::string& result) const {
  if (id < _female_names.size()) {
    result = _female_names[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::get_nickname(const size_t& id, std::string& result) const {
  if (id < _nicknames.size()) {
    result = _nicknames[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::get_surname(const size_t& id, std::string& result) const {
  if (id < _surnames.size()) {
    result = _surnames[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_hero_description(std::string& result) const {
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

size_t TemplateStorage::make_hero_template(const size_t& id, HeroTemplate& result, const size_t& level) {
  if (_male_names.empty() || _female_names.empty() || _nicknames.empty() || _surnames.empty() || _hero_description_beginning.empty() || _hero_description_middle.empty() || _hero_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  if (id < _heroes.size()) {
    result = _heroes[id];
    srand(static_cast<size_t>(time(0)));
    result._gender = (rand() % 2 == 0);
    form_name(result._gender, result._name);
    form_description(result._description);
    for (size_t i = 0; i < result._equipment._equipment.size(); ++i) {
      form_item_name(result._equipment._equipment[i]._name, result._equipment._equipment[i]._kind, i);
      form_item_description(result._equipment._equipment[i]._description);
      result._equipment._equipment[i]._level = result._level;
      power_up_item(result._equipment._equipment[i]);
    }
    power_up_hero(result);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_faction_name(std::string& result) const {
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

size_t TemplateStorage::get_faction_firstname(const size_t& id, std::string& result) const {
  if (id < _faction_firstname_templates.size()) {
    result = _faction_firstname_templates[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::get_faction_lastname(const size_t& id, std::string& result) const {
  if (id < _faction_lastname_templates.size()) {
    result = _faction_lastname_templates[id];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_faction_description(std::string& result) const {
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

size_t TemplateStorage::make_faction_template(const size_t& id, FactionTemplate& result) const {
  if (_faction_firstname_templates.empty() || _faction_lastname_templates.empty() || _faction_description_beginning.empty() || _faction_description_middle.empty() || _faction_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  if (id < _factions[id]) {
    result = _factions[id];
    result._name.clear();
    form_faction_name(result._name);
    result._description.clear();
    form_faction_description(result._description);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_item_name(std::string& result, const size_t& kind_id, const size_t& slot_id) const {
  if (_item_kind_names.empty() || _item_slot_subnames.empty()) {
    return RC_EMPTY_VECTOR;
  }
  if (kind_id < _item_kind_names.size() && slot_id < _item_slot_subnames.size()) {
    srand(static_cast<size_t>(time(0)));
    result.clear();
    result += _item_kind_names[kind_id * NAMES_PER_KIND + rand() % NAMES_PER_KIND];
    if (!_item_slot_subnames.empty()) {
      result.append(" ");
      result += _item_slot_subnames[slot_id];
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_item_description(std::string& result) const {
  result.clear();
  if (_item_description_beginning.empty() || _item_description_middle.empty() || _item_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _item_description_beginning.size();
  result += _item_description_beginning[id];
  result.append("\n");
  id = rand() % _item_description_middle.size();
  result += _item_description_middle[id];
  result.append("\n");
  id = rand() % _item_description_ending.size();
  result += _item_description_ending[id];
  return RC_OK;
}

size_t TemplateStorage::make_item_template(const size_t& id, ItemTemplate& result, const size_t& level) const {
  if (id < _items.size()) {
    std::string buffer;
    buffer.clear();
    result = _items[id];
    form_item_name(buffer);
    result._name.clear();
    result._name = buffer;
    buffer.clear();
    form_item_description(buffer);
    result._description.clear();
    result._description = buffer;
    buffer.clear();
    power_up_item(result);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_enemy_name(std::string& result) const {
  if (_enemy_firstnames.empty() || _enemy_lastnames.empty()) {
    return RC_EMPTY_VECTOR;
  }
  result.clear();
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _enemy_firstnames.size();
  result += _enemy_firstnames[id];
  result.append(" ");
  id = rand() % _enemy_lastnames.size();
  result += _enemy_lastnames[id];
  return RC_OK;
}

size_t TemplateStorage::form_enemy_description(std::string& result) const {
  if (_enemy_description_beginning.empty() || _enemy_description_middle.empty() || _enemy_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  result.clear();
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _enemy_description_beginning.size();
  result += _enemy_description_beginning[id];
  result.append("\n");
  id = rand() % _enemy_description_middle.size();
  result += _enemy_description_middle[id];
  result.append("\n");
  id = rand() % _enemy_description_ending.size();
  result += _enemy_description_ending[id];
  return RC_OK;
}

size_t TemplateStorage::make_enemy_template(const size_t& id, EnemyTemplate& result, const size_t& faction_id, const size_t& level) const {
  if (_loot_data.empty()) {
    return RC_EMPTY_VECTOR;
  }
  if (id < _enemies.size()) {
    std::string buffer;
    buffer.clear();
    result = _enemies[id];
    form_enemy_name(buffer);
    result._name.clear();
    result._name = buffer;
    buffer.clear();
    form_enemy_description(buffer);
    result._description.clear();
    result._description = buffer;
    buffer.clear();
    srand(static_cast<size_t>(time(0)));
    result._loot_list.clear();
    for (size_t i = 0; i < MAX_LOOT_ITEMS; ++i) {
      size_t loot_id = rand() % _loot_data.size();
      result._loot_list.push_back(_loot_data[loot_id]);
    }
    power_up_enemy(result);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TemplateStorage::form_quest_name(std::string& result) const {
  if (_quest_name_first.empty() || _quest_name_middle.empty() || _quest_name_last.empty()) {
    return RC_EMPTY_VECTOR;
  }
  result.clear();
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _quest_name_first.size();
  result += _quest_name_first[id];
  result.append(" ");
  id = rand() % _quest_name_middle.size();
  result += _quest_name_middle[id];
  result.append(" ");
  id = rand() % _quest_name_last.size();
  result += _quest_name_last[id];
  return RC_OK;
}

size_t TemplateStorage::form_quest_description(std::string& result) const {
  if (_quest_description_beginning.empty() || _quest_description_middle.empty() || _quest_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  result.clear();
  srand(static_cast<size_t>(time(0)));
  size_t id = rand() % _quest_description_beginning.size();
  result += _quest_description_beginning[id];
  result.append("\n");
  id = rand() % _quest_description_middle.size();
  result += _quest_description_middle[id];
  result.append("\n");
  id = rand() % _quest_description_ending.size();
  result += _quest_description_ending[id];
  return RC_OK;
}

size_t TemplateStorage::make_quest_template(const size_t& id, QuestTemplate& result, const size_t& level) const {
  if (_quest_name_first.empty() || _quest_name_middle.empty() || _quest_name_last.empty() || _quest_description_beginning.epmpty() || _quest_description_middle.empty() || _quest_description_ending.empty()) {
    return RC_EMPTY_VECTOR;
  }
  if (id < _quests.size()) {
    result = _quests[id];
    form_quest_name(result._name);
    form_quest_description(result._description);
    result._level = level;
    for (size_t i = 0; i < result._enemies.size(); ++i) {
      result._enemies[i]._level = result._level;
      power_up_enemy(result._enemies[i]);
    }
    power_up_quest(result);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

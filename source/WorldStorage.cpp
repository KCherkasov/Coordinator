#include "WorldStorage.h"

WorldStorage::WorldStorage(const std::string& text_db_name, const std::string& template_db_name, const std::string& type_objects_db_name) {
  _texts.fill_storage(text_db_name);
  _templates.fill_storage(template_db_name);
  _type_objects.fill_storage(type_objects_db_name);
  HeroClass* class_tmp = NULL;
  CharacterArchetype* archetype_tmp = NULL;
  Location* location_tmp = NULL;
  _factions.clear();
  size_t i = 0;
  while (true) {
    if (_type_objects.get_character_archetype(i++, archetype_tmp) != RC_OK) {
      break;
    }
    if (archetype_tmp != NULL) {
      archetype_tmp->set_dictionary(_texts);
    }
  }
  i = 0;
  while(true) {
    if (_type_objects.get_hero_class(i++, class_tmp) != RC_OK) {
      break;
    }
    if (class_tmp != NULL) {
      class_tmp->set_dictionary(_texts);
    }
  }
  i = 0;
  while(true) {
    if (_type_objects.get_location(i++, location_tmp) != RC_OK) {
      break;
    }
    if (location_tmp != NULL) {
      location_tmp->set_dictionary(_texts);
    }
  }
}

size_t WorldStorage::fill_storage(const std::string& text_db_name, const std::string& template_db_name, const std::string& type_objects_db_name) {
  _texts.fill_storage(text_db_name);
  _templates.fill_storage(template_db_name);
  _type_objects.fill_storage(type_objects_db_name);
  size_t i = 0;
  while (true) {
    CharacterArchetype* archetype_tmp = NULL;
    if (_type_objects.get_character_archetype(i++, archetype_tmp) != RC_OK) {
      break;
    }
    if (archetype_tmp != NULL) {
      archetype_tmp->set_dictionary(&_texts);
    }
  }
  i = 0;
  while(true) {
    HeroClass* class_tmp = NULL;
    if (_type_objects.get_hero_class(i++, class_tmp) != RC_OK) {
      break;
    }
    if (class_tmp != NULL) {
      class_tmp->set_dictionary(&_texts);
    }
  }
  i = 0;
  while(true) {
    Location* location_tmp = NULL;
    if (_type_objects.get_location(i++, location_tmp) != RC_OK) {
      break;
    }
    if (location_tmp != NULL) {
      location_tmp->set_dictionary(&_texts);
    }
  }
  srand(static_cast<size_t>(time(0)));
  for (size_t i = 0; i < MAX_FACTIONS_NUMBER; ++i) {
    FactionTemplate temp;
    _templates.make_faction_template(rand() % _templates.get_factions_count(), temp);
    Faction to_add(temp);
    to_add.set_dictionary(&_texts);
    _factions.push_back(to_add);
  }
  return RC_OK;
}

size_t WorldStorage::clear_storage() {
  _texts.clear_storage();
  _templates.clear_storage();
  _type_objects.clear_storage();
  return RC_OK;
}

size_t WorldStorage::make_hero(Hero*& result, const size_t& level) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  HeroTemplate temp;
  srand(static_cast<size_t>(time(0)));
  _templates.make_hero_template(rand() % _templates.get_heroes_count(), temp);
  HeroClass h_class = NULL;
  _type_objects.get_hero_class(temp._class_id, h_class);
  result = new Hero(temp, *h_class, _factions[temp._faction_id]);
  result->set_dictionary(_texts);
  Inventory* inv = NULL;
  result->get_equipment(inv);
  for (size_t i = 0; i < inv->get_items_count(); ++i) {
    Item* item = NULL;
    inv->get_equipment(i, item);
    item->set_dictionary(&_texts);
  }
  return RC_OK;
}

size_t WorldStorage::make_hero(Hero*& result, const HeroTemplate& data) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  HeroClass* h_class = NULL;
  _type_objects.get_hero_class(data._class_id, h_class);
  result = new Hero(data, *h_class, _factions[data._faction_id]);
  result->set_dictionary(&_texts);
  Inventory* inv = NULL;
  result->get_equipment(inv);
  for (size_t i = 0; i < inv->get_items_count(); ++i) {
    Item* item = NULL;
    inv->get_equipment(i, item);
    item->set_dictionary(&_texts);
  }
  return RC_OK; 
}

size_t WorldStorage::get_faction(const size_t& id, Faction*& result) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  if (id < _factions.size()) {
    result = &(_factions[id]);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t WorldStorage::make_item(Item*& result, const size_t& id, const size_t& level) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  if (id < _templates.get_items_count()) {
    ItemTemplate temp;
    _templates.make_item_template(id, result, level);
    result = new Item(temp);
    result->set_dictionary(&_texts);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }  
}

size_t WorldStorage::make_item(Item*& result, const ItemTemplate& data) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  result = new Item(data);
  result->set_dictionary(&_texts);
  return RC_OK;
}

size_t WorldStorage::make_enemy(Enemy*& result, const size_t& id, const size_t& level) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  if (id < _templates.get_enemies_count()) {
    EnemyTemplate temp;
    srand(static_cast<size_t>(time(0)));
    _templates.make_enemy_template(id, temp, rand() % _factions.size(), level);
    CharacterArchetype* archetype =  NULL; 
    _type_objects.get_character_archetype(temp._archetype_id, archetype);
    result = new Enemy(temp, *archetype, _factions[temp._faction_id]);
    result->set_dictionary(&_texts);
    return RC_OK;
  } else {
    return RC_BAD_INDEX
  }
}

size_t WorldStorage::make_enemy(Enemy*& result, const EnemyTemplate& data) {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  CharacterArchetype* archetype = NULL;
  _type_objects.get_character_archetype(data._archetype_id, archetype);
  result = new Enemy(data, *archetype, _factions[data._faction_id]);
  result->set_dictionary(&_texts);
  return RC_OK;
}

size_t WorldStorage::make_quest(Quest*& result, const size_t& id, const size_t& level) const {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  if (id < _templates.get_quests_count()) {
    QuestTemplate temp;
    _type_objects.make_quest_template(id, temp, level);
    srand(static_cast<size_t>(time(0)));
    if (temp._location_id >= _type_objects.get_locations_count()) {
      temp._location_id = rand() % _type_objects.get_locations_count();
    }
    if (temp._target_id >= _factions.size()) {
      temp._target_id = rand() % _factions.size();
    }
    if (temp._employer_id >= _factions.size()) {
      temp._employer_id = rand() % _factions.size();
    }
    while (true) {
      if (temp._target_id != temp._employer_id) {
        break;
      }
      temp._target_id = rand() % _factions.size();
    }
    Location* location = NULL;
    _type_objects.get_location(temp._location_id, location);
    result = new Quest(temp, *location, _factions[temp._employer_id], _factions[temp._target_id]);
    result->set_dictionary(&_texts);
    for (size_t i = 0; i < result->get_enemies_count(); ++i) {
      Enemy* enemy = NULL;
      result->get_enemies(i, enemy);
      if (enemy != NULL) {
        enemy->set_dictionary(&_texts);
      }
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t WorldStorage::make_quest(Quest*& result, const QuestTemplate& data) {
  if (result != NULL) {
    return RC_BAD_INPUT;
  }
  Location* location = NULL;
  _type_objects.get_location(temp._location_id, location);
  result = new Quest(data, *location, _factions[data._employer_id], _factions[data._target_id]);
  result->set_dictionary(_texts);
  for (size_t i = 0; i < result->get_enemies_count(); ++i) {
    Enemy* enemy = NULL;
    result->get_enemies(i, enemy);
    if (enemy != NULL) {
      enemy->set_dictionary(&_texts);
    }
  }
  return RC_OK;
}

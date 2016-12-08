#ifndef WORLD_STORAGE_H
#define WORLD_STORAGE_H

#include "TextStorage.h"
#include "TemplateStorage.h"
#include "TypeObjectStorage.h"

#include "Hero.h"
#include "Faction.h"
#include "Item.h"
#include "Enemy.h"
#include "Quest.h"

class WorldStorage {
  public:
    WorldStorage() {}
    WorldStorage(const std::string& text_db_name, const std::string& template_db_name, const std::string& type_objects_db_name);
    ~WorlStorage() {}
    size_t fill_storage(const std::string& text_db_name, const std::string& template_db_name, const std::string& type_objects_db_name);
    size_t clear_storage();
    
    size_t get_heroes_count() const { return _templates.get_heroes_count(); }
    size_t get_factions_count() const { return _factions.size(); }
    size_t get_items_count() const { return _templates.get_items_count(); }
    size_t get_enemies_count() const { return _templates.get_enemies_count(); }
    size_t get_quests_count() const { return _templates.get_quests_count(); }
    
    size_t get_archetypes_count() const { return _type_objects.get_archetypes_count(); }
    size_t get_classes_count() const { return _type_objects.get_classes_count(); }
    size_t get_locations_count() const { return _type_objects.get_locations_count(); }
    
    TextStorage* get_dictionary() const { return &_texts; }
    
    size_t get_character_archetype(const size_t& id, CharacterArchetype*& result) const { return _type_objects.get_character_archetype(id, result); }
    size_t get_hero_class(const size_t& id, HeroClass*& result) const { return _type_objects.get_hero_class(id, result); }
    size_t get_location(const size_t& id, Location*& result) const { return _type_objects.get_location(id, result); }
    
    size_t make_hero(Hero*& result, const size_t& level = START_LEVEL) const;
    size_t make_hero(Hero*& result, const HeroTemplate& data) const;
    size_t get_faction(const size_t& id, Faction*& result) const;
    size_t make_item(Item*& result, const size_t& id, const size_t& level = START_LEVEL) const;
    size_t make_item(Item*& result const ItemTemplate& data) const;
    size_t make_enemy(Enemy*& result, const size_t& id, const size_t& level = START_LEVEL) const;
    size_t make_enemy(Enemy*& result, const EnemyTemplate& data) const;
    size_t make_quest(Quest*& result, const size_t& id, const size_t& level = START_LEVEL) const;
    size_t make_quest(Quest*& result, const QuestTemplate& data) const;
  protected:
    TextStorage _texts;
    TemplateStorage _templates;
    TypeObjectStorage _type_objects;
    
    std::vector<Faction> _factions;
};

#endif

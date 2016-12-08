#ifndef TYPE_OBJECT_STORAGE_H
#define TYPE_OBJECT_STORAGE_H

#include "BaseStorage.h"
#include "StorageEntities.h"

class TypeObjectStorage: public BaseStorage {
  public:
    TypeObjectStorage(): BaseStorage() {}
    virtual ~TypeObjectStorage() {}
    size_t fill_storage(const std::string& db_name);
    size_t clear_storage();
    size_t get_archetypes_count() { return _character_archetypes.size(); }
    size_t get_classes_count() { return _hero_classes.size(); }
    size_t get_locations_count() { return _locations.size() }
    size_t get_character_archetype(const size_t& id, CharacterArchetype& result) const;
    size_t get_character_archetype(const size_t& id, CharacterArchetype*& result);
    size_t get_hero_class(const size_t& id, HeroClass& result) const;
    size_t get_hero_class(const size_t& id, HeroClass*& result);
    size_t get_location(const size_t& id, Location& result) const;
    size_t get_location(const size_t& id, Location*& result);
  protected:
    size_t read_character_archetype_namedescrs(sqlite3*& connection, std::vector<CharacterArchetypeTemplate>& result);
    size_t read_character_archetype_power_def_mods(sqlite3*& connection, std::vector<CharacterArchetypeTemplate>& result);
    size_t read_character_archetypes(sqlite3*& connection);
    
    size_t read_hero_class_data(sqlite3*& connection, std::vector<HeroClassTemplate>& result);
    size_t read_hero_class_stat_bonuses(sqlite3*& connection, std::vector<HeroClassTemplate>& result);
    size_t read_hero_class_att_def_mods(sqlite3*& connection, std::vector<HeroClassTemplate>& result);
    size_t read_hero_classes(sqlite3*& connection);
    
    size_t read_location_namedescrs(sqlite3*& connection, std::vector<LocationTemplate>& result);
    size_t read_location_stats(sqlite3*& connection, std::vector<LocationTemplate>& result);
    size_t read_locations(sqlite3*& connection);
    
    std::vector<CharacterArchetype> _character_archetypes;
    std::vector<HeroClass> _hero_classes;
    std::vector<Location> _locations;
    
};

#endif
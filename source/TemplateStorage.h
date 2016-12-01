#ifndef TEMPLATE_STORAGE_H
#define TEMPLATE_STORAGE_H

#include "BaseStorage.h"
#include "StorageEntities.h"

class TemplateStorage: public BaseStorage {
  public:
    TemplateStorage(): BaseStorage() {}
    virtual ~TemplateStorage() {}
    size_t fill_storage(const std::string& db_name);
    size_t clear_storage();
    
    size_t form_name(bool gender, std::string& result) const;
    size_t get_male_name(const size_t& id, std::string& result) const;
    size_t get_female_name(const size_t& id, std::string& result) const;
    size_t get_nickname(const size_t& id, std::string& result) const;
    size_t get_surname(const size_t& id, std::string& result) const;
    size_t form_hero_description(std::string& result) const;
    size_t make_hero_template(const size_t& id, HeroTemplate& result, const size_t& level = START_LEVEL) const;
    
    size_t form_faction_name(std::string& result) const;
    size_t get_faction_firstname(const size_t& id, std::string& result) const;
    size_t get_faction_lastname(const size_t& id, std::string& result) const;
    size_t form_faction_description(std::string& result) const;
    size_t make_faction_template(const size_t& id, FactionTemplate& result) const;
    
    size_t form_item_name(std::string& result, const size_t& kind_id, const size_t& slot_id) const;
    size_t form_item_description(std::string& result) const;
    size_t make_item_template(const size_t& id, ItemTemplate& result, const size_t& level = START_LEVEL) const;
    
    size_t form_enemy_name(std::string& result) const;
    size_t form_enemy_description(std::string& result) const;
    size_t make_enemy_template(const size_t& id, EnemyTemplate& result, const size_t& faction_id, const size_t& level = START_LEVEL) const;
    
    size_t form_quest_name(std::string& result) const;
    size_t form_quest_description(std::string& result) const;
    size_t make_quest_template(const size_t& id, QuestTemplate& result, const size_t& level = START_LEVEL) const;
  protected:
    size_t read_male_names(sqlite3*& connection);
    size_t read_female_names(sqlite3*& connection);
    size_t read_nicknames(sqlite3*& connection);
    size_t read_surnames(sqlite3*& connection);
    size_t read_hero_descriptions(sqlite3*& connection);
    size_t read_hero_data(sqlite3*& connection);
    size_t read_hero_stats(sqlite3*& connection);
    size_t read_hero_personality(sqlite3*& connection);
    size_t read_hero_equipment(sqlite3*& connection);
    size_t read_heroes(sqlite3*& connection);
    
    size_t read_faction_firstnames(sqlite3*& connection);
    size_t read_faction_lastnames(sqlite3*& connection);
    size_t read_faction_descriptions(sqlite3*& connection);
    size_t read_factions(sqlite3*& connection);
    
    size_t read_item_namedescrs(sqlite3*& connection);
    size_t read_item_bonuses(sqlite3*& connection);
    size_t read_item_slots(sqlite3*& connection);
    size_t read_item_data(sqlite3*& connection);
    size_t read_items(sqlite3*& connection);
    
    size_t read_loot_data(sqlite3*& connection);
    
    size_t read_enemy_namedescrs(sqlite3*& connection);
    size_t read_enemy_data(sqlite3*& connection);
    size_t read_enemy_stats(sqlite3*& connection);
    size_t read_enemy_rewards(sqlite3*& connection);
    size_t read_enemies(sqlite3*& connection);
    
    size_t read_quest_namedescrs(sqlite3*& connection);
    size_t read_quest_data(sqlite3*& connection);
    size_t read_quest_rewards(sqlite3*& connection);
    size_t read_quest_bonuses(sqlite3*& connection);
    size_t read_quest_enemies(sqlite3*& connection);
    size_t read_quests(sqlite3*& connection);
    
    size_t power_up_hero(HeroTemplate& result) const;
    size_t power_up_item(ItemTemplate& result) const;
    size_t power_up_enemy(EnemyTemplate& result) const;
    size_t power_up_quest(QuestTemplate& result) const;
    
    std::vector<std::string> _male_names;
    std::vector<std::string> _female_names;
    std::vector<std::string> _nicknames;
    std::vector<std::string> _surnames;
    std::vector<std::string> _hero_description_beginning;
    std::vector<std::string> _hero_description_middle;
    std::vector<std::string> _hero_description_ending;
    
    std::vector<HeroTemplate> _heroes;
    
    std::vector<std::string> _faction_firstname_templates;
    std::vector<std::string> _faction_lastname_templates;
    std::vector<std::string> _faction_description_beginning;
    std::vector<std::string> _faction_description_middle;
    std::vector<std::string> _faction_description_ending;
    
    std::vector<FactionTemplate> _factions;
    
    std::vector<std::string> _item_kind_names; // not the kind names itself, but variations for each kind. NAMES_PER_KIND variations per kind.
    std::vector<std::string> _item_slot_subnames;
    std::vector<std::string> _item_description_beginning;
    std::vector<std::string> _item_description_middle;
    std::vector<std::string> _item_description_ending;
    
    std::vector<ItemTemplate> _items;
    
    std::vector<LootData> _loot_data;
    
    std::vector<std::string> _enemy_firstnames;
    std::vector<std::string> _enemy_lastnames;
    std::vector<std::string> _enemy_description_beginning;
    std::vector<std::string> _enemy_description_middle;
    std::vector<std::string> _enemy_description_ending;
    
    std::vector<EnemyTemplate> _enemies;
    
    std::vector<std::string> _quest_name_first;
    std::vector<std::string> _quest_name_middle;
    std::vector<std::string> _quest_name_last;
    std::vector<std::string> _quest_description_beginning;
    std::vector<std::string> _quest_description_middle;
    std::vector<std::string> _quest_description_ending;
    
    std::vector<QuestTemplate> _quests;
}

#endif
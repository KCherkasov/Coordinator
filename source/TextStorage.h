#ifndef TEXT_STORAGE_H
#define TEXT_STORAGE_H

#include <ctime>
#include <cstdlib>
#include "BaseStorage.h"

class TextStorage: public BaseStorage {
  public:
    TextStorage(): BaseStorage() {}
    virtual ~TextStorage() {}
    size_t fill_storage(const std::string& db_name);
    size_t clear_storage();
    size_t get_stat_name(const size_t& id, std::string& result) const;
    size_t get_personality_stat_name(const size_t& id, std::string& result) const;
    size_t get_gender_name(const size_t& id, std::string& result) const;
    size_t get_health_state_name(const size_t& id, std::string& result) const;
    size_t get_hero_history_name(const size_t& id, std::string& result) const;
    size_t get_player_history_name(const size_t& id, std::string& result) const;
    size_t get_hero_answer(const size_t& answer_id, std::string& result) const;
    size_t get_item_rarity_name(const size_t& rarity_id, std::string& result) const;
    size_t get_item_kind_name(const size_t& kind_id, std::string& result) const;
    size_t get_quest_phase_name(const size_t& phase_id, std::string& result) const;
  protected:
    size_t read_stat_names(sqlite3*& connection);
    size_t read_personality_stat_names(sqlite3*& connection);
    size_t read_gender_names(sqlite3*& connection);
    size_t read_health_state_names(sqlite3*& connection);
    size_t read_hero_history_names(sqlite3*& connection);
    size_t read_player_history_names(sqlite3*& connection);
    size_t read_okay_answers(sqlite3*& connection);
    size_t read_risky_answers(sqlite3*& connection);
    size_t read_greedy_answers(sqlite3*& connection);
    size_t read_item_rarity_names(sqlite3*& connection);
    size_t read_item_kind_names(sqlite3*& connection);
    size_t read_quest_phase_names(sqlite3*& connection);
    // size_t read_miscellaneous(sqlite3*& connection);
    size_t get_okay_answer(std::string& result) const;
    size_t get_risky_answer(std::string& result) const;
    size_t get_greedy_answer(std::string& result) const;

    std::vector<std::string> _stat_names;
    std::vector<std::string> _personality_stat_names;
    std::vector<std::string> _gender_names;
    std::vector<std::string> _health_state_names;
    std::vector<std::string> _hero_history_names;
    std::vector<std::string> _player_history_names;
    std::vector<std::string> _hero_answers_okay;
    std::vector<std::string> _hero_answers_risky;
    std::vector<std::string> _hero_answers_greedy;
    std::vector<std::string> _item_rarity_names;
    std::vector<std::string> _item_kind_names;
    std::vector<std::string> _quest_phase_names;
};

#endif

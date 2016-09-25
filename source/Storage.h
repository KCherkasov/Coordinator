#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>

#include "Miscellaneous.h"
#include "StorageEntities.h"

// Note: this module should be linked with chosen framework to fetch game data.
// ATM proposed frameworks are sqlite and jsoncpp.

class TextStorage {
  public:
    TextStorage();
    ~TextStorage() {};
    static size_t get_task_stat_name(const size_t& index, std::string& result);
    static size_t get_recruitment_stat_name(const size_t& index, std::string& result);
    static size_t get_merc_history_name(const size_t& index, std::string& result);

    static size_t get_item_rarity_name(const size_t& index, std::string& result);
    static size_t get_item_kind_name(const size_t& index, std::string& result);

    static size_t get_merc_answer(const size_t& index, std::string& result);

    static size_t get_contract_answer(const size_t& index, std::string& result);
    static size_t get_contract_reaction(const size_t& index, std::string& result);

    static size_t get_name(const bool& gender, std::string& result);
  protected:
    static size_t get_male_name(const size_t& index, std::string& result);
    static size_t get_female_name(const size_t& index, std::string& result);
    static size_t get_nickname(const size_t& index, std::string& result);
    static size_t get_surname(const size_t& index, std::string& result);

    static std::vector<std::string> _male_names;
    static std::vector<std::string> _female_names;
    static std::vector<std::string> _nicknames;
    static std::vector<std::string> _surnames;

    static std::vector<std::string> _task_stat_names;
    static std::vector<std::string> _recruitment_stat_names;
    static std::vector<std::string> _item_rarity_names;
    static std::vector<std::string> _item_kind_names;
    static std::vector<std::string> _merc_history_names;

    static std::vector<std::vector<std::string> > _merc_answers;
    static std::vector<std::vector<std::string> > _contract_answers;
    static std::vector<std::vector<std::string> > _contract_reactions;      
};

#endif

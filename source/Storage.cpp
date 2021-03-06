#include "Storage.h"

std::vector<std::string> TextStorage::_male_names;
std::vector<std::string> TextStorage::_female_names;
std::vector<std::string> TextStorage::_nicknames;
std::vector<std::string> TextStorage::_surnames;

std::vector<std::string> TextStorage::_enemy_stat_names;
std::vector<std::string> TextStorage::_merc_stat_names;
std::vector<std::string> TextStorage::_recruitment_stat_names;
std::vector<std::string> TextStorage::_item_stat_names;
std::vector<std::string> TextStorage::_item_rarity_names;
std::vector<std::string> TextStorage::_item_kind_names;
std::vector<std::string> TextStorage::_merc_history_names;

std::vector<std::vector<std::string> > TextStorage::_merc_answers;
std::vector<std::vector<std::string> > TextStorage::_contract_answers;
std::vector<std::vector<std::string> > TextStorage::_contract_reactions;

TextStorage::TextStorage() {
  _male_names.clear();
  _female_names.clear();
  _nicknames.clear();
  _surnames.clear();
  _enemy_stat_names.clear();
  _merc_stat_names.clear();
  _recruitment_stat_names.clear();
  _item_stat_names.clear();
  _item_rarity_names.clear();
  _item_kind_names.clear();
  _merc_history_names.clear();
}

size_t TextStorage::get_male_name(const size_t& index, std::string& result) {
  if (index < _male_names.size()) {
    result.clear();
    result = _male_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_female_name(const size_t& index, std::string& result) {
  if (index < _female_names.size()) {
    result.clear();
    result = _female_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_surname(const size_t& index, std::string& result) {
  if (index < _surnames.size()) {
    result.clear();
    result = _surnames[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_nickname(const size_t& index, std::string& result) {
  if (index < _nicknames.size()) {
    result.clear();
    result = _surnames[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_enemy_stat_name(const size_t& index, std::string& result) {
  if (index < _enemy_stat_names.size()) {
    result.clear();
    result = _enemy_stat_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_merc_stat_name(const size_t& index, std::string& result) {
  if (index < _merc_stat_names.size()) {
    result.clear();
    result = _merc_stat_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_item_stat_name(const size_t& index, std::string& result) {
  if (index < _item_stat_names.size()) {
    result.clear();
    result = _item_stat_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_recruitment_stat_name(const size_t& index, std::string& result) {
  if (index < _recruitment_stat_names.size()) {
    result.clear();
    result = _recruitment_stat_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_merc_history_name(const size_t& index, std::string& result) {
  if (index < _merc_history_names.size()) {
    result.clear();
    result = _merc_history_names[index];
    return RC_OK;   
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_item_rarity_name(const size_t& index, std::string& result) {
  if (index < _item_rarity_names.size()) {
    result.clear();
    result = _item_rarity_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_item_kind_name(const size_t& index, std::string& result) {
  if (index < _item_kind_names.size()) {
    result.clear();
    result = _item_kind_names[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_merc_answer(const size_t& index, std::string& result) {
  if (index < _merc_answers.size()) {
    result.clear();
    result = _merc_answers[index][roll_dice(_merc_answers[index].size())];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_contract_answer(const size_t& index, std::string& result) {
  if (index < _contract_answers.size()) {
    result.clear();
    result = _contract_answers[index][roll_dice(_contract_answers[index].size())];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_contract_reaction(const size_t& index, std::string& result) {
  if (index < _contract_reactions.size()) {
    result.clear();
    result = _contract_reactions[index][roll_dice(_contract_reactions[index].size())];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t TextStorage::get_name(const bool& gender, std::string& result) {
  std::string buffer;
  buffer.clear();
  if (gender == MALE_GENDER) {
    get_male_name(roll_dice(_male_names.size()), buffer);
  } else {
    get_female_name(roll_dice(_female_names.size()), buffer);
  }
  buffer.append(" ");
  result.clear();
  result += buffer;
  buffer.clear();
  if (roll_dice() % 2 == 0) {
    buffer.append("\"");
    get_nickname(roll_dice(_nicknames.size()), buffer);
    buffer.append("\" ");
    result += buffer;
    buffer.clear();
  }
  buffer = get_surname(roll_dice(_surnames.size()), buffer);
  result += buffer;
  buffer.clear();
  return RC_OK;
}


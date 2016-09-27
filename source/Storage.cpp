#include "Storage.h"

std::vector<std::string> TextStorage::_male_names;
std::vector<std::string> TextStorage::_female_names;
std::vector<std::string> TextStorage::_nicknames;
std::vector<std::string> TextStorage::_surnames;

std::vector<std::string> TextStorage::_task_stat_names;
std::vector<std::string> TextStorage::_recruitment_stat_names;
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
  _task_stat_names.clear();
  _recruitment_stat_names.clear();
  _item_rarity_names.clear();
  _item_kind_names.clear();
  _merc_history_names.clear();
}

size_t TextStorage::get_male_name(const size_t& index, std::string& result) {

}

size_t TextStorage::get_female_name(const size_t& index, std::string& result) {

}

size_t TextStorage::get_surname(const size_t& index, std::string& result) {

}

size_t TextStorage::get_nickname(const size_t& index, std::string& result) {

}

size_t TextStorage::get_task_stat_name(const size_t& index, std::string& result) {
  if (index < _task_stat_names.size()) {
    result.clear();
    result = _task_stat_names[index];
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


#include "MercSpec.h"

size_t MercSpec::get_name(std::string& result) {
  result.clear();
  result = _name;
  return RC_OK;
}

size_t MercSpec::get_description(std::string& result) {
  result.clear();
  result = _description;
  return RC_OK;
}

size_t MercSpec::get_base_merc_stats(std::vector<size_t>& result) {
  result.clear();
  result = _base_merc_stats;
  return RC_OK;
}

size_t MercSpec::get_base_merc_stats(const size_t& index, size_t& result) {
  if (index < _base_merc_stats.size()) {
    result = _base_merc_stats[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t MercSpec::set_name(const std::string& value) {
  if (!value.empty()) {
    _name.clear();
    _name = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t MercSpec::set_description(const std::string& value) {
  if (!value.empty()) {
    _description.clear();
    _description = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t MercSpec::set_base_merc_stats(const std::vector<size_t>& value) {
  if (value.size() == SI_SIZE) {
    _base_merc_stats.clear();
    _base_merc_stats = value;
    return RC_OK;
  } else {
    return RC_BAD_SIZE;
  }
}

size_t MercSpec::set_base_merc_stats(const size_t& index, const size_t& value) {
  if (index < _base_merc_stats.size()) {
    _base_merc_stats[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}


size_t MercSpec::what(std::string& result) {
  result.clear();
  result.append("Mercenary class info:\n");
  result.append("---------------------\n");
  result += _name;
  result.append("\n\"");
  result += _description;
  result.append("\"\n");
  result.append("class base skills:\n");
  for (size_t i = 0; i < _base_merc_stats.size(); ++i) {
    std::string buffer;
    buffer.clear();
    TextStorage::get_merc_stat_name(i, buffer);
    result += buffer;
    result.append(": ");
    buffer.clear();
    convert_to_string<size_t>(_base_merc_stats[i], buffer);
    result += buffer;
    result.append("\n");
  }
  return RC_OK;
}


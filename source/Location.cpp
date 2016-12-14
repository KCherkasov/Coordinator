#include "Location.h"

size_t Location::_id = FREE_ID;

Location::Location(LocationTemplate& data): _own_id(data._own_id), _name(data._name), _description(data._description), _to_delete(false), _stats(data._stats) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_id < _own_id) {
      _id = _own_id;
    }
  }
}

size_t Location::get_stats(std::vector<size_t>& result) const {
  result.clear();
  result = _stats;
  return RC_OK;
}

size_t Location::get_stats(const size_t& index, size_t& result) const {
  if (index < _stats.size()) {
    result = _stats[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Location::what(std::string& result) const {
  result.clear();
  std::string buffer;
  buffer.clear();
  result += _name;
  result.append("\nStats:\n");
  for (size_t i = 0; i < _stats.size(); ++i) {
    _dictionary->get_location_stat_name(i, buffer);
    buffer.append(": ");
    result += buffer;
    buffer.clear();
    convert_to_string(_stats[i], buffer);
    buffer.append("\n");
    result += buffer;
    buffer.clear();
  }
  result.append("\"");
  result += _description;
  result.append("\"");
  return RC_OK;
}

size_t Location::short_what(std::string& result) const {
  result.clear();
  result += _name;
  result.append("\n\"");
  result += _description;
  result.append("\"");
  return RC_OK;
}


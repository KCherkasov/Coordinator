#include "Mercenary.cpp"

size_t Mercenary::_id = SIZE_T_DEFAULT_VALUE;

Mercenary::Mercenary(const MercenaryTemplate& data, MercSpec& spec): _own_id(data._own_id), _name(data._name), _description(data._description), _level(START_LEVEL), _stats(data._stats), _spec(spec), _experience(data._experience), _personality(data._personality), _equipment(data._equipment) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_id > _own_id) {
      _id = _own_id;
    }
  }
  if (data._level > _level) {
    _level = data._level;
  }
}

size_t Mercenary::get_merc_spec(MercSpec& result) const {
  result = _spec;
  return RC_OK;
}

size_t Mercenary::get_experience(std::vector<size_t>& result) const {
  result.clear();
  result = _experience;
  return RC_OK;
}

size_t Mercenary::get_experience(const size_t& index, size_t& result) const  {
  if (index < _experience.size()) {
    result = _experience[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::get_personality(std::vector<size_t>& result) const {
  result.clear();
  result = _personality;
  return RC_OK;
}

size_t Mercenary::get_personality(const size_t& index, size_t& result) const {
  if (index < _personality.size()) {
    result = _personality[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::get_equipment(Inventory& result) const {
  result = _equipment;
  return RC_OK;
}


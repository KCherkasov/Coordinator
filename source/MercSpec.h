#ifndef TYPE_OBJECTS_H
#define TYPE_OBJECTS_H

#include <string>
#include <vector>

#include "Miscellaneous.h"
#include "StorageEntities.h"
#include "Storage.h"

class MercSpec {
  public:
    MercSpec(const MercSpecTemplate& table): _name(table._name), _description(table._description), _base_task_stats(table._base_task_stats) {}
    ~MercSpec() {}
    size_t get_name(std::string& result);
    size_t get_description(std::string& result);
    size_t get_base_task_stats(std::vector<size_t>& result);
    size_t get_base_task_stats(const size_t& index, size_t& result);
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    size_t set_base_task_stats(const std::vector<size_t>& value);
    size_t set_base_task_stats(const size_t& index, const size_t& value);
    size_t what(std::string& result);

    MercSpec& operator = (const MercSpec& rhs) {
      if (!_name.empty()) {
        _name.clear();
      }
      _name = rhs._name;
      if (!_description.empty()) {
        _description.clear();
      }
      if (!_base_task_stats.empty()) {
        _base_task_stats.clear();
      }
      _base_task_stats = rhs._base_task_stats;
      return *this;
    }

  protected:
    std::string _name;
    std::string _description;
    std::vector<size_t> _base_task_stats;
}

#endif

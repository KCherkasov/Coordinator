#ifndef LOCATION_H
#define LOCATION_H

#include "GameObject.h"
#include "Miscellaneous.h"

class Location: public GameObject {
  public:
    Location(LocationTemplate& data);
    virtual ~Location() {}
    size_t get_stats(std::vector<size_t>& result) const;
    size_t get_stats(const size_t& index, LocationObject& result) const;
    size_t get_fees(const size_t& index, LocationObject& result) const;
    size_t get_fees(std::vector<size_t>& result) const;
    size_t what(std::string& result) const;
    size_t short_what(std::string& result) const;
    size_t update() { return RC_OK; }
    size_t set_stats(const std::vector<size_t>& value);
    size_t set_stats(const size_t& index, const size_t& value);
    size_t set_fees(const std::vector<LocationObject>& value);
    size_t set_fees(const size_t& index, const LocationObject& value);
  protected:
    static size_t _id;
    std::vector<size_t> _stats;
    std::vector<LocationObject> _fees;
};

#endif
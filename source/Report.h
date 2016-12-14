#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <fstream>

#include "Miscellaneous.h"

class Report {
  public:
    Report();
    ~Report() {}
    size_t get_topic(std::string& result) const;
    size_t get_subtopic_1(std::string& result) const;
    size_t get_subtopic_2(std::string& result) const;
    size_t get_content(std::string& result) const;
    size_t set_topic(const std::string& value);
    size_t set_subtopic_1(const std::string& value);
    size_t set_subtopic_2(const std::string& value);
    size_t set_content(const std::string& value);
    size_t what(std::string& result) const;
  private:
    std::string _topic;
    std::string _subtopic_1;
    std::string _subtopic_2;
    std::string _content;
};

#endif
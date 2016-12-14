#include "Report.h"

Report::Report() {
  _topic.clear();
  _subtopic_1.clear();
  _subtopic_2.clear();
  _content.clear();
}

size_t Report::get_topic(std::string& result) const {
  result.clear();
  result = _topic;
  return RC_OK;
}

size_t Report::get_subtopic_1(std::string& result) const {
  result.clear();
  result = _subtopic_1;
  return RC_OK;
}

size_t Report::get_subtopic_2(std::string& result) const {
  result.clear();
  result += _subtopic_2;
  return RC_OK;
}

size_t Report::get_content(std::string& result) const {
  result.clear();
  result += _content;
  return RC_OK;
}

size_t Report::set_topic(const std::string& value) {
  _topic.clear();
  _topic = value;
  return RC_OK;
}

size_t Report::set_subtopic_1(const std::string& value) {
  _subtopic_1.clear();
  _subtopic_1 = value;
  return RC_OK;
}

size_t Report::set_subtopic_2(const std::string& value) {
  _subtopic_2.clear();
  _subtopic_2 = value;
  return RC_OK;
}

size_t Report::set_content(const std::string& value) {
  _content.clear();
  _content = value;
  return RC_OK;
}

size_t Report::what(std::string& result) const {
  result.clear();
  if (!_topic.empty()) {
    result += _content;
    result.append("\n\n");
  }
  if (!_subtopic_1.empty()) {
    result += _subtopic_1;
    result.append("\n");
  }
  if (!_subtopic_2.empty()) {
    result += _subtopic_2;
    result.append("\n");
  }
  if (!_content.empty()) {
    result += _content;
  }
  return RC_OK;
}

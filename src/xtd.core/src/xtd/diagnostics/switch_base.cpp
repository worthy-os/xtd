#include "../../../include/xtd/diagnostics/switch_base.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

const switch_base::attribute_collection& switch_base::attributes() const noexcept {
  return attributes_;
}

switch_base::attribute_collection& switch_base::attributes() noexcept {
  return attributes_;
}

void switch_base::attributes(const attribute_collection& attributes) noexcept {
  attributes_ = attributes;
}

const string& switch_base::description() const noexcept {
  return description_;
}

const string& switch_base::display_name() const noexcept {
  return display_name_;
}

bool switch_base::equals(const object& obj) const noexcept {
  return is<switch_base>(obj) && equals(static_cast<const switch_base&>(obj));
}

bool switch_base::equals(const switch_base& other) const noexcept {
  return display_name_ == other.display_name_ && description_ == other.description_ && attributes_ == other.attributes_ && switch_setting_ == other.switch_setting_ && value_ == other.value_;
}

switch_base::switch_base(const string& display_name, const string& description) : display_name_(display_name), description_(description) {
}

switch_base::switch_base(const string& display_name, const string& description, const string& default_switch_value) : display_name_(display_name), description_(description), value_(default_switch_value) {
}

int32 switch_base::switch_setting() const noexcept {
  return switch_setting_;
}

void switch_base::switch_setting(int32 switch_setting) {
  if (switch_setting_ == switch_setting) return;
  switch_setting_ = switch_setting;
  on_switch_setting_changed();
}

const string& switch_base::value() const noexcept {
  return value_;
}

void switch_base::value(const string& value) {
  if (value_ == value) return;
  value_ = value;
  on_value_changed();
}

array<string> switch_base::get_supported_attributes() const noexcept {
  return {};
}

void switch_base::on_switch_setting_changed() {
}

void switch_base::on_value_changed() {
}

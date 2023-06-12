#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(directory_valid_exists_string_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      auto d = environment::get_folder_path(environment::special_folder::common_application_data);
      xtd::tunit::directory_valid::exists(d);
    }
  };
}

void test_(directory_valid_exists_string_succeed_tests, test_output) {
  auto [output, result] = run_test_("directory_valid_exists_string_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED directory_valid_exists_string_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(directory_valid_exists_string_succeed_tests, test_result) {
  auto [output, result] = run_test_("directory_valid_exists_string_succeed_tests.*");
  assert_value_(0, result);
}
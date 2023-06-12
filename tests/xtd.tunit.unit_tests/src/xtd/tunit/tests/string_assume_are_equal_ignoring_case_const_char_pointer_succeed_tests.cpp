#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(string_assume_are_equal_ignoring_case_const_char_pointer_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      const char* s = "VALUE";
      xtd::tunit::string_assume::are_equal_ignoring_case("value", s);
    }
  };
}

void test_(string_assume_are_equal_ignoring_case_const_char_pointer_succeed_tests, test_output) {
  auto [output, result] = run_test_("string_assume_are_equal_ignoring_case_const_char_pointer_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED string_assume_are_equal_ignoring_case_const_char_pointer_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(string_assume_are_equal_ignoring_case_const_char_pointer_succeed_tests, test_result) {
  auto [output, result] = run_test_("string_assume_are_equal_ignoring_case_const_char_pointer_succeed_tests.*");
  assert_value_(0, result);
}
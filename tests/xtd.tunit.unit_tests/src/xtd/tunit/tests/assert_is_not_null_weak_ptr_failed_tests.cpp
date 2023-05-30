#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <memory>

namespace xtd::tunit::tests {
  class test_class_(assert_is_not_null_weak_ptr_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::weak_ptr<int> p;
      xtd::tunit::assert::is_not_null(p);
    }
  };
}

void test_(assert_is_not_null_weak_ptr_failed_tests, test_output) {
  auto [result, output] = run_test_("assert_is_not_null_weak_ptr_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  assert_is_not_null_weak_ptr_failed_tests.test_case_failed\n"
    "    Expected: not null\n"
    "    But was:  null\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assert_is_not_null_weak_ptr_failed_tests, test_result) {
  auto [result, output] = run_test_("assert_is_not_null_weak_ptr_failed_tests.*");
  assert_value_(1, result);
}
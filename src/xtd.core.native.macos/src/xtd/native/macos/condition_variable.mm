#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable.h>
#include "../../../../include/xtd/native/macos/mutex.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>
#include <pthread.h>

using namespace xtd::native;

intmax_t condition_variable::create() {
  pthread_cond_t* handle = new pthread_cond_t;
  if (handle == nullptr) return reinterpret_cast<intmax_t>(MUTEX_FAILED);
  return reinterpret_cast<intmax_t>(handle);
}

void condition_variable::destroy(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  pthread_cond_destroy(reinterpret_cast<pthread_cond_t*>(handle));
  delete reinterpret_cast<pthread_cond_t*>(handle);
}

void condition_variable::pulse(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  pthread_cond_signal(reinterpret_cast<pthread_cond_t*>(handle));
}

void condition_variable::pulse_all(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  pthread_cond_broadcast(reinterpret_cast<pthread_cond_t*>(handle));
}

bool condition_variable::wait(intmax_t handle, intmax_t critical_section_handle, int_least32_t milliseconds_timeout) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return false;
  if (reinterpret_cast<std::recursive_mutex*>(critical_section_handle) == nullptr) return false;

  auto mutex = reinterpret_cast<std::recursive_mutex*>(critical_section_handle)->native_handle();
  
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;

  return pthread_cond_timedwait(reinterpret_cast<pthread_cond_t*>(handle), mutex, &timeout) == 0;
}
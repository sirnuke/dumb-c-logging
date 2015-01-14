#include "logging.h"

static const char *TAG = "DumbLogging";

int main()
{
  int i = 42;
  DUMB_LOGGING_TODO("Make this!");
  DUMB_LOGGING_VERBOSE("Extra noisy information like: (%i)", i);
  DUMB_LOGGING_INFO("Norma information!");
  DUMB_LOGGING_WARN("A warning, but probably nothing critical.  Probably");
  DUMB_LOGGING_ERROR("SEGFAULT INCOMING");
  return 0;
}

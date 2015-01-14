#include "logging.h"

static const char *TAG = "DumbLogging";

int main()
{
  int i = 42;
  TODO("Make this!");
  VERBOSE("Extra noisy information like: (%i)", i);
  INFO("Norma information!");
  WARN("A warning, but probably nothing critical.  Probably");
  ERROR("SEGFAULT INCOMING");
  return 0;
}

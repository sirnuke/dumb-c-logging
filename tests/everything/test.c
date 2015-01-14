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
  T("Make this!");
  V("Extra noisy information like: (%i)", i);
  I("Norma information!");
  W("A warning, but probably nothing critical.  Probably");
  E("SEGFAULT INCOMING");
  todo(__LINE__, __FUNCTION__, TAG, "Make this!");
  verbose(__LINE__, __FUNCTION__, TAG, "Extra noisy information like: (%i)", i);
  info(__LINE__, __FUNCTION__, TAG, "Norma information!");
  warn(__LINE__, __FUNCTION__, TAG, "A warning, but probably nothing critical.  Probably");
  error(__LINE__, __FUNCTION__, TAG, "SEGFAULT INCOMING");
  return 0;
}

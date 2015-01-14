#include "logging.h"

static const char *TAG = "DumbLogging";

int main()
{
  int i = 42;
  dumb_logging("TODO", __LINE__, __FUNCTION__, TAG, "Make this!");
  dumb_logging("Verbose", __LINE__, __FUNCTION__, TAG, "Extra noisy information like: (%i)", i);
  dumb_logging("Info", __LINE__, __FUNCTION__, TAG, "Norma information!");
  dumb_logging("Warn", __LINE__, __FUNCTION__, TAG, "A warning, but probably nothing critical.  Probably");
  dumb_logging("Error", __LINE__, __FUNCTION__, TAG, "SEGFAULT INCOMING");
  return 0;
}

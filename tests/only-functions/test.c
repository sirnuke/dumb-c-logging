#include "logging.h"

static const char *TAG = "DumbLogging";

int main()
{
  int i = 42;
  todo(__LINE__, __FUNCTION__, TAG, "Make this!");
  verbose(__LINE__, __FUNCTION__, TAG, "Extra noisy information like: (%i)", i);
  info(__LINE__, __FUNCTION__, TAG, "Norma information!");
  warn(__LINE__, __FUNCTION__, TAG, "A warning, but probably nothing critical.  Probably");
  error(__LINE__, __FUNCTION__, TAG, "SEGFAULT INCOMING");
  return 0;
}

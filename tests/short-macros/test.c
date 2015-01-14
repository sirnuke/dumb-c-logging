#include "logging.h"

static const char *TAG = "DumbLogging";

int main()
{
  int i = 42;
  T("Make this!");
  V("Extra noisy information like: (%i)", i);
  I("Norma information!");
  W("A warning, but probably nothing critical.  Probably");
  E("SEGFAULT INCOMING");
  return 0;
}

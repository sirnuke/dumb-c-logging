#include "logging.h"
static const char *TAG = "KeepThisShort";
int main()
{
  int ret = 1;
  WARN("Here Be Dragons --> logging.h");
  VERBOSE("%s", "extra string");
  INFO("And the winning numbers are %i, %i, %i, & %i", 10, 18, 92, 1);
  TODO("Reimplement facebook!");
  ERROR("Critical error, quitting (%i)", ret);
  return ret;
}

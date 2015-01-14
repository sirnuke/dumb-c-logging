Dumb Logging
==============

* Dumb Logging is soooo dumb that you'll have to recompile pretty much
  everything anytime you tweak it!
* Dumb Logging is soooo dumb that when it was told it's not called
  c-pound; it responded "c-number sign?"
* Dumb Logging is soooo dumb that it only does one thing, and does it
  well enough, I hope, for many people in many cases.

But Really
----------

Dumb Logging is pretty much what it says on the tin: it's a single header
file that implements a simple, very dumb logging system.

* Enable DUMB\_LOGGING\_MEDIUM\_MACROS (default), you get TODO(tag,
  message, ...); VERBOSE(...), INFO(...), WARN(...), ERROR(...).
* Enable DUMB\_LOGGING\_SHORT\_MACROS you get single letter variants.
* Disable both and you get long DUMB\_LOGGING\_WARN macros.
* Enable DUMB\_LOGGING\_NO\_MACROS and you get the global, static
  function dumb\_logging(level, line, function, tag, message, ...) and
  nothing else.
* Enable DUMB\_LOGGING\_FUNCTIONS and you get info(line, function, tag,
  message, ...) static globals.  Keep your Best C++ Practices A++++
  Would Hire Again Award for avoiding dirty macros (though we both know
  about that goto you used, but don't worry that secret is safe).
* Enable some other combination and you hopefully get about what you
  expect.

But What Really
---------------

It's what it says on the tin: a simple, dumb logging system for C and C++.
It uses some preprocessor magic to make things Just Work, and wraps
around C style printfs.  It's hopefully flexible and powerful enough
to work well for most projects with minimal tweak, and simple enough to
tweak the source code if needed.


But Why
-------

To be frank, I've written at least a dozen variants on this, and
I'm tiring of going through "ok, which project has the most resent
implementation to copy over?"  So create one copy that borrows Good
Ideas\* from every logging system I've worked with.

\*Agreement may vary

Personally, I've found frequent, well formatted outputs to: A) act as a
surprising decent self-documentation, enforcing action/intent in twitter
like-summaries, and B) help quickly catch certain domains of errors;
wait why is Y happening before X, C crashed on a NULL pointer - wait,
A originally received the NULL, etc.  Having a system up front helps
avoid needing one later when log files start to grow.

But More Questions
------------------

* What does it work on?
  * GCC and Clang on Linux, Visual Studio 2010 last I checked.
    Hopefully anything modern!
* Do I get thread safety?
  * Hopefully no worse than what printf variants already provide!
* Do I get file logging?
  * No!  Hopefully not too painful to implement yourself!
* Do I get channel selection at runtime?
  * No!  Hopefully not too painful to implement yourself!
* Do I get FEATURE?
  * Unlikely!  Write it yourself!
* In retrospect, what the code calls "levels" should be called "channels".
  * Is that a question!?  But, yes!  Maybe if/when I revisit this!
* Do I get global polluting symbols and processor directives?  Yes!
* What is a tag?
  * More or less identical to the Android concept.
  * I typically set a static const char \*TAG at the beginning of
    each file.
  * Replacing this in the header with \_\_FILE\_\_ should do usually
    get the job done.

But Usage and Code
------------------

```
#include "logging.h"
static const char *TAG = "KeepThisShort
int main()
{
  Verbose("And the winning numbers are %i %i %i %i %s", 10, 18, 92, 1, "extra string");
  return 0;
}
```

But License
-----------

Public Domain!  Go hog wild!  Lock it away in a proprietary codebase!
Slap a GPL on it and go to war against the dirty BSD heathens!

See LICENSE or [unlicense.org](http://unlicense.org/) for more details.


But Jokes
---------

* Dumb Logging is soooo dumb that it expressed an opinion on gun control
  on the internet.
* Dumb Logging is soooo dumb that it has an equally dumb, shell scripting
  based test suite.
* Dumb Logging is soooo dumb that it bought a swiss made watch in China.
  For full price.

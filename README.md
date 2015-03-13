Dumb Logging
==============

* Dumb Logging is soooo dumb that you'll have to recompile pretty much
  everything anytime you tweak it!
* Dumb Logging is soooo dumb that when it was told it's not called
  c-pound, it responded "c-number sign?"
* Dumb Logging is soooo dumb that it only does one thing, but hopefully
  does it just well enough.

But Really
----------

Dumb Logging is pretty much what it says on the tin: it's a single header
file that implements a simple, very dumb logging system.

* Five channels: TODO, VERBOSE, INFO, WARN, ERROR.
* Macros or functions.  Macros depend on a locally accessible variable
  named TAG.  Functions don't do much legwork for you.
* Enable *DUMB\_LOGGING\_MEDIUM\_MACROS* (default), you get
  TODO(message, ...) and similar.
* Enable *DUMB\_LOGGING\_SHORT\_MACROS* you get single letter variants.
* Disable both and you only get long DUMB\_LOGGING\_WARN macros.
* Enable *DUMB\_LOGGING\_NO\_MACROS* and you get the global, static
  function dumb\_logging(channel, line, function, tag, message, ...) and
  nothing else.
* Enable DUMB\_LOGGING\_FUNCTIONS and you get info(line, function, tag,
  message, ...) static globals.  Keep your Best C++ Practices A++++
  Would Hire Again Award For Avoiding Dirty Macros (though we both know
  about that Goto incident).
* Enable some other combination and you hopefully get about what you
  expect.

But Example Please
------------------

```
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
```

Which nets you:

```
[Warn]    KeepThisShort:main@6              Here Be Dragons --> logging.h
[Verbose] KeepThisShort:main@7              extra string
[Info]    KeepThisShort:main@8              And the winning numbers are 10, 18, 92, & 1
[TODO]    KeepThisShort:main@9              Reimplement facebook!
[Error]   KeepThisShort:main@10             Critical error, quitting (1)
```

And that's it!

But What Really
---------------

It's arguable more of a dumb output formatting system, but only for
logging.  It borrows ideas from various other logging code that I've
written or used over the years, stays reasonably true to print, and
contains just enough magic to make things Just Work.  Hopefully just
powerful enough to work well for some projects, while simple enough to
painlessly modify for many others.

But Why
-------

Over the years, I've written at least a dozen similar variants to
this.  Finding a recent implementation, removing any project specific
dependencies, and updating it for a new project every three to six months
has grown tiring.

So instead, this is a copy that borrows Good Ideas\* from other logging
systems, and tweaked to be reasonably generic for most codebases.

(\*Agreement may vary)

On a more philosophical note, I've found frequent, well formatted outputs
to: A) act as a mild form of self-documentation, enforcing action/intent
in twitter like-summaries, and B) help quickly catch certain domains of
errors; wait why is Y happening before X, C crashed on a NULL pointer -
wait, A originally received the NULL, etc.

As for TAG and Macros, because Android, Inc. or Google or whomever had
something figured out, and Macros because I've never really qualified
for the Best C++ Practices A++++ Would Hire Again Award For Avoiding
Dirty Macros.

But More Questions
------------------

* What does it work on?
  * GCC and Clang on Linux, Visual Studio 2010 last time I checked.
    Hopefully anything modern!

* Do I get thread safety?
  * Hopefully no worse than what printf variants already provide!

* Do I get file logging?
  * No!  Hopefully not too painful to implement yourself!

* Do I get channel selection at runtime?
  * No!  Hopefully not too painful to implement yourself!

* Do I get FEATURE?
  * Unlikely!  Write it yourself!

* What's runtime and compile time performance like?
  * Not sure!  But I don't think it's a real burden, outside requiring
    recompiles everytime you tweak logging.h (so don't do that often).

* Why is runtime a single word, but compile time isn't?
  * I was just wondering that. Runtime has that Germanic thing were you
    create new words by smashing simplier ones together, but I guess
    compile time didn't get the memo.

* Do I get global namespace polluting symbols and preprocessor directives?
  * Yes!

* What is a tag?
  * More or less identical to the Android concept.
  * I typically set a static const char \*TAG at the beginning of
    each file.
    * Something like static const char \*TAG = \_\_FILE\_\_ should also
      work well.

But License
-----------

Public Domain; see LICENSE or
[unlicense.org](http://unlicense.org/) for more details.

Go hog wild!  Lock it away in a proprietary codebase!  Slap a GPL sticker on it and
go to war against the dirty BSD heathens!

But Jokes
---------

* Dumb Logging is soooo dumb that it expressed an opinion on gun control
  on the internet.
* Dumb Logging is soooo dumb that it has an equally dumb, shell scripting
  based test suite.
* Dumb Logging is soooo dumb that it bought a swiss made watch in China.
  For the list price.

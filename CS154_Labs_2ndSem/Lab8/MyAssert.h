#ifndef NDEBUG
#   define codeassert(arg) \
    do { \
        if (!arg) { \
            std::cerr << program_invocation_short_name << ": "  __FILE__ \
  << ":" << __LINE__ << ": " << __FUNCTION__ << ": " << "Assertion `" #arg "` failed." << std::endl; \
                      std::abort();\
        } \
    } while (false)
#else
#   define codeassert(arg) do {} while (false)
#endif

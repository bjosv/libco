#if defined(__clang__)
  #pragma clang diagnostic ignored "-Wparentheses"

  /* placing code in section(text) does not mark it executable with Clang. */
  #undef  LIBCO_MPROTECT
  #define LIBCO_MPROTECT
#endif

#if defined(__clang__) || defined(__GNUC__)
  #if defined(__i386__)
    #warning ">> USING: x86.c"
    #include "x86.c"
  #elif defined(__amd64__)
    #warning ">> USING: amd64.c"
    #include "amd64.c"
  #elif defined(__arm__)
    #warning ">> USING: arm.c"
    #include "arm.c"
  #elif defined(__aarch64__)
    #warning ">> USING: aarch64.c"
    #include "aarch64.c"
  #elif defined(__powerpc64__) && defined(_CALL_ELF) && _CALL_ELF == 2
    #warning ">> USING: ppc64v2.c"
    #include "ppc64v2.c"
  #elif defined(_ARCH_PPC) && !defined(__LITTLE_ENDIAN__)
    #warning ">> USING: ppc.c"
    #include "ppc.c"
  #elif defined(_WIN32)
    #warning ">> USING: fiber.c"
    #include "fiber.c"
  #else
    #warning ">> USING: sjlj.c"
    #include "sjlj.c"
  #endif
#elif defined(_MSC_VER)
  #if defined(_M_IX86)
    #pragma message ( ">> USING: x86.c" )
    #include "x86.c"
  #elif defined(_M_AMD64)
    #pragma message ( ">> USING: amd64.c" )
    #include "amd64.c"
  #else
    #pragma message ( ">> USING: fibet.c" )
    #include "fiber.c"
  #endif
#else
  #error "libco: unsupported processor, compiler or operating system"
#endif

#ifdef _WIN32
#define OS_NAME "Windows"
#elif __linux__
#define OS_NAME "Linux"
#elif __APPLE__
#define OS_NAME "macOS"
#else
#define OS_NAME "Unknown"
#endif
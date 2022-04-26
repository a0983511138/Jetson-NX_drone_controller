find_path(JETSONGPIO_INCLUDE_DIRS JetsonGPIO.h
    "/usr/include/JetsonGPIO"
    "/usr/local/include/JetsonGPIO"
    )
find_library(JETSONGPIO_LIBRARIES libJetsonGPIO.so
    "/usr/lib"
    "/usr/local/lib"
    )
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(JetsonGPIO
    FOUND_VAR JetsonGPIO_FOUND
    REQUIRED_VARS JETSONGPIO_INCLUDE_DIRS JETSONGPIO_LIBRARIES
)

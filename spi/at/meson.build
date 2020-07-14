# Headers
spi_inc = []

# Source Code
spi_sources = [
    'spi.cpp'
]

# Shared Library
spilib = shared_library ('spilib',
                         spi_sources,
                         include_directories : spi_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('spiat', 'spi_tb.cpp',
                     include_directories : spi_inc,
                     link_with : spilib,
                     dependencies : deps)
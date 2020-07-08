# Headers
mem_lt_inc = []

# Source Code
mem_lt_sources = [
    'memory.cpp'
]

# Shared Library
memltlib = shared_library ('memlib',
                         mem_lt_sources,
                         include_directories : mem_lt_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('memlt', 'memory_tb.cpp',
                     include_directories : mem_lt_inc,
                     link_with : memltlib,
                     dependencies : deps)

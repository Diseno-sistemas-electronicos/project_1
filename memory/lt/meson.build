# Headers
mem_inc = []

# Source Code
mem_sources = [
    'memory.cpp'
]

# Shared Library
memlib = shared_library ('memlib',
                         mem_sources,
                         include_directories : mem_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('memlt', 'memory_tb.cpp',
                     include_directories : mem_inc,
                     link_with : memlib,
                     dependencies : deps)

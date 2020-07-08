# Headers
mem_pv_inc = []

# Source Code
mem_pv_sources = [
    'memory.cpp'
]

# Shared Library
mempvlib = shared_library ('memlib',
                         mem_pv_sources,
                         include_directories : mem_pv_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('mempv', 'memory_tb.cpp',
                     include_directories : mem_pv_inc,
                     link_with : mempvlib,
                     dependencies : deps)

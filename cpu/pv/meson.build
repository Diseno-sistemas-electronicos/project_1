# Headers
processor_pv_inc = []

# Source Code
processor_pv_sources = [
    'processor.cpp'
]

# Shared Library
processor_pv_lib = shared_library ('processorpvlib',
                         processor_pv_sources,
                         include_directories : processor_pv_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('processorpv', 'processor_run.cpp',
                     include_directories : processor_pv_inc,
                     link_with : processor_pv_lib,
                     dependencies : deps)

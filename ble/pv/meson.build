# Headers
ble_pv_inc = []

# Source Code
ble_pv_sources = [
    'ble.cpp'
]

# Shared Library
ble_pv_lib = shared_library ('blepvlib',
                         ble_pv_sources,
                         include_directories : ble_pv_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('blepv', 'ble_tb.cpp',
                     include_directories : ble_pv_inc,
                     link_with : ble_pv_lib,
                     dependencies : deps)

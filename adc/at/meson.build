# Headers
adc_inc = []

# Source Code
adc_sources = [
    'adc.cpp'
]

# Shared Library
adclib = shared_library ('adclib',
                         adc_sources,
                         include_directories : adc_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('adcpv', 'adc_tb.cpp',
                     include_directories : adc_inc,
                     link_with : adclib,
                     dependencies : deps)
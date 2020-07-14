# Headers
adc_lt_inc = []

# Source Code
adc_lt_sources = [
    'adc.cpp'
]

# Shared Library
adcltlib = shared_library ('adclib',
                         adc_lt_sources,
                         include_directories : adc_lt_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('adclt', 'adc_tb.cpp',
                     include_directories : adc_lt_inc,
                     link_with : adcltlib,
                     dependencies : deps)

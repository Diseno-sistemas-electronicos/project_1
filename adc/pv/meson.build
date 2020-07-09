# Headers
adc_pv_inc = []

# Source Code
adc_pv_sources = [
    'adc.cpp'
]

# Shared Library
adcpvlib = shared_library ('adclib',
                         adc_pv_sources,
                         include_directories : adc_pv_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('adcpv', 'adc_tb.cpp',
                     include_directories : adc_pv_inc,
                     link_with : adcpvlib,
                     dependencies : deps)

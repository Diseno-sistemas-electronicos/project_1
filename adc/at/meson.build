# Headers
adc_at_inc = []

# Source Code
adc_at_sources = [
    'adc.cpp'
]

# Shared Library
adcatlib = shared_library ('adclib',
                         adc_at_sources,
                         include_directories : adc_at_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('adcat', 'adc_tb.cpp',
                     include_directories : adc_at_inc,
                     link_with : adcatlib,
                     dependencies : deps)

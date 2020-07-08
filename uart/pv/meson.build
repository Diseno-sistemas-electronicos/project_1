# Headers
uart_pv_inc = []

# Source Code
uart_pv_sources = [
    'uart.cpp'
]

# Shared Library
uart_pv_lib = shared_library ('uartpvlib',
                         uart_pv_sources,
                         include_directories : adc_inc,
                         dependencies : deps,
                         install : false)

testexe = executable('uartpv', 'uart_tb.cpp',
                     include_directories : uart_pv_inc,
                     link_with : uart_pv_lib,
                     dependencies : deps)
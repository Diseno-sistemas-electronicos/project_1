
project('tutorial', 'cpp')
cxx = meson.get_compiler('cpp')

# Dependencies
systemc_dep = dependency ('systemc')
math_dep = cxx.find_library('m', required : true)
deps = [systemc_dep, math_dep]

subdir('memory')
subdir('adc')
subdir('uart')
subdir('cpu')
subdir('spi')


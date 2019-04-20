project(
    'Prometheus',
    'cpp',
    version: '2.0.0',
    default_options : ['cpp_std=c++11']
)

inc = include_directories('include')

subdir('src')

sfml_system = dependency('sfml-system')
sfml_window = dependency('sfml-window')
sfml_graphics = dependency('sfml-graphics')

sfml_app = executable(
    'sfml-app',
    'Main.cpp',
    dependencies: [deps, sfml_system, sfml_window, sfml_graphics],
    include_directories: inc,
    install: true
)
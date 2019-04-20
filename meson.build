# project('Prometheus', 'cpp')

# inc = include_directories('.')
# # install_header(['Objet.h', 'Vecteur.h', 'Planete.h'])

# sfml_window = dependency('sfml-window')
# sfml_graphics = dependency('sfml-graphics')
# sfml_system = dependency('sfml-system')

# vecteurlib = shared_library('Vecteur', 'Vecteur.cpp', include_directories: inc)
# objetlib = shared_library('Objet', 'Objet.cpp', include_directories: inc)
# planetelib = shared_library('Planete', 'Planete.cpp', include_directories: inc)

# executable('sfml-app', 'Main.cpp', include_directories: inc,
#             dependencies: [sfml_window, sfml_graphics, sfml_system],
#             link_with: [vecteurlib, objetlib, planetelib])

project(
    'Prometheus',
    'cpp',
    version: '1.0.0'
)

inc = include_directories('include')

subdir('include')
subdir('src')

sfml_window = dependency('sfml-window')
sfml_graphics = dependency('sfml-graphics')
sfml_system = dependency('sfml-system')

sfml_app = executable(
    'sfml-app',
    'Main.cpp',
    dependencies: [deps, sfml_graphics, sfml_system, sfml_window],
    install: true
)
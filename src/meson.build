lib_vecteur = static_library('Vecteur', 'Vecteur.cpp', include_directories: inc, install: true)
lib_objet = static_library('Objet', 'Objet.cpp', include_directories: inc, install: true)
lib_planete = static_library('Planete', 'Planete.cpp', include_directories: inc, install: true)

deps = declare_dependency(link_with: [lib_vecteur, lib_objet, lib_planete], include_directories: inc)
lib_vecteur = static_library('Vecteur', 'Vecteur.cpp', include_directories: inc, install: true)
lib_objet = static_library('Objet', 'Objet.cpp', include_directories: inc, install: true)
lib_vaisseau = static_library('Vaisseau', 'Vaisseau.cpp', include_directories: inc, install: true)
lib_text = static_library('Text', 'Text.cpp', include_directories: inc, install: true)
lib_pagesetting = static_library('PageSetting', 'PageSetting.cpp', include_directories: inc, install: true)
lib_input = static_library('Input', 'Input.cpp', include_directories: inc, install: true)
lib_data = static_library('Data', 'Data.cpp', include_directories: inc, install: true)
lib_corpsstellaire = static_library('CorpsStellaire', 'CorpsStellaire.cpp', include_directories: inc, install: true)

deps = declare_dependency(
    link_with: [lib_vecteur, lib_objet, lib_vaisseau, lib_text, lib_pagesetting, lib_input, lib_data, lib_corpsstellaire],
    include_directories: inc
)
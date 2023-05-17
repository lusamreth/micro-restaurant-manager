project('final-project', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

add_global_arguments('-DSOME_TOKEN=value', language : 'cpp')
glib_dep = dependency('glib-2.0')

project_header_files = []
project_sources = []
incdir = include_directories('include')

subdir('include')
subdir('src')

final_project_static_lib = [
  domain_lib
]
executable('final-project',
           main_source ,
           include_directories : incdir,
           # linked with the domain static lib
           link_with : final_project_static_lib ,
           install : false)

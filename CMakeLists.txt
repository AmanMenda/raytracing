cmake_minimum_required(VERSION 3.8)

project(Raytracing CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Active le rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
		"$<IF:$<AND:$<C_COMPILER_ID:MSVC>,\
		$<CXX_COMPILER_ID:MSVC>>,\
		$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,\
		$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>"
  )
endif()


# Ajouter source à l'exécutable de ce projet.

add_executable(raytracing "src/raytracing.cpp")
add_compile_options(-Wall -Wextra -g3 -g)

# TODO: Ajoutez des tests et installez des cibles si nécessaire.

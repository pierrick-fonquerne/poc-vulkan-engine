cmake_minimum_required(VERSION 3.10)
project(VulkanEngine)

set(CMAKE_CXX_STANDARD 17)

# Ajouter les chemins d'inclusion et de bibliothèques pour GLFW et Vulkan
if (WIN32)
    # Spécifique à Windows
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:library")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
    set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_parties/glfw/include")
    set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/third_parties/glfw/lib/glfw3.lib")
    set(VULKAN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_parties/vulkan/include")
    set(VULKAN_LIBRARY "${CMAKE_SOURCE_DIR}/third_parties/vulkan/lib/vulkan-1.lib")
else()
    # Spécifique à Linux
    set(GLFW_INCLUDE_DIR "/usr/include/GLFW")
    set(GLFW_LIBRARY "glfw")
    set(VULKAN_INCLUDE_DIR "/usr/include/vulkan")
    set(VULKAN_LIBRARY "vulkan")
endif()

# Inclure les chemins Vulkan
include_directories(${VULKAN_INCLUDE_DIR})

# Ajouter les fichiers source
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Ajouter l'exécutable
add_executable(VulkanEngine ${SOURCES})

# Inclure les répertoires d'en-tête
target_include_directories(VulkanEngine PRIVATE includes ${GLFW_INCLUDE_DIR})

# Lier les bibliothèques (différentes selon l'OS)
target_link_libraries(VulkanEngine ${GLFW_LIBRARY} ${VULKAN_LIBRARY})

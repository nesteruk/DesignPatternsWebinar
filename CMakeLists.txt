cmake_minimum_required(VERSION 3.5)
project(DesignPatternsWebinar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# made with the 'incboost' macro
find_package(Boost)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIR})
endif ()

set(ADAPTER_FILES adapter/adapter.cpp)
add_executable(Adapter ${ADAPTER_FILES})

set(COMPOSITE_FILES composite/composite.cpp)
add_executable(Composite ${COMPOSITE_FILES})

set(SPECIFICATION_FILES specification/specification.cpp)
add_executable(Specifiction ${SPECIFICATION_FILES})

set(BUILDER_FILES builder/builder.cpp)
add_executable(Builder ${BUILDER_FILES})

set(GROOVY_BUILDER_FILES groovy-builder/groovy-builder.cpp)
add_executable(GroovyBuilder ${GROOVY_BUILDER_FILES})

add_subdirectory(facet-builders)

set(MAYBE_MONAD_FILES maybe-monad/maybe-monad.cpp)
add_executable(MaybeMonad ${MAYBE_MONAD_FILES})
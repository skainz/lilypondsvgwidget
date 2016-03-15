cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")

if(MSVC)
set(BUILD_STATIC ON BOOL CACHE BOOL "Set to true to build static Binary (/MT compiler flag)")

	if(BUILD_STATIC)
	message("Building static binary")
	foreach(flag_var 
		CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
		if (${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif(${flag_var} MATCHES "/MD")
	endforeach(flag_var)
	endif()
endif()

find_package(Qt5 REQUIRED Core Multimedia Svg Widgets Xml)
add_definitions(-std=c++11)
#qt5_add_resources(RESOURCES app.qrc)
add_executable(test-app
  test_neu.cpp
  ${RESOURCES}
)



target_link_libraries(test-app Qt5::Widgets Qt5::Multimedia Qt5::Svg Qt5::Xml)

# build a CPack driven installer package
include(InstallRequiredSystemLibraries)
#set(CPACK_RESOURCE_FILE_LICENSE "${bmc_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 1)
set(CPACK_PACKAGE_VERSION_PATCH 0)
set(CPACK_PACKAGE_CONTACT       "Mario Lang <mlang@delysid.org>")
set(CPACK_STRIP_FILES           TRUE)
#set(CPACK_SOURCE_GENERATOR      "TGZ;TXZ;")
include(CPack)

include(InstallRequiredSystemLibraries)

install(TARGETS test-app 
    DESTINATION bin
   )

#foreach(plugin ${Qt5Multimedia_PLUGINS})
#  get_target_property(_loc ${plugin} LOCATION)
#  message("Plugin ${plugin} is at location ${_loc}")
#endforeach()

#file(GLOB MY_QT5_PLATFORM_FILES ${Qt5_DIR}/../../../plugins/platforms/qwindows*.dll)
#message(${MY_QT5_PLATFORM_FILES})
#install (FILES ${MY_QT5_PLATFORM_FILES} DESTINATION bin/platforms)

#file(GLOB MY_QT5_EXTRADLL_FILES ${Qt5_DIR}/../../../../../Tools/QtCreator/bin/Qt5*.dll)
#message(${MY_QT5_EXTRADLL_FILES})
#install (FILES ${MY_QT5_EXTRADLL_FILES} DESTINATION bin)

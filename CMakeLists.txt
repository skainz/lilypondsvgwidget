cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

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

#list(APPEND CMAKE_PREFIX_PATH /usr/local/Cellar/qt5/5.5.1_2)
#find_package(Qt5 COMPONENTS Core Multimedia Svg Widgets Xml)
find_package(Qt5 REQUIRED Core Multimedia Svg Widgets Xml)
if(Qt5_FOUND)
  configure_file(config.h.in config.h)
  add_executable(bmc-ui 
    app.cpp
    mainwindow.cpp mainwindow.h
    lilypondsvgwidget.cpp lilypondsvgwidget.h
    lilypondsvgcontainer.h
    optionsdialog.cpp optionsdialog.h
    ${RESOURCES}
  )
  
#  target_compile_features(bmc-ui PRIVATE cxx_range_for)
  target_link_libraries(bmc-ui
    Qt5::Widgets Qt5::Multimedia Qt5::Svg Qt5::Xml
  )
  
  # install(TARGETS bmc-ui
    # BUNDLE DESTINATION . COMPONENT Runtime
    # RUNTIME DESTINATION bin COMPONENT Runtime
  # )
  # set(APPS "\${CMAKE_INSTALL_PREFIX}/bin/bmc-ui")
  # if(APPLE)
    # set(APPS "\${CMAKE_INSTALL_PREFIX}/bmc-ui.app")
  # elseif(MSVC)
    # set(APPS "\${CMAKE_INSTALL_PREFIX}/bin/bmc-ui.exe")
  # endif()
  # set(DIRS ${QT_LIBRARY_DIRS})
  # install(CODE "
    # include(BundleUtilities)
    # set(BU_CHMOD_BUNDLE_ITEMS ON)
    # fixup_bundle(\"${APPS}\" \"\" \"${DIRS}\")"
    # COMPONENT Runtime
  # )
 endif()


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

install(TARGETS bmc-ui 
    DESTINATION bin
   )

#foreach(plugin ${Qt5Multimedia_PLUGINS})
#  get_target_property(_loc ${plugin} LOCATION)
#  message("Plugin ${plugin} is at location ${_loc}")
#endforeach()

file(GLOB MY_QT5_PLATFORM_FILES ${Qt5_DIR}/../../../plugins/platforms/qwindows*.dll)
message(${MY_QT5_PLATFORM_FILES})
install (FILES ${MY_QT5_PLATFORM_FILES} DESTINATION bin/platforms)

file(GLOB MY_QT5_EXTRADLL_FILES ${Qt5_DIR}/../../../../../Tools/QtCreator/bin/Qt5*.dll)
message(${MY_QT5_EXTRADLL_FILES})
install (FILES ${MY_QT5_EXTRADLL_FILES} DESTINATION bin)


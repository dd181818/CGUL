# Find Apple's Carbon and Cocoa libraries
if(APPLE)
    INCLUDE_DIRECTORIES(/Developer/Headers/FlatCarbon)
    FIND_LIBRARY(CARBON_LIBRARY Carbon)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(APP_SERVICES_LIBRARY ApplicationServices)
    MARK_AS_ADVANCED(CARBON_LIBRARY COCOA_LIBRARY APP_SERVICES_LIBRARY)
    SET(JATTA_LIBRARIES ${JATTA_LIBRARIES} ${CARBON_LIBRARY} ${COCOA_LIBRARY} ${APP_SERVICES_LIBRARY})
ENDIF()
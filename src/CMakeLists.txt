# Include the headers
INCLUDE_DIRECTORIES(${Pronostic_SOURCE_DIR}/include)

# Create the moc files
qt5_wrap_cpp(Pronostic_SRC ../include/mainwindow.h)

# Create the executable
ADD_EXECUTABLE(Pronostic mainwindow.cpp main.cpp ${Pronostic_SRC})

# Link the executable to the libraries
TARGET_LINK_LIBRARIES(Pronostic ${Qt5Widgets_LIBRARIES})
#t5_use_modules(Pronostic Widgets)
# Include the headers
INCLUDE_DIRECTORIES(${Pronostic_SOURCE_DIR}/include)

# Create the moc files
qt5_wrap_cpp(Pronostic_SRC ../include/mainwindow.h
                           ../include/dbmanager.h
                           ../include/league.h
                           ../include/match.h
                           ../include/team.h
                           ../include/singleton.h
                           ../include/widgets/addleaguewidget.h
                           ../include/widgets/addmatchwidget.h
                           ../include/widgets/addteamwidget.h
                           ../include/widgets/editleaguewidget.h
                           ../include/widgets/editmatchwidget.h
                           ../include/widgets/editteamwidget.h)

# Create the executable
ADD_EXECUTABLE(Pronostic widgets/editteamwidget.cpp
                         widgets/editmatchwidget.cpp
                         widgets/editleaguewidget.cpp
                         widgets/addteamwidget.cpp
                         widgets/addmatchwidget.cpp
                         widgets/addleaguewidget.cpp
                         team.cpp
                         match.cpp
                         league.cpp
                         dbmanager.cpp
                         mainwindow.cpp
                         main.cpp

                         ${Pronostic_SRC})

# Link the executable to the libraries
TARGET_LINK_LIBRARIES(Pronostic ${Qt5Widgets_LIBRARIES} ${Qt5Sql_LIBRARIES})
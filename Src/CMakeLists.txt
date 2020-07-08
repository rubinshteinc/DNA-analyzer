cmake_minimum_required(VERSION 3.15)
project(DNA___analyzer)

set(CMAKE_CXX_STANDARD 98)

add_executable(Src
        main.cpp
        app.h app.cpp
        terminal.h terminal.cpp
        parsing.h parsing.cpp
        Command/factory_command.h Command/factoryCommand.cpp
        Command/Icommand.h
        Command/New/new_command.h Command/New/new_command.cpp
        Command/Load/load_command.h Command/Load/load_command.cpp
        Command/Load/load_parser.h Command/Load/load_parser.cpp
        Command/New/new_parser.h Command/New/new_parser.cpp
        Data/dna.h
        Data/dna_sequence.cpp
        Data/meta_data.h Data/meta_data.cpp
        I_O/output_data.cpp
        I_O/output_data.h
        I_O/input_data.cpp
        I_O/input_data.h
        )
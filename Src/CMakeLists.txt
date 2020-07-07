cmake_minimum_required(VERSION 3.15)
project(DNA___analyzer)

set(CMAKE_CXX_STANDARD 98)

add_executable(DNA___analyzer main.cpp
        app.h app.cpp
        terminal.h terminal.cpp
        meta_data.h meta_data.cpp
        parsing.h parsing.cpp
        factory_command.h factoryCommand.cpp
        Icommand.h
        new_command.h new_command.cpp
        dna.h
        input_data.cpp
        input_data.h
        output_data.cpp
        output_data.h
        dna_sequence.cpp
        )
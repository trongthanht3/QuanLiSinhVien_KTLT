PROJECT(QuanLiSinhVien)

set(CMAKE_CXX_STANDARD 14)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(QuanLiSinhVien main.cpp Header/Date.cpp Header/Menu.cpp Header/SinhVien.cpp Header/ConstString.cpp Header/InDanhSach.cpp Header/SapXep.cpp Header/SapXep.h Header/TimKiem.cpp Header/TimKiem.h)
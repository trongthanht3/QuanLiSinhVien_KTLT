PROJECT(QuanLiSinhVien)

set(CMAKE_CXX_STANDARD 14)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(QuanLiSinhVien main.cpp Header/Date.cpp Header/Menu.cpp Header/SinhVien.cpp Header/ConstString.cpp Header/InDanhSach.cpp)
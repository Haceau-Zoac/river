add_rules("mode.debug", "mode.release")

target("river")
    set_languages("cxx17")
    set_warnings("all")
    set_kind("static")
    set_arch("x64")
    add_files("src/*.cpp")

target("river_demo")
    set_languages("cxx17")
    set_warnings("all")
    set_kind("binary")
    set_arch("x64")
    add_deps("river")
    add_includedirs("src")
    add_files("src/demo/main.cpp")
    add_links("user32")
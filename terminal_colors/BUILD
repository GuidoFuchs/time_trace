cc_library(
    name = "rgb_colors",
    hdrs = glob(["rgb_colors.h"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "terminal_colors",
    hdrs = glob(["terminal_colors.h"]),
    deps = [
        ":rgb_colors",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "terminal_colors_example",
    hdrs = glob(["terminal_colors_example.h"]),
    deps = [
        ":terminal_colors",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "terminal_colors_demo",
    srcs = ["terminal_colors_demo.cpp"],
    deps = [
        ":rgb_colors",
        ":terminal_colors_example",
        "//braille_dots:braille_dots",
    ],
)

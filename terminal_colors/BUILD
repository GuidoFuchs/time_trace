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

cc_binary(
    name = "terminal_colors_example",
    srcs = ["terminal_colors_example.cpp"],
    deps = [
        ":rgb_colors",
        ":terminal_colors",
        "//braille_dots:braille_dots",
    ],
)

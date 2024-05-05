

cc_library(
    name = "braille_dots",
    hdrs = glob(["braille_dots.h"]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "braille_dots_example",
    srcs = ["braille_example.cpp"],
    deps = [
        ":braille_dots",
    ],
)

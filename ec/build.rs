#[cfg(feature = "hardware")]
fn main() {
    pkg_config::Config::new();
    let src = ["c/point_add.c"];
    let mut builder = cc::Build::new();
    let build = builder
        .files(src.iter())
        .include("c")
        .flag("-Wno-unused-parameter")
        .flag("-Wall")
        .flag("-c")
        .flag("-g")
        .flag("-std=c99")
        .flag("-o3")
        .flag("-l")
        .flag("-lpthread")
        .flag("-D_GNU_SOURCE")
        .flag("-l")
        .define("USE_ZLIB", None);

    build.compile("point_add_c");
}

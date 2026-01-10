{
  description = "C++ dev shell (CMake + clangd )";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux.default =
      let
        pkgs = import nixpkgs { system = "x86_64-linux"; };
      in
      pkgs.mkShell {
        packages = with pkgs; [
          clang
          clang-tools
          gcc
          cmake
          ninja
        ];

        # Declarative defaults
        CMAKE_BUILD_DIR = "build";
        CMAKE_BUILD_TYPE = "Debug";
        CMAKE_GENERATOR = "Ninja";

        shellHook = ''
          			echo "C++ dev shell ready"
          			echo "clang: $(clang++ --version | head -n1)"
          			echo "gcc:   $(gcc --version | head -n1)"
          			echo "Build dir: $CMAKE_BUILD_DIR ($CMAKE_BUILD_TYPE)"
          			export Nix_SHELL=Cmake

          			cmake-configure() {
          				cmake \
          					-S . \
          					-B "$CMAKE_BUILD_DIR" \
          					-G "$CMAKE_GENERATOR" \
          					-DCMAKE_BUILD_TYPE="$CMAKE_BUILD_TYPE" \
          					-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
          			}

          		cmake-build() {
          			cmake --build "$CMAKE_BUILD_DIR"
          		}

          		cmake-run() {
          			"./$CMAKE_BUILD_DIR/main"
          		}

          		export -f cmake-configure
          			export -f cmake-build
          			export -f cmake-run
          			'';
      };
  };
}
